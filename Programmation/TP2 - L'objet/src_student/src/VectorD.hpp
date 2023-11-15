#pragma once
#include <vector>

class VectorD {
    public: 
    std::vector<double> m_data;

    // Constructeur 1 (par défaut)
    VectorD();
    // Constructeur 2
    VectorD(const unsigned int size);
    // Constructeur 3
    VectorD(const unsigned int size, const double &value);

    // Constructeur par recopie
    VectorD(const VectorD &vec);

    // Destructeur
    ~VectorD();

    // Méthode display
    void display() const;

    // Méthode dot
    double dot(const VectorD &v) const;
};