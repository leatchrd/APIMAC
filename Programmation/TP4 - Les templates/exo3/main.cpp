#include <iostream>

#include "Tableau.hpp"


// g++ -Wall -O2 -std=c++11 main.cpp

int main()
{
	Tableau<int,5> tab;

	std::cout << "isEmpty    : " << tab.isEmpty() << std::endl;
	std::cout << "getSize    : " << tab.getSize() << std::endl;
	std::cout << "getMaxSize : " << tab.getMaxSize() << std::endl;

	tab.push(41);
	tab.push(42);
	tab.push(43);
	tab.push(44);

	std::cout << "isEmpty    : " << tab.isEmpty() << std::endl;
	std::cout << "getSize    : " << tab.getSize() << std::endl;
	std::cout << "getMaxSize : " << tab.getMaxSize() << std::endl;

	std::cout << tab << std::endl;

	tab[2] = 21;
	tab.pop();

	std::cout << tab << std::endl;

	return 0;
}