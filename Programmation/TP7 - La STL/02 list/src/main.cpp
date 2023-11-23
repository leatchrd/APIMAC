#include<iostream>
#include<list>
#include<string>



int main(){

	// construct the listst
	std::list<std::string> phylosophers   = {"Platon", "Aristote", "Descartes", "Kant"};
	std::list<std::string> mathematicians = {"Gauss", "Laplace", "Poincaré", "Descartes"};

	// sort the lists
	phylosophers.sort();
	std::cout << "phylosophers   : ";
	for(const auto &e : phylosophers)
		std::cout << e << " - ";
	std::cout << std::endl;

	mathematicians.sort();
	std::cout << "mathematicians : ";
	for(const auto &e : mathematicians)
		std::cout << e << " - ";
	std::cout << std::endl;

	// merge the lists
	std::list<std::string> all(mathematicians);
	all.merge(phylosophers);
	std::cout << "merged         : ";
	for(const auto &e : all)
		std::cout << e << " - ";
	std::cout << std::endl;

	// remove duplicates
	all.unique();
	std::cout << "unique         : ";
	for(const auto &e : all)
		std::cout << e << " - ";
	std::cout << std::endl;

	// reverse the list
	all.reverse();
	std::cout << "reverse        : ";
	for(const auto &e : all)
		std::cout << e << " - ";
	std::cout << std::endl;

	return 0;
}