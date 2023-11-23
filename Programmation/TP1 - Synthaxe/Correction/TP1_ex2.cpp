// ================================
// POO C++ - IMAC 2
// TP 1 - Exercice 2
// ================================

// g++ -Wall -O2 -std=c++11 TP1_ex2.cpp -o ex2

#include<iostream>
#include<string>

// ------------------------------------- 7
bool isVowel(const char my_char)
{
    const char c = std::tolower(my_char);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
    {
        return true;
    }
    return false;
}


int main(int argc, char *argv[])
{

    // ------------------------------------- 1
    // nom => TP1_ex2.cpp

    // ------------------------------------- 3
    std::string my_string = "I love C++";
    std::cout << my_string << std::endl;

    // ------------------------------------- 4
    /// n'utilisez qu'un seul cout
    /// back() fait partie de C++11, il faut rajouter l'option de compilation -std=c++11
    std::cout   << "String size  : " << my_string.size() << std::endl
                << "Last element : " << my_string.back() << std::endl;

    // ------------------------------------- 5
    my_string.pop_back();
    std::cout << my_string << std::endl;

    /// ou bien
    /// utiliser une variable locale pour stocker la taille (eviter d'appeler plusieurs fois size()/length())
    /// dans un vrai programme doit etre fait question 2
    // const size_t strSize = my_string.size(); // ou my_string.length()
    // my_string.erase(strSize - 1, strSize);
    // std::cout << my_string << std::endl;

    // ------------------------------------- 6

    my_string = "Les imacs and " + my_string;
    // my_string.insert(0, "IMAC");
    std::cout << my_string << std::endl;

    // ------------------------------------- 7
    for (size_t i = 0; i < my_string.length(); ++i)
    {
        if (isVowel(my_string[i]))
        {
            my_string[i] = std::toupper(my_string[i]); // voyelle en majuscule
        }
        else
        {
            my_string[i] = std::tolower(my_string[i]); // consonne en minuscule
        }
    }
    std::cout << my_string << std::endl;

    // ------------------------------------- 8
    size_t beginId = 0;
    size_t endId = my_string.size() - 1;

    while (beginId < endId)
    {
        std::swap(my_string[beginId], my_string[endId]);
        ++beginId;
        --endId;
    }
    std::cout << my_string << std::endl;


    return 0;
}