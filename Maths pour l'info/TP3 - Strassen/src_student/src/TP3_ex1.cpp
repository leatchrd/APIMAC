#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <Eigen/Dense>
#include <ctime>
#include <cassert>

using namespace Eigen;


double dotProduct(const VectorXd &a, const VectorXd &b){

  assert(a.size() == b.size() && "dotProudct: error: les deux vecteurs doivent etre de meme taille");

  double result = 0.0;
  for(unsigned int i=0; i<a.size(); ++i)
    result += a(i)*b(i);	
	
  return result;	
}

MatrixXd matrixProduct(const MatrixXd &A, const MatrixXd B)
{
  assert(A.cols() == B.rows());
	
  MatrixXd C = MatrixXd::Zero(A.rows(),B.cols());
  
  for(unsigned int i=0; i<C.rows(); ++i)
    for(unsigned int j=0; j<C.cols(); ++j)
      C(i,j) = dotProduct(A.row(i),B.col(j));

  return C;
}

MatrixXd strassenProduct(const MatrixXd &A, const MatrixXd B)
{
    assert(A.cols() == A.rows() && "strassenProduc: error: la matrice A doit etre carree");
    assert(B.cols() == B.rows() && "strassenProduc: error: la matrice B doit etre carree");
    assert(A.cols() == B.rows());

  if (A.cols()/2 < 100)
  {
    return matrixProduct(A, B);
  }

  MatrixXd a = A.topLeftCorner(A.cols()/2, A.cols()/2);
  MatrixXd b = A.topRightCorner(A.cols()/2, A.cols()/2);
  MatrixXd c = A.bottomLeftCorner(A.cols()/2, A.cols()/2);
  MatrixXd d = A.bottomRightCorner(A.cols()/2, A.cols()/2);
  
  MatrixXd e = B.topLeftCorner(B.cols()/2, B.cols()/2);
  MatrixXd f = B.topRightCorner(B.cols()/2, B.cols()/2);
  MatrixXd g = B.bottomLeftCorner(B.cols()/2, B.cols()/2);
  MatrixXd h = B.bottomRightCorner(B.cols()/2, B.cols()/2);
  
  P1 = strassenProduct(a, f-h);
  P2 = strassenProduct(a+b, h);
  P3 = strassenProduct(c+d, e);
  P4 = strassenProduct(d, g-e);
  P5 = strassenProduct(a+d, e+h);
  P6 = strassenProduct(b-d, g+h);
  P7 = strassenProduct(a-c, e+f);
}

int main()
{
  srand(time(0));

  MatrixXd A = MatrixXd::Random(5,5);	
  MatrixXd B = MatrixXd::Random(5,5);	
  
  std::cout << "A :\n" << A << std::endl;
  std::cout << "B :\n" << B << std::endl;
  
  std::cout << "mine  : \n" << matrixProduct(A,B) << std::endl;
  std::cout << "eigen : \n " << A*B << std::endl;	
	
  return 0;
}

// g++ -Wall -I ~/eigen/  TP3_ex1.cpp 