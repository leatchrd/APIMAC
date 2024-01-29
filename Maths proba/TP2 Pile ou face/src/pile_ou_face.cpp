#include <iostream>
#include <random>

double rand01() {
  thread_local std::default_random_engine gen{std::random_device{}()};
  thread_local auto distrib = std::uniform_real_distribution<double>{0.0, 1.0};

  return distrib(gen);
}

bool pileOuFace(double nbRandom, const double proba) {
  if (nbRandom > 1 - proba)
    return false;

  else
    return true;
}

void lance(const double proba, const uint nbLance) {
  std::cout << "Nombre de lances " << nbLance << std::endl;
  for (uint i = 0; i < nbLance; i++) {
    double nb = rand01();
    std::cout << pileOuFace(nb, proba) << " - ";
  }
}

int main() {
  lance(0.3, 150);

  std::cout << std::endl;
  return 0;
}
