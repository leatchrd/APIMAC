// 7 septembre 2023

#include <iostream>

int main ()
{
    std::cout << "Les IMACs sont des brutes de C++" << std::endl;

    int nb = -43;
    std::cout << "Nombre = " << nb << std::endl;
    
    if (nb == 42)
    {
        std::cout << "Parfait" << std::endl;
    }

    if (nb > 0)
    {
        std::cout << "Strictement positif" << std::endl;
    }
    
    else if (nb < 0)
    {
        std::cerr << "Négatif" << std::endl; // Sortie d'erreur
    }

    return 0;
}