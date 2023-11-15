
#include<iostream>
#include<vector>
#include <functional>

int main(){
	/////////////////////////////////////////////////////////
	try
	{
		std::vector<long double> vec(100000000000000000);
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "L'argument de vec est trop long" << '\n';
	}
	
	
	/////////////////////////////////////////////////////////
	std::vector<double> vec2(5,0.0);
	[[maybe_unused]] double value;
	try
	{
		value = vec2.at(10);
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "On ne peut pas mettre 10 éléments car il n'y a que 5 places" << '\n';
	}

	/////////////////////////////////////////////////////////
	std::function<int(int,int)> plop;  // function declared but not defined
	[[maybe_unused]] int a;
	try
	{
		a = plop(42,42);
	}
	catch(const std::bad_function_call& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "La fonction est declaree mais pas definie" << '\n';
	}

	std::cout << "end of program" << std::endl;

	return 0;
}