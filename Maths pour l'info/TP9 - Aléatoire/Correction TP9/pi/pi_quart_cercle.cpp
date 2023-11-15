#include <iostream>
#include <chrono>
#include <random>
#include <cmath>
#include <iomanip>

// g++ -Wall -O2 pi_quart_cercle.cpp

/*
# Explications :
- Prenons **a = 1**
- Aire du carré  : **Ac = 1**
- Aire du disque : **Ad = pi r^2 / 4 = pi/4**
- On part du principe qu'en jetant des points aléatoires uniformément sur le carré, certains vont tomber dans le quart de cercle et d'autres non.
- Le rapport des aires (carré / quart de disque) sera donc proportionnel au rapport du nombre de points tombant dans le carré (tous les points) et ceux qui tombent dans le disque.
- Un point (x,y) tombe dans le disque si sa distance à l'origine (centre du cercle) est inférieur à r=1, autrement dit si x^2 + y^2 < 1^2 = 1
- En pratique, il suffit alors de jeter pleins de points dans le carré, voir ceux qui tombent dans le quart de cercle et faire le ratio.
- Au final :  **pi ~ 4 . nbPointsDisque / nbPointTotal **
*/

double pi(const unsigned int nbIter){

	// select seed from time
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::cout << "seed : " << seed << std::endl;

	// select a random generator engine and a distribution
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> uniformRealDistribution(0,1);

	unsigned int nbPointsInCircle = 0;

	// start launching points
	for(unsigned int i=0; i<nbIter; ++i){
		const double x = uniformRealDistribution(generator);
		const double y = uniformRealDistribution(generator);

		if(x*x + y*y < 1.0)
			nbPointsInCircle++;
	}

	return  4.0 * nbPointsInCircle / double(nbIter);
}

template<typename T>
T pi_template(const unsigned int nbIter){

	// select a random generator engine and a distribution
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<T> uniformRealDistribution(0,1);

	unsigned int nbPointsInCircle = 0;

	// start launching points
	for(unsigned int i=0; i<nbIter; ++i){
		const T x = uniformRealDistribution(generator);
		const T y = uniformRealDistribution(generator);

		if(x*x + y*y < static_cast<T>(1.0))
			nbPointsInCircle++;
	}

	return  4.0 * nbPointsInCircle / static_cast<T>(nbIter);
}



int main(){

	const unsigned int nbIter = 1000000000;
	std::cout << std::setprecision(20) << std::abs(pi(nbIter) - M_PI) << std::endl;
	std::cout << std::setprecision(20) << std::abs(pi_template<long double>(nbIter) - M_PI) << std::endl;
	std::cout << std::setprecision(20) << M_PI << std::endl;

	return 0;
}