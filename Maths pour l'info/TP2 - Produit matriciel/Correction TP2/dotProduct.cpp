#include <iostream>
#include <iomanip>      // std::setprecision
#include <cstdlib>
#include <Eigen/Dense>
#include <ctime>
#include <cassert>

using namespace Eigen;

const unsigned int vectorSize = 10;


double dotProduct(const VectorXd &a, const VectorXd &b){

  assert(a.size() == b.size() && "dotProudct: error: the 2 vectors should have the same size");

  double result = 0.0;
  for(unsigned int i=0; i<a.size(); ++i)
    result += a(i)*b(i);	
	
  return result;	
}


int main()
{
  srand(time(0));

  VectorXd x1 = VectorXd::Random(vectorSize);	
  VectorXd x2 = VectorXd::Random(vectorSize);
  
  std::cout << "x1 : " << x1.transpose() << std::endl;
  std::cout << "x2 : " << x2.transpose() << std::endl;
  
  std::cout << std::setprecision(100) << "my dot product : " << dotProduct(x1,x2) << std::endl;
  std::cout << std::setprecision(100) << "eigen dot      : " << x1.dot(x2) << std::endl;	
	
  return 0;
}



// g++ -Wall -I ~/eigen/  dotProduct.cpp 
