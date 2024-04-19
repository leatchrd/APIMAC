#include "VectorD.hpp"

#include <fstream>
#include <cstdlib>    // size_t
#include <algorithm>  // transform, inner
#include <cmath>      // sqrt



VectorD::VectorD(const VectorD & v) : m_data(v.m_data){
}

VectorD::VectorD(const size_t size, const double &value) : m_data(size, value)
{
	//std::fill(m_data.begin(), m_data.end(), value);
}


VectorD & VectorD::operator=(const VectorD &v){
	if(&v == this) return *this;

	m_data = v.m_data;

	return *this;
}


double& VectorD::operator[](const size_t& i){
	return m_data[i];
}


const double& VectorD::operator[](const size_t& i) const {
	return m_data[i];
}


VectorD VectorD::operator+(const VectorD &v) const
{
	if(v.size() != this->size()){
		std::cerr << "error: VectorD::operator+: operand with incompatible size" << std::endl;
		return *this;
	}

	VectorD result(size());
	std::transform(m_data.begin(), m_data.begin()+size(), v.m_data.begin(), result.m_data.begin(), std::plus<double>());

	return result;
}


VectorD VectorD::operator-(const VectorD &v) const
{
	if(v.size() != this->size()){
		std::cerr << "error: VectorD::operator-: operand with incompatible size" << std::endl;
		return *this;
	}

	VectorD result(size());
	std::transform(m_data.begin(), m_data.begin()+size(), v.m_data.begin(), result.m_data.begin(), std::minus<double>());

	return result;
}


VectorD VectorD::operator-() const
{
	VectorD result(size());
	for(size_t i=0; i<size(); ++i)
		result[i] = -m_data[i];

	return result;
}


VectorD VectorD::operator*(const double &value) const
{
	VectorD result(*this);
	for(size_t i=0; i<size(); ++i)
		result[i] *= value;

	return result;
}


double VectorD::norm() const{
	return sqrt(this->dot(*this));
}


void VectorD::normalize() {
	double vec_norm = this->norm();

	if (std::abs(vec_norm) < 1.0e-10)
		return;
	
	for (size_t i =0; i<size(); i++) 
		m_data[i] /= vec_norm;
}


double VectorD::dot(const VectorD & v) const {
	if (size() != v.size() ) {
		std::cerr << "Erreur dans la taille du vecteur " << std::endl;
		exit(EXIT_FAILURE);
	}	
	double result = 0.0;
	for(size_t i=0; i<size(); ++i)
		result += m_data[i]*v[i];

	// return std::inner_product(m_data.begin(), m_data+size(), v.m_data.begin(),0.0);

	return result;
}



int VectorD::save(const std::string &filename) const{

	//open the file
	std::ofstream myfile;
	myfile.open(filename, std::ios::out | std::ios::binary);
	
	if(!myfile.is_open()){
		std::cerr << "error: can not create file: " << filename << std::endl;
		return EXIT_FAILURE;
	}

	// write the vector size
	myfile << size() << std::endl;

	for(size_t i=0; i<size(); ++i)
		myfile << m_data[i] << " ";

	myfile.close();

	return EXIT_SUCCESS;
}


int VectorD::load(const std::string &filename){

	//open the file
	std::ifstream myfile;
	myfile.open(filename, std::ios::in | std::ios::binary);
	if(!myfile.is_open()){
		std::cerr << "error: can not open file: " << filename << std::endl;
		return EXIT_FAILURE;
	}

	// read the vector size
	size_t vectorSize;
	myfile >> vectorSize;
	if(vectorSize != size())
		*this = VectorD(vectorSize);

	// read the data
	for(size_t i=0; i<vectorSize; ++i)
		myfile >> m_data[i];

	// close file
	myfile.close();
	return EXIT_SUCCESS;
}


void VectorD::display() const {
	for(size_t i=0; i< m_data.size(); ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}


std::ostream& operator<< (std::ostream& stream, const VectorD& v) {
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


VectorD operator*(const double value, const VectorD &vec){
	return vec * value;
}