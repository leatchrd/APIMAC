#include <iostream>
#include <Eigen/Dense>
#include <cassert>
#include <iomanip>
#include <chrono>

#include <cstdlib>  // srand
#include <ctime>    // srand(time(0))


// mac   : g++ -Wall -O2 -I /usr/local/include/eigen3 -std=c++11 comparatif.cpp 
// linux : g++ -Wall -O2 -I /usr/include/eigen3 -std=c++11 comparatif.cpp 


// mac (eigen warnings) : g++ -Wall -O2 -I /usr/local/include/eigen3 -std=c++11 -Wno-unknown-warning-option comparatif.cpp


///////////////////////////////////////////////////////////////////////////////////////
Eigen::VectorXd gaussSeidel(const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const uint nbIter)
{
  // initial solution 
  Eigen::VectorXd x(b);

  // iterations
  for(uint iter=0; iter<nbIter; ++iter)
  	for(int i=0; i<A.rows(); ++i){
  		double sum = 0.0;
  		for(int j=0; j<i; ++j)          sum += A(i,j)*x(j);
  		for(int j=i+1; j<A.cols(); ++j)	sum += A(i,j)*x(j);
  		x(i) = (b(i)-sum)/A(i,i);
  	}

  return x;
}

///////////////////////////////////////////////////////////////////////////////////////
Eigen::VectorXd gaussSeidelSIMD(const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const uint nbIter)
{
  // initial solution 
  Eigen::VectorXd x(b);

  // iterations
  for(uint iter=0; iter<nbIter; ++iter)
    for(int i=0; i<A.rows(); ++i){
      double sum = A.row(i)*x - A(i,i)*x(i);  // use SIMD instruction in Eigen dot product
      x(i) = (b(i)-sum)/A(i,i);
    }

  return x;
}

///////////////////////////////////////////////////////////////////////////////////////
Eigen::MatrixXd inverseUpperTriangular(const Eigen::MatrixXd &A)
{
  Eigen::MatrixXd M(A.rows(),A.cols());
  Eigen::MatrixXd Id = Eigen::MatrixXd::Identity(A.rows(),A.cols());

  for(unsigned int j=0; j<M.cols(); ++j)
    M.col(j) = A.triangularView<Eigen::Upper>().solve(Id.col(j));

  return M;
}


///////////////////////////////////////////////////////////////////////////////////////
Eigen::VectorXd gaussSeidelMatrix(const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const uint nbIter)
{
  // (D + E)^-1
  Eigen::MatrixXd DE = (A.triangularView<Eigen::Upper>());
  DE = inverseUpperTriangular(DE);  // faster than a regular inverse

  // F = A striclty lower triangular
  Eigen::MatrixXd F  = A.triangularView<Eigen::StrictlyLower>();

  // F = (DE)^-1 * F
  F = -DE * F;

  // DE = (DE)^-1 * b
  DE = DE * b;

  // initial solution 
  Eigen::VectorXd x(b);

  // iterations
  for(uint iter=0; iter<nbIter; ++iter)
    // x = (DE)^-1*F*x + (DE)^-1*b
    x = F*x + DE;

  return x;
}


///////////////////////////////////////////////////////////////////////////////////////
/// warning : I don't recommend to use a recursive form of an algo when the iterative one is perfectly fine.
Eigen::VectorXd gaussSeidelRecursive(const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const uint nbIter)
{
	// stop condition
  if(nbIter ==0) return b;

	// ask for the solution at the previous iteration
  Eigen::VectorXd x = gaussSeidelRecursive(A,b,nbIter-1);

	// update this solution and return it
  for(int i=0; i<A.rows(); ++i){
    double sum = 0.0;
    for(int j=0; j<i; ++j)
      sum += A(i,j)*x(j);
    for(int j=i+1; j<A.cols(); ++j)
      sum += A(i,j)*x(j);
    x(i) = (b(i)-sum)/A(i,i);
	}

  return x;
}

///////////////////////////////////////////////////////////////////////////////////////
Eigen::VectorXd LuOptimized(const Eigen::MatrixXd &A, const Eigen::VectorXd &b){

  // first estimate with LU
  Eigen::PartialPivLU<Eigen::MatrixXd> lu(A);
  Eigen::VectorXd x_lu = lu.solve(b);

  // update the solution
  return x_lu + lu.solve(b-A*x_lu);
}


///////////////////////////////////////////////////////////////////////////////////////
Eigen::MatrixXd buildDiagonalStrictMatrix(const size_t n, double alpha){
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(n,n);
  A.diagonal() = alpha * Eigen::VectorXd::Ones(n);
  return A;
}


///////////////////////////////////////////////////////////////////////////////////////
unsigned int getRank(const Eigen::MatrixXd &A){
   Eigen::FullPivLU<Eigen::MatrixXd> lu_decomp(A);
   return lu_decomp.rank();
}


///////////////////////////////////////////////////////////////////////////////////////
int main()
{
  srand(time(0));

  constexpr unsigned int matrixSize = 100;
  
  // build a matrix
  Eigen::MatrixXd A = buildDiagonalStrictMatrix(matrixSize, matrixSize);
  //Eigen::MatrixXd A = Eigen::MatrixXd::Random(matrixSize,matrixSize);

  // check if the matrix is full rank
  if(getRank(A) != matrixSize){
    std::cerr << "error: matrix generation: matrix is not full rank" << std::endl;
    return 1;
  }

  // build vector b
  Eigen::VectorXd b = Eigen::VectorXd::Random(matrixSize);

  // display options
  constexpr unsigned int timeNbDigits = 6;

  // gauss siedel
  const uint nbIterations = 20;
  auto start = std::chrono::high_resolution_clock::now();
  Eigen::VectorXd x_gs = gaussSeidel(A,b,nbIterations);
  auto elapsed = std::chrono::high_resolution_clock::now() - start;
  std::cout << "GS  : " << std::setw(timeNbDigits) << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " micro-sec | error : " << std::setprecision(3) << (b-A*x_gs).norm() << std::endl;

  // GS matriciel
  start = std::chrono::high_resolution_clock::now();
  Eigen::VectorXd x_gsm = gaussSeidelMatrix(A,b,nbIterations);
  elapsed = std::chrono::high_resolution_clock::now() - start;
  std::cout << "GSM : " << std::setw(timeNbDigits) << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " micro-sec | error : " << std::setprecision(3) << (b-A*x_gsm).norm() << std::endl;

  // recursive GS
  start = std::chrono::high_resolution_clock::now();
  Eigen::VectorXd x_rgs = gaussSeidelRecursive(A,b,nbIterations);
  elapsed = std::chrono::high_resolution_clock::now() - start;
  std::cout << "GSR : " << std::setw(timeNbDigits) << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " micro-sec | error : " << std::setprecision(3) << (b-A*x_rgs).norm() << std::endl;

  // GS SIMD
  start = std::chrono::high_resolution_clock::now();
  Eigen::VectorXd x_gs_simd = gaussSeidelSIMD(A,b,nbIterations);
  elapsed = std::chrono::high_resolution_clock::now() - start;
  std::cout << "GS S: " << std::setw(timeNbDigits) << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " micro-sec | error : " << std::setprecision(3) << (b-A*x_gs_simd).norm() << std::endl;

  // LU
  start = std::chrono::high_resolution_clock::now();
  Eigen::PartialPivLU<Eigen::MatrixXd> lu(A);
  Eigen::VectorXd x_lu = lu.solve(b);
  elapsed = std::chrono::high_resolution_clock::now() - start;
  std::cout << "LU  : " << std::setw(timeNbDigits) << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " micro-sec | error : " << std::setprecision(3) << (b-A*x_lu).norm() << std::endl;

  // QR
  start = std::chrono::high_resolution_clock::now();
  Eigen::ColPivHouseholderQR<Eigen::MatrixXd> qr(A);
  Eigen::VectorXd x_qr = qr.solve(b);
  elapsed = std::chrono::high_resolution_clock::now() - start;
  std::cout << "QR  : " << std::setw(timeNbDigits) << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " micro-sec | error : " << std::setprecision(3) << (b-A*x_qr).norm() << std::endl;

  // SVD
  start = std::chrono::high_resolution_clock::now();
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeThinV);
  Eigen::VectorXd x_svd = svd.solve(b);
  elapsed = std::chrono::high_resolution_clock::now() - start;
  std::cout << "SVD : " << std::setw(timeNbDigits) << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " micro-sec | error : " << std::setprecision(3) << (b-A*x_svd).norm() << std::endl;
   
  // LU optimizedd
  start = std::chrono::high_resolution_clock::now();
  Eigen::VectorXd x_lu2 = LuOptimized(A,b);
  elapsed = std::chrono::high_resolution_clock::now() - start;
  std::cout << "LU2 : " << std::setw(timeNbDigits) << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " micro-sec | error : " << std::setprecision(3) << (b-A*x_lu2).norm() << std::endl;



  return 0;
}




