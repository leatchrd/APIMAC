#pragma once
#include <vector>

class VectorD {
    public: 
    std::vector<double> m_data;

    // Constructeur par défaut
    VectorD();

    // Constructeur paramètre
    VectorD(const size_t size);

    // Constructeur initialisation
    VectorD(const size_t size, const double value);

    // Constructeur par recopie
    VectorD(const VectorD &vec);

    // Destructeur
    ~VectorD();

    // Méthode display
    void display() const;

    // Méthode dot
    double dot(const VectorD &v) const;
};