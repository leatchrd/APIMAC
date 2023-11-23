#include <iostream>
#include <cctype>  // toupper

// g++ -Wall -O2 ex1.cpp 


template<typename T>
T getMinimum(const T&a, const T&b)
{
	return a < b ? a : b;
}


// question 3
template<>
char getMinimum(const char &a, const char &b)
{
	return std::toupper(a) < std::toupper(b) ? a : b;
}


int main()
{
	// question 1
	std::cout << "getMinimum(42,57)   = " << getMinimum(42,57) << std::endl;
	std::cout << "getMinimum(4.2,5.7) = " << getMinimum(4.2,5.7) << std::endl;
	std::cout << "getMinimum('v','n') = " << getMinimum('v','n') << std::endl;

	// question 2
	std::cout << "getMinimum(4.2,57)  = " << getMinimum<double>(4.2,57) << std::endl;


	// question 3
	std::cout << "ASCII 'a' = " << int('a') << std::endl;
	std::cout << "ASCII 'z' = " << int('z') << std::endl;
	std::cout << "ASCII 'A' = " << int('A') << std::endl;
	std::cout << "ASCII 'Z' = " << int('Z') << std::endl;

	std::cout << "getMinimum('a','Z') = " << char(getMinimum<unsigned short>('a','Z')) << std::endl;
	std::cout << "getMinimum('a','Z') = " << getMinimum('a','Z') << std::endl;


	return 0;
}