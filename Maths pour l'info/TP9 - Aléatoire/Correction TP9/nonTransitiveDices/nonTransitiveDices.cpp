#include <iostream>
#include <chrono>
#include <random>
#include <vector>


// g++ -Wall -O3 -std=c++14 nonTransitiveDices.cpp -o nonTransitiveDices

// https://plus.maths.org/content/non-transitiv-dice
// https://mathartfun.com/dSpecial.html

bool fight(const std::vector<unsigned int> &dice1, const std::vector<unsigned int> &dice2, const unsigned int nbRolls){

	// select a random generator engine and a distribution
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distrib(0,5);
	auto dice = std::bind(distrib, generator);

	// roll dices
	unsigned int nbWinDice1 = 0;
	unsigned int nbWinDice2 = 0;
	for(unsigned int i=0; i<nbRolls; ++i){
		if(dice1[dice()] > dice2[dice()]) nbWinDice1++;
		else nbWinDice2++;
	}

	return nbWinDice1 > nbWinDice2;
}


bool fightExtention(const std::vector<unsigned int> &dice1a, 
					const std::vector<unsigned int> &dice1b, 
					const std::vector<unsigned int> &dice2a, 
					const std::vector<unsigned int> &dice2b, 
					const unsigned int nbRolls){

	// select a random generator engine and a distribution
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distrib(0,5);
	auto dice = std::bind(distrib, generator);

	// roll dices
	unsigned int nbWinDice1 = 0;
	unsigned int nbWinDice2 = 0;
	for(unsigned int i=0; i<nbRolls; ++i){
		if( (dice1a[dice()] + dice1b[dice()]) > (dice2a[dice()] + dice2b[dice()])) nbWinDice1++;
		else nbWinDice2++;
	}

	return nbWinDice1 > nbWinDice2;
}


int main(){

	const std::vector<unsigned int> A = {3,3,3,3,3,6};
	const std::vector<unsigned int> B = {2,2,2,5,5,5};
	const std::vector<unsigned int> C = {1,4,4,4,4,4};

	const unsigned int nbRolls = 1000000;
	std::cout << "A vs. B : the winner is " << (fight(A,B,nbRolls) ? "A" : "B") << " !" << std::endl;
	std::cout << "B vs. C : the winner is " << (fight(B,C,nbRolls) ? "B" : "C") << " !" << std::endl;
	std::cout << "C vs. A : the winner is " << (fight(C,A,nbRolls) ? "C" : "A") << " !" << std::endl;

	std::cout << std::endl << "et pour l'extention " << std::endl;
	std::cout << "AB vs. AC : the winner is " << (fightExtention(A,B,A,C,nbRolls) ? "AB" : "AC") << " !" << std::endl;
	std::cout << "AC vs. BC : the winner is " << (fightExtention(A,C,B,C,nbRolls) ? "AC" : "BC") << " !" << std::endl;
	std::cout << "BC vs. AB : the winner is " << (fightExtention(B,C,A,B,nbRolls) ? "BC" : "AB") << " !" << std::endl;

	return 0;
}
