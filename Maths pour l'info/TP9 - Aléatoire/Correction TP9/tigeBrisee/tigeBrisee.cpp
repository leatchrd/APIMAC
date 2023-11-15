#include <iostream>
#include <chrono>
#include <random>
#include <vector>


// g++ -Wall -O3 -std=c++14 tigeBrisee.cpp -o tige


double proba(const unsigned int nbRun){

	// select a random generator engine and a distribution
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> distrib(0,1);

	unsigned int nbTriangles = 0;

	for(unsigned int i=0;i<nbRun; ++i){

		// generate 2 break points
		double break1 = distrib(generator);
		double break2 = distrib(generator);

		// get 3 lengths
		std::vector<double> lengths(3);
		lengths[0] = std::min(break1,break2);
		lengths[1] = std::abs(break1-break2);
		lengths[2] = 1.0 - lengths[0] - lengths[1];

		// sort the lengths
		std::sort(lengths.begin(),lengths.end());

		if(lengths[0] + lengths[1] > lengths[2])
			nbTriangles++;
	}

	return nbTriangles / double(nbRun);
}

int main(){

	std::cout << proba(10000000) << std::endl;

	return 0;
}