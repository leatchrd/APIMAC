#include <iostream>
#include <iomanip>      // std::setprecision
#include <Eigen/Dense>
#include <chrono>

double dot_product(const Eigen::VectorXd &v1, const Eigen::VectorXd &v2)
{
  //if (v1.size() == v2.size())
  {
    double produit = 0;
    
    for (int i = 0; i < v1.size(); i++)
    {
      produit += v1(i) * v2(i);
    }
    
    return produit;
  }
  // else
  // {
  //   std::cout << "Indiquer des vecteurs de même taille" << std::endl;
  //   exit(1);
  // }
  // return 0;
}

int main()
{
  // Aléatoire
  unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
  srand(seed);

  // Chrono
  const unsigned int iter = 10000;
  Eigen::MatrixXd C(3,4);


  // Vecteurs
  int vectorSize = 1500000;
  Eigen ::VectorXd v1 = Eigen::VectorXd::Random(vectorSize);
  Eigen ::VectorXd v2 = Eigen::VectorXd::Random(vectorSize);


  double value = 0;

  auto start = std::chrono::steady_clock::now();
  for(unsigned int i=0; i<iter; ++i)
    value += v1.dot(v2);
  auto stop = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_seconds = stop-start;
  std::cout << "temps calcul du produit vectoriel : " << elapsed_seconds.count() << " s" << std::endl;
  
  start = std::chrono::steady_clock::now();
  for(unsigned int i=0; i<iter; ++i)
    value += dot_product(v1, v2);
  stop = std::chrono::steady_clock::now();
  elapsed_seconds = stop-start;
  std::cout << "temps calcul de mon produit vectoriel : " << elapsed_seconds.count() << " s" << std::endl;
  
  std::cout << value << std::endl;

  
  // Eigen::VectorXd v1(5);
  // Eigen::VectorXd v2(5);
  // v1 << 1, 2, 3, 4, 5;
  // v2 << 1, 1, 1, 1, 1;

  //std::cout << "v1 : " << v1.transpose() << std::endl;
  //std::cout << "v2 : " << v1.transpose() << std::endl << std::endl;

  // Produit vectoriel
  //std::cout << "Produit scalaire de v1 et v2 : " << dot_product(v1, v2) << std::endl << std::endl;

  //std::cout << "Dot product : " << v1.dot(v2) << std::endl;
  
  
  
  return 0;
}