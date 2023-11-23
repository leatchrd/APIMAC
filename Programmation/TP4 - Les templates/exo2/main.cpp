#include <iostream>


#include "VectorX.hpp"


// g++ -Wall -O2 -std=c++11 main.cpp VectorX.hpp


int main(int argc, char **argv) {

    VectorX<float> v1(3,42.0);
    std::cout << "(constructor) v1 : " << v1 << std::endl; 

    VectorX<float> v2(v1);
    std::cout << "(copy constr) v2 : " << v2 << std::endl; 

    VectorX<float> v3;
    std::cout << "(def constr)  v3 : " << v3 << std::endl; 

    VectorX<float> v4(3);
    v4 = v1;
    std::cout << "(operator =)  v4 : " << v4 << std::endl; 

    v1[1] = 10;
    std::cout << "(op [])       v1 : " << v1 << std::endl; 

    const VectorX<float> v5 = v1;
    std::cout << "(op[] const)     : " << v5[1] << std::endl; 

    std::cout << "(operator +)     : " << v1 + v2 << std::endl; 
    std::cout << "(operator -)     : " << v1 - v2 << std::endl; 
    std::cout << "(op unary -)     : " << -v1 << std::endl; 

    std::cout << "(dot)   v1.v2    : " << v1.dot(v2) << std::endl;
    std::cout << "(norm)  v1.norm  : " << v1.norm() << std::endl; 

    v1.normalize();
    std::cout << "(normalize)  v1  : " << v1 << std::endl; 

    v1.save("/tmp/test.vec");
    VectorX<float> v6;
    v6.load("/tmp/test.vec");
    std::cout << "(load/save)  v1  : " << v6 << std::endl; 


    VectorX<double> vecDouble(3,2.5);
    std::cout << "(VectorX<double>): " << vecDouble << std::endl; 


    VectorX<float> vecFloatFromDouble(vecDouble);
    std::cout << "(convert U -> T) : " << vecFloatFromDouble << std::endl; 

    return 0;
}
