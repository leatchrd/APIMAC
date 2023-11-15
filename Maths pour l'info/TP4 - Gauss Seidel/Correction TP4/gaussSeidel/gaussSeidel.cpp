#include <iostream>
#include <Eigen/Dense>
#include <cassert>
#include <iomanip>
#include <chrono>

#include <cstdlib>  // srand
#include <ctime>    // srand(time(0))


// mac   : g++ -Wall -O2 -I /usr/local/include/eigen3 -std=c++11  gaussSeidel.cpp 
// linux : g++ -Wall -O2 -I /usr/include/eigen3 -std=c++11  gaussSeidel.cpp 


// mac (eigen warnings) : g++ -Wall -O2 -I /usr/local/include/eigen3 -std=c++11 -Wno-unknown-warning-option  gaussSeidel.cpp


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

  // check if the matrix is full rank
  if(getRank(A) != matrixSize){
    std::cerr << "error: matrix generation: matrix is not full rank" << std::endl;
    return 1;
  }

  // build vector b
  Eigen::VectorXd b = Eigen::VectorXd::Random(matrixSize);

  // gauss siedel
  const uint nbIterations = 20;
  Eigen::VectorXd x_gs = gaussSeidel(A,b,nbIterations);
  std::cout << "GS error : " << std::setprecision(3) << (b-A*x_gs).norm() << std::endl;

  return 0;
}




