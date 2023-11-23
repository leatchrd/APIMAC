#include <iostream>

#include "VectorD.hpp"


// g++ -Wall -O2 -std=c++11 main.cpp VectorD.cpp -o test


int main() {

    VectorD v(3);

    v[0] = 1.0;
    v[1] = 0.3; 
    v[2] = 5.2;

    std::cout << "v             : " << v << std::endl;
    std::cout << "size of v     : " << v.size() << std::endl;
    std::cout << "v[2]          : " << v[2] << std::endl << std::endl;
    std::cout << "v*2           : " << v*2 << std::endl;
    std::cout << "2*v           : " << 2*v << std::endl;

    VectorD v2 = v;
    std::cout << "v2            : " <<  v2 << std::endl;
    std::cout << "-v2           : " << -v2 << std::endl;
    std::cout << "v - v2        : " << v - v2 << std::endl;
    v = v + v2;
    std::cout << "v + v2        : " << v << std::endl;

    std::cout << "norm(v2)      : " << v2.norm() << std::endl;
    v2.normalize();
    std::cout << "v2 normalized : " << v2 << std::endl;

    std::cout << "dot product   : " << v.dot(v2) << std::endl << std::endl;


    VectorD v3(5,42);
    std::cout << "v3            : " << v3 << std::endl;


    std::cout << "saving        : " << v << std::endl;   
    v.save("/tmp/vec.txt");

    VectorD v4;
    v4.load("/tmp/vec.txt");
    std::cout << "loading       : " << v4 << std::endl;   


    return 0;
}
