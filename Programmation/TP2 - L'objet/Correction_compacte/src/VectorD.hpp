#pragma once

#include <iostream>
#include <vector>
#include <cmath>


class VectorD {

public :
    
    std::vector<double> m_data;


    // constructor and default constructor
    VectorD(const size_t size=0, const double value = 0.0);  // if we don't specify these parameters, they are replaced by their default value

    // copy constructor
	VectorD(const VectorD &v) = default;  // calls the default constructor of each class attribute (success expected in this class VectorD)

    // destructor
    ~VectorD() = default;   // calls the destructor of each class attribute (success expected in this class VectorD)

    // methods
    void display() const;
    double dot(const VectorD &v) const;
    inline double norm() const { return sqrt(this->dot(*this)); }

    // operators
    VectorD& operator=(const VectorD &vec);

    // VectorD sum(VectorD vec2);
};

