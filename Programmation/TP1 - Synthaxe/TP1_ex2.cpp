// 7 septembre 2023

#include <iostream>
#include <string>

bool voyelle (char lettre)
{
    // char array {'a','e','i','o','u','y','A','E','I','O','U','Y'};
    // int size_array = array.length()-1;

    // for (int i= 0; i < size_array; i++)
    // {
    //     if (lettre == array[i])
    //         return;

    //     else
    //         return false;
    // }
    return false;
}

bool voyelle_bis (char lettre)
{
    lettre = std::tolower(lettre);
    std::string voyelles = "aeiouy";

    for (unsigned int i = 0; i < voyelles.length(); i++)
    {
        if (lettre == voyelles[i])
            return true;
    }
    return false;
}

int main ()
{
    std::string chaine = "chaine de caracteres";
    std::cout << chaine << std::endl;

    std::cout << std::endl;

    std::cout   << "String size : " << chaine.length() << "\n" 
                << "Last element : " << chaine[chaine.length()-1] << std::endl;
    
    std::cout << std::endl;

    std::string chaine_without_last = chaine.erase(chaine.length()-1);
    std::cout << "La chaine sans le dernier caractere : " << chaine_without_last << std::endl;

    std::cout << std::endl;

    std::string chaine_imac = chaine.insert(0, "IMAC");
    std::cout << "La chaine avec IMAC devant : " << chaine_imac << std::endl;

    std::cout << std::endl;

    // Etape 1 : Savoir si la lettre est une voyelle ou non

    for (unsigned int i = 0; i < chaine_majuscule.length(); i++)
    {
        if (voyelle_bis(chaine_majuscule[i]))
            chaine_majuscule[i] = std::tolower(chaine_majuscule[i]);

        else
            chaine_majuscule[i] = std::toupper(chaine_majuscule[i]);
    }

    std::cout << "La chaine avec les voyelles en majuscule : " << chaine_majuscule << std::endl;    
}

// faire question 8