#include<iostream>
#include<map>
#include<string>


int main(){

	std::map<std::string, int> departements;

	departements.insert( std::pair<std::string, int>("Côtes d'Armor", 22) );
	departements.insert( {"Aveyron", 12} );
	departements.insert( {"Seine-et-Marne", 77} );
	departements.insert( {"Haute-Savoie", 74} );

	for(const auto &e : departements)
		std::cout << e.first << " - " << e.second << std::endl;

	return 0;
}