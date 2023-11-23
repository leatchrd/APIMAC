#include <iostream>
#include <cstdlib>

#include "VectorD.hpp"


// g++ -Wall -O2 -std=c++11 main.cpp VectorD.cpp -o VectorD




int main(int argc, char **argv) {

    // test constructor
    VectorD v1(3);
    v1.m_data[0] = 1.0;
    v1.m_data[1] = 0.5;
    v1.m_data[2] = 2.0;

    std::cout << "v1 = ";
    v1.display();

    // test constructor initialization
    VectorD v2(3,2);
    std::cout << "v2 = ";
    v2.display();

    // test default constructor
    VectorD v3;
    std::cout << "v3 = ";
    v3.display();

    // test copy constructor
    VectorD v4(v1);
    std::cout << "v4 = ";
    v4.display();

    // test dot
    std::cout << "v1.v2   = " <<  v1.dot(v2) << std::endl;

    // test norm
    std::cout << "v2.norm = " <<  v2.norm() << std::endl;

    // test operator =
    v4 = v2;
    std::cout << "v4 = ";
    v4.display();

    // // test sum
    // VectorD vFlo(3);
    // vFlo.m_data[1] = 1;
    // vFlo.m_data[2] = 1;
    // vFlo.m_data[0] = 1;

    // std::cout << vFlo.sum(v1) <<std::endl;

    return 0;
}
