#include<iostream>
#include<vector>
#include<numeric>


std::vector<int> exercice1()
{
    std::cout << "Exercice 1 " << std::endl;

    unsigned int NbIterations = 17;

    std::vector<int> vec;
    vec.reserve(NbIterations);

    for (unsigned int i=0; i<NbIterations; ++i)
    {
        vec.push_back(i);
        std::cout << "Iteration " << i+1 << " : " << std::endl;
        std::cout << "Memoire ajustee : " << vec.capacity() << std::endl << std::endl;
    }

    std::cout << "Boucle finie " << std::endl << std::endl;
    return vec;
}

void exercice2(const std::vector<int> &vec)
{
    std::cout << "Exercice 2 " << std::endl;
    std::cout << "Contenu du vecteur : ";

    for(auto it = vec.cbegin(); it != vec.cend(); ++it)
    {
        std::cout << *it << " - ";
    }
	std::cout << std::endl;
}


int main()
{
    std::vector<int> vec = exercice1();
    exercice2(vec);
    return 0;
}