#include <iostream>
#include <math.h>
#include <random>

double rand01() {
  thread_local std::default_random_engine gen{std::random_device{}()};
  thread_local auto distrib = std::uniform_real_distribution<double>{0.0, 1.0};

  return distrib(gen);
}

int de() {
  double nbRandom = rand01() * 6 + 1;
  return floor(nbRandom);
}

void lance(const uint nbLance) {
  std::cout << "Nombre de lances " << nbLance << std::endl;

  uint valeur1 = 0;
  uint valeur2 = 0;
  uint valeur3 = 0;
  uint valeur4 = 0;
  uint valeur5 = 0;
  uint valeur6 = 0;

  for (uint i = 0; i < nbLance; i++) {
    std::cout << de() << " - ";

    if (de() == 1)
      valeur1++;

    if (de() == 2)
      valeur2++;

    if (de() == 3)
      valeur3++;

    if (de() == 4)
      valeur4++;

    if (de() == 5)
      valeur5++;

    if (de() == 6)
      valeur6++;
  }
  
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Apparition de 1 : " << valeur1 * 100 / nbLance << " %"
            << std::endl;
  std::cout << "Apparition de 2 : " << valeur2 * 100 / nbLance << " %"
            << std::endl;
  std::cout << "Apparition de 3 : " << valeur3 * 100 / nbLance << " %"
            << std::endl;
  std::cout << "Apparition de 4 : " << valeur4 * 100 / nbLance << " %"
            << std::endl;
  std::cout << "Apparition de 5 : " << valeur5 * 100 / nbLance << " %"
            << std::endl;
  std::cout << "Apparition de 6 : " << valeur6 * 100 / nbLance << " %"
            << std::endl;
}

int main() {
  lance(15000);
  std::cout << std::endl;
  return 0;
}
