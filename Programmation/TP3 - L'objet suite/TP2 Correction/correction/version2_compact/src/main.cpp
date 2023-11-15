#include <iostream>
#include <cstdlib>

#include "VectorD.hpp"


// g++ -Wall -O2 -std=c++11 main.cpp VectorD.cpp -o VectorD


int main() {

    // test vec[3] = 42
    VectorD v2(5, 0.0);
    v2[3] = 42;
    std::cout << "v2 = " << v2[3] << std::endl;

    // obtenir la taille du v2
    std::cout << "size de v2 = " << v2.size() << std::endl;

    return 0;
}