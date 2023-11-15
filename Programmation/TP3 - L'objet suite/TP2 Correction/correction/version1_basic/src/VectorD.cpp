#include <iostream>
#include <cassert>
#include <cmath>

#include "VectorD.hpp"


VectorD::VectorD(const size_t size) 
: m_data(size) 
{}

VectorD::VectorD(const size_t size, const double value) 
: m_data(size,value) 
{}

VectorD::VectorD() 
: m_data() 
{}

VectorD::VectorD(const VectorD &vec) 
: m_data(vec.m_data)
{}

VectorD::~VectorD() 
{}

VectorD& VectorD::operator=(const VectorD &vec)
{
	if(&vec == this) return *this; // check if I am doing "a = a;" -> do nothing

	m_data = vec.m_data;

	return *this;
}

void VectorD::display() const {
	for(size_t i=0; i< m_data.size(); ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

double VectorD::dot(const VectorD & vec) const {
	assert(m_data.size() == vec.m_data.size());

	double result = 0.0;
	for(size_t i=0; i<m_data.size(); ++i)
		result += m_data[i] * vec.m_data[i];

	return result;
}

double VectorD::norm() const
{
	return sqrt(this->dot(*this));
}
