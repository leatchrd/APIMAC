// ================================
// POO C++ - IMAC 2
// TP 1 - Exercice 1
// ================================

// g++ -Wall -O2 TP1_ex1.cpp -o ex1

#include<iostream>

int main(){
    std::cout << "Les imacs sont des brutes de C++" << std::endl;

    int val = 10;
    std::cout << "value = " << val << std::endl;

    if (val == 42){ 
        // sortie standard
        std::cout << "Parfait" << std::endl;
    } else if (val > 0){ 
        // sortie standard
        std::cout << "Strictement positif" << std::endl;
    } else { // inutile d'utiliser un else if
        // sortie d'erreur
        std::cerr << "Negatif" << std::endl;
    }
   
    return 0;
}