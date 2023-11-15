#include <iostream>
#include <Eigen/Dense>


using namespace Eigen;



int main()
{
  MatrixXi M(4,4);
  M << 1, 2, 3, 4,
       5, 6, 7, 8, 
       9, 10, 11, 12,
       13, 14, 15, 16;
  
  MatrixXi P = MatrixXi::Identity(4,4);	
  P.row(2).swap(P.row(1));
  
  std::cout << "M :\n" << M << std::endl << std::endl;
  std::cout << "P :\n" << P << std::endl << std::endl;
  
  std::cout << "permutation : \n " << M*P << std::endl << std::endl;	
  std::cout << "permutation : \n " << P*M << std::endl << std::endl;	
	
  return 0;
}



// g++ -Wall -I ~/eigen/  permutation.cpp 
