#include<iostream>
#include<vector>
#include<numeric>


void exercice1()
{
    unsigned int NbIterations = 17;

    std::vector<int> vec;
    vec.reserve(NbIterations);

    for (unsigned int i=0; i<NbIterations; ++i)
    {
        vec.push_back(i);
        std::cout << "Iteration " << i+1 << " : " << std::endl;
        std::cout << "Taille du vecteur : " << vec.size() << std::endl;
        std::cout << "Memoire allouee : " << vec.capacity() << std::endl;

        vec.shrink_to_fit();
        std::cout << "Memoire ajustee : " << vec.capacity() << std::endl << std::endl;
    }

    std::cout << "Boucle finie " << std::endl;
}
// Size est la taille effective et capacity est la taille réelle allouée au vecteur


int main()
{
    exercice1();
    return 0;
}