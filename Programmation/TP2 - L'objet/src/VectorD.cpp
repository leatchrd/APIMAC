#include "VectorD.hpp"
#include <iostream>

VectorD::VectorD()
// Initialisation
: m_data()
{
    // Code ici
}


// Sinon :
// VectorD::VectorD(const size_t size)
// {
//     m_data = std::vector<double>(size);
// }

// Si on veut que des 0 dans le vecteur
VectorD::VectorD(const size_t size, const double value)
: m_data(size, value)
{}

VectorD::VectorD(const size_t size)
: m_data(size, 0.0)
{}

// Constructeur par recopie
VectorD::VectorD(const VectorD &vec)
: m_data(vec.m_data)
{}

// Destructeur
VectorD::~VectorD()
{}

// Méthode display
void VectorD::display() const
{
    std::cout << m_data.size() << ", " << std::endl;

    for(unsigned int i=0; i<m_data.size(); i++)
    {
        std::cout << m_data[i] << std::endl;
        // std::cout << m_data.at(i) << std::endl; // C'est plus lent mais plus sécure
    }
}

// Méthode dot
double VectorD::dot(const VectorD &v) const
{
    double produit = 0.0;
    
    for (unsigned int i = 0; i < m_data.size(); i++)
    {
      produit += v.m_data[i] * m_data[i];
    }
    
    return produit;
}
