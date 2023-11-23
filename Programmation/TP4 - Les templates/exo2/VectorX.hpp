#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <cassert>


// g++ -Wall -O2 -std=c++11 main.cpp VectorX.hpp

// Doxygen menu
/// \version 0.1
/// \mainpage
/// \image html myImage.jpg
/// \tableofcontents
/// \section instroduction_sec What for?
/// VectorX is a super tool.
/// \section install_bigsec How to install
/// \subsection dependencies_sec Dependecies
/// \li nothing
/// \li nothing else
/// \li Doxygen (if you want the documentation)
/// \subsection install_sec Install with cmake (Linux)
/// \li go to main dir
/// \li mkdir build
/// \li cd build
/// \li cmake ..
/// \li make
/// \li make html
/// \li The documentation is located in [path to build]/doc/doc-doxygen/html/index.html



/// \class VectorX
/// \brief class defining a vector for linear algebra operations.
template<typename T>
class VectorX {

public:

	/// \brief constructor from a size and default constructor
	/// \param size  : the size of the requested vector (optional)
	/// \param value : the default value used to fill the vector (optional)
	VectorX(const size_t size = 0, const T &value = static_cast<T>(0))
		: m_data(size,value)
		{};

	/// \brief copy-constructor
	/// \param vec : the source vector to be copied
	VectorX(const VectorX & vec) = default;

	/// \brief destructor
	~VectorX() = default;

	// copy constructor from other type
	template <typename U>
	friend class VectorX;

#if 0
	/// \brief copy constructor from different template type
	/// \param vec : the source vector to be copied
	template<typename U>
	VectorX<T>(const VectorX<U> &vec) 
		: VectorX<T>(vec.size())
	{
		// access to a private member of VectorX<U>, VectorX<T> and VectorX<U> must be friend
		std::transform(vec.m_data.begin(), vec.m_data.end(), m_data.begin(), [](const U &x) { return static_cast<T>(x);});
	}
#else
	template<typename U>
	VectorX<T>(const VectorX<U> &vec) 
		: VectorX<T>(vec.size())
	{
		for(size_t i=0; i<vec.size(); ++i)
			m_data[i] = static_cast<T>(vec[i]); 
	}
#endif


private :
  
  	// attribute (components of the vector)
	std::vector<T> m_data;  /*!< components of the vector */


public :
	
	// methods ///////////////////////////

	/// \brief return the size of a Vector
	size_t size() const { return m_data.size(); }

	/// \brief compute the inner product between 2 vectors
	/// \param v : the second vector to consider in the dot product.
	/// \return : the scalar value corresponding to the dot product. 
	T dot(const VectorX &v) const;

	/// \brief compute the norm L2 of a vector
	/// \return the L2 norm of the calling vector	
	T norm() const;

   	/// \brief inplace normalize a vector such its norm is 1.
	void normalize();

	/// \brief save a vector in a file
	/// \param filemane : name of the file (including path) where to save the vector data
	/// \return true if the file is save correctly, else false	
	bool save(const std::string &filename) const;

	// \brief load a vector from a file, the size of the vector should be already the good one ...
	/// \param filemane : name of the file (including path) to open and load the vector data
	/// \return true if the file is save correctly, else false	
	bool load(const std::string &filename);



	// operators ///////////////////////////

	/// \brief affectation operator
	VectorX & operator=(const VectorX &v);

	/// \brief operator to access to the ist element of a vector
	/// \param  i: index of the targeted vector component
	/// \return vector[i] 
	T& operator[](const size_t& i) {return m_data[i];};

	/// \brief operator to access to the ist element of a vector (const version)
	/// \param i: index of the targeted vector component
	/// \return vector[i] (constant reference)
	const T& operator[](const size_t& i) const {return m_data[i];};

	/// \brief add 2 vectors of same size
	/// \param vector to add to the calling vector (should have the same dimension as the calling vector)
	/// \return the sum of the current vector and the argument vector
	VectorX operator+(const VectorX &v) const;

	/// \brief substract a vector to *this (where the two vectors have the same size)
	/// \param vector to substract to the calling vector (should have the same dimension as the calling vector)
	/// \return the sum of the current vector and the argument vector
	VectorX operator-(const VectorX &v) const;

	/// \brief unary minus
	/// \return the minus the calling vector 	
	VectorX operator-() const;

	/// \brief scale a vector with a constant value
	/// \param scale factor
	/// \return the scaled vector
	VectorX operator*(const T &value) const;
};



template<typename T>
VectorX<T> & VectorX<T>::operator=(const VectorX<T> &v){
	if(&v == this) return *this;

	m_data = v.m_data;

	return *this;
}


template<typename T>
VectorX<T> VectorX<T>::operator+(const VectorX<T> &v) const
{
	assert(v.size() == this->size() && "error: VectorX::operator+: operands with incompatible size");

	VectorX<T> result(size());
	std::transform(m_data.begin(), m_data.begin()+size(), v.m_data.begin(), result.m_data.begin(), std::plus<double>());

	return result;
}


template<typename T>
VectorX<T> VectorX<T>::operator-(const VectorX<T> &v) const
{
	assert(v.size() == this->size() && "error: VectorX::operator-: operands with incompatible size");

	VectorX<T> result(size());
	std::transform(m_data.begin(), m_data.begin()+size(), v.m_data.begin(), result.m_data.begin(), std::minus<double>());

	return result;
}


template<typename T>
VectorX<T> VectorX<T>::operator-() const
{
	VectorX<T> result(size());
	for(size_t i=0; i<size(); ++i)
		result[i] = -m_data[i];

	return result;
}


template<typename T>
VectorX<T> VectorX<T>::operator*(const T &value) const
{
	VectorX<T> result(*this);
	for(size_t i=0; i<size(); ++i)
		result[i] *= value;

	return result;
}


template<typename T>
T VectorX<T>::dot(const VectorX<T> & v) const {  

	assert(v.size() == this->size() && "error: VectorX::dot: operands with incompatible size");

	// T result = static_cast<T>(0);
	// for(size_t i=0; i<size(); ++i)
	// 	result += m_data[i]*v[i];
	// return result;

	return std::inner_product(m_data.begin(), m_data.end(), v.m_data.begin(), static_cast<T>(0));
}


template<typename T>
T VectorX<T>::norm() const{
	return sqrt(this->dot(*this));
}


template<typename T>
void VectorX<T>::normalize() {
	T vec_norm = this->norm();

	if (std::abs(vec_norm) < static_cast<T>(1.0e-10))
		return;
	
	for (size_t i =0; i<size(); i++) 
		m_data[i] /= vec_norm;
}


template<typename T>
std::ostream& operator<< (std::ostream& stream, const VectorX<T>& v){
	if(v.size() == 0){
		stream << "Not initialized yet -> size is 0";
		return stream;
	}
			
	stream << "(";
	for(unsigned int i=0; i<v.size()-1; ++i)
		stream << v[i] << " , ";
 
 	stream << v[v.size()-1] << ")";

	return stream;
}


template<typename T>
bool VectorX<T>::save(const std::string &filename) const{

	//open the file
	std::ofstream myfile;
	myfile.open(filename, std::ios::out | std::ios::binary);
	
	if(!myfile.is_open()){
		std::cerr << "error: can not create file: " << filename << std::endl;
		return false;
	}

	// write the vector size
	myfile << size() << std::endl;

	for(size_t i=0; i<size(); ++i)
		myfile << m_data[i] << " ";

	myfile.close();

	return true;
}


template<typename T>
bool VectorX<T>::load(const std::string &filename){

	//open the file
	std::ifstream myfile;
	myfile.open(filename, std::ios::in | std::ios::binary);
	if(!myfile.is_open()){
		std::cerr << "error: can not open file: " << filename << std::endl;
		return false;
	}

	// read the vector size
	size_t vectorSize;
	myfile >> vectorSize;
	if(vectorSize != size())
		*this = VectorX(vectorSize);

	// read the data
	for(size_t i=0; i<vectorSize; ++i)
		myfile >> m_data[i];

	// close file
	myfile.close();
	return true;
}

