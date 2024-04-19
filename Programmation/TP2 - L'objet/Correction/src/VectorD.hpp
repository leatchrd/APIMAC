#pragma once

#include <iostream>
#include <vector>

class VectorD {


public :
	
	std::vector<double> m_data;
	

public:

	// default constructor
	VectorD();
	
	// parameter constructor
	VectorD(const size_t size);

	// initializer constructor
	VectorD(const size_t size, const double value);

	// copy constructor
	VectorD(const VectorD &v);

	// destructor
	~VectorD();

	// methods
	void   display() const;
	double dot(const VectorD &v) const;
	double norm() const;

	// operators
	VectorD& operator=(const VectorD &vec);
};
