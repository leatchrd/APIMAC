#include <iostream>
#include "VectorD.hpp"

// g++ -Wall -O2 -std=c++11 main.cpp VectorD.cpp -o VectorD


int main() {

    VectorD vec1();
    VectorD vec2(42);
    VectorD vec3 (5, 1.0);

    vec3.display();

    return 0;
}
