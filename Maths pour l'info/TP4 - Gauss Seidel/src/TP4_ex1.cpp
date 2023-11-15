#include <iostream>
#include <cstdlib>
#include <Eigen/Dense>
#include <chrono>
#include <cassert>
#include <iomanip>      // std::setprecision

Eigen::MatrixXd DiagDomStricte (const unsigned int n)
{
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(n, n);
  A.diagonal() = Eigen::VectorXd::Ones(n) * n; // Ici pour modifier : n ou n - 1
  return A;
}

Eigen::MatrixXd VectorRand (const unsigned int n)
{
 return Eigen::VectorXd::Random(n);
}

Eigen::VectorXd GaussSeidel (const Eigen::MatrixXd &A, const Eigen::VectorXd &B, const unsigned int p)
{
  const unsigned int n = A.cols();
  Eigen::VectorXd LaSolution = B;

  for (unsigned int k = 0; k < p; k++)
  {
    for (unsigned int i = 0; i < n; i++)
    {
      double sum = 0.0;
      for (unsigned int j = 0; j < n; j++)
      {
        sum += LaSolution(j)*A(i,j);
      }
      LaSolution(i) = (B(i) - sum)/A(i,i);
    }
  }
  return LaSolution;
}


int main()
{
  unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
  srand(seed);

  const unsigned int matrixSize = 100;

  // 1 random matrice
  Eigen::MatrixXd A = DiagDomStricte(matrixSize);

  // 1 random vector
  Eigen::VectorXd B = VectorRand(matrixSize); 

  // Calcul
  Eigen::VectorXd X = GaussSeidel(A, B, 1000); 

  std::cout << "La super solution est : " << std::endl;
  for (unsigned int i = 0; i < matrixSize; i++)
  {
    std::cout << X[i] << std::endl;
  }

  std::cout << A*X - B << std::endl;

// #if 1 // eigen multithread, put 0 if openMP is not supported, 1 otherwize
//   const int nbProc = 8; // choose accordingly to the number of cores on your machine 
//   Eigen::setNbThreads(nbProc);
//   auto start_multi = std::chrono::steady_clock::now();
//   for(unsigned int i=0; i<nbRuns; ++i){
//     C = A*B;
//   }
//   auto stop_multi = std::chrono::steady_clock::now();
//   std::chrono::duration<double> elapsed_multi = stop_multi -start_multi;
//   std::cout << "eigen Multi : " << elapsed_multi.count() << " s" << std::endl;
//   Eigen::setNbThreads(1);
// #endif

  // // eigen  
  // auto start = std::chrono::steady_clock::now();
  // for(unsigned int i=0; i<nbRuns; ++i){
  //   C = A*B;
  // }
  // auto stop = std::chrono::steady_clock::now();
  // std::chrono::duration<double> elapsed_seconds = stop-start;
  // std::cout << "eigen       : " << elapsed_seconds.count() << " s" << std::endl;
  
  return 0;
}