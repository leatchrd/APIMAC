#include<iostream>
#include<vector>
#include <algorithm>
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

void affichageVecteur(const std::vector<int> &vec)
{
    std::cout << "Contenu du vecteur : ";

    for(auto it = vec.cbegin(); it != vec.cend(); ++it)
    {
        std::cout << *it << " - ";
    }
	std::cout << std::endl;
}

bool parite(const int a, const int b)
{
    if ((a%2) == (b%2)) return a<b;
    return (a%2) == 0;
}

void triSort(std::vector<int> &vec)
{
    std::cout << " Tri du vecteur : " << std::endl;
    std::sort(vec.begin(), vec.end(), parite);
}

void count(std::vector<int> &vec, int valeur)
{
    int nbOccur = std::count(vec.begin(), vec.end(), valeur);
    std::cout << "Nombre d'occurences : " << nbOccur << std::endl;
}

int main()
{
    std::vector<int> vec = {1, 5, 4, 3, 2, 9, 6, 7};
    triSort(vec);
    affichageVecteur(vec);
    count(vec, 7);
    return 0;
}

/*conique
intersection cone et plan
l'intersection ressemble à une éllipse, cercle, paire de droites, point, ...
en pratique, si on a 5 points, on peut trouver une ellipse
w, point à l'infini

rapport de 5 pages*/
