#include <iostream>
#include <Eigen/Dense>
#include <limits>

using namespace Eigen;

// mac   : g++ -Wall -O2 -I /usr/local/include/eigen3 verif.cpp -o verif
// linux : g++ -Wall -O2 -I /usr/include/eigen3 verif.cpp -o verif


bool checkMatrixProduct(const MatrixXd &A, const MatrixXd &B, const MatrixXd &C)
{
  const double epsilon = 1.0e6 * std::numeric_limits<double>::epsilon();

  VectorXd b = B.rowwise().sum();
  VectorXd c = C.rowwise().sum();

  if( (A*b-c).norm() < epsilon ) return true;
  else return false;
}


int main(){

  srand(time(0));
  const unsigned int matrixSize = 1000;
  
  // 2 random matrices
  MatrixXd A = MatrixXd::Random(matrixSize,matrixSize); 
  MatrixXd B = MatrixXd::Random(matrixSize,matrixSize); 
  std::cout << "product success : " << (checkMatrixProduct(A,B,A*B) ? "yes" : "no") << std::endl;

  MatrixXd noise = 0.00000001 * MatrixXd::Random(matrixSize,matrixSize); 
  std::cout << "product success : " << (checkMatrixProduct(A,B,A*B + noise) ? "yes" : "no") << std::endl;

  return 0;
}

