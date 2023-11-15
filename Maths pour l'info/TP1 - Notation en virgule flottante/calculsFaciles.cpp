#include <iostream>
#include <iomanip> 
#include <math.h>


void recherche_racine (const int u, double &r, float pas)
{
    for (int i=0; i<1000; i++)
    {
    if (r * r < u)
    {
        r = r + pas;
    }    
    else 
    {
        r = r - pas;
        continue;
    }
    }
    std::cout << "racine = " << r << std::endl;   
}

int main()
{
    /*
    // Exercice 3
    double u = 1/3.0;
    for (int i=1; i<100; i++)
    {
        u = 4.0 * u - 1.0;
        std::cout << "u =" << u << std::endl;
    }
    */

   // Exercice 4
    const int u = 62;
    double r = 0.0;
    float pas = 0.1;

    for (int i=0; i<5; i++)
    {
        recherche_racine (u, r, pas);
        pas = pas * 0.1;
    }
    std::cout << sqrt(u) << std::endl;
 
    return 0;
}