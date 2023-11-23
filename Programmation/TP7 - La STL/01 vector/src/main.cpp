
#include<iostream>
#include<vector>
#include<numeric>
#include <algorithm>


void exo1()
{
	// exo 1:2
	{
		std::vector<int> vec;
		const unsigned int maxElement = 42;

		for(unsigned int i=0; i<maxElement; ++i){
			std::cout << "iteration : " << i << std::endl;
			std::cout << "size      : " << vec.size() << std::endl;
			std::cout << "capacity  : " << vec.capacity() << std::endl << std::endl;
			vec.push_back(i);
		}
		// with clang and gcc, capacity is : 0-1-2-4-4-8-8-8-8-16 ... 
		// with visual studio, capacity is : 0-1-2-3-4-6-6-9-9-9-13 ... 19 ... 28 ... 42 		
	}

	// exo 1:4
	{
		const size_t index = 42;
		std::vector<int> vec;
		for(unsigned int i=0; i<index; ++i)
			vec.push_back(i);
		std::cout << "with push push_back " << std::endl;
		std::cout << "specified size : " << index << std::endl;
		std::cout << "size           : " << vec.size() << std::endl;
		std::cout << "capacity       : " << vec.capacity() << std::endl << std::endl;

		vec.shrink_to_fit();
		std::cout << "shrink to fit " << std::endl;
		std::cout << "specified size : " << index << std::endl;
		std::cout << "size           : " << vec.size() << std::endl;
		std::cout << "capacity       : " << vec.capacity() << std::endl << std::endl;
	}

	// exo 1:5
	{
		const size_t index = 42;
		std::vector<int> vec1;
		vec1.reserve(index);
		std::cout << "with resreve " << std::endl;
		std::cout << "specified size : " << index << std::endl;
		std::cout << "size           : " << vec1.size() << std::endl;
		std::cout << "capacity       : " << vec1.capacity() << std::endl << std::endl;

		std::vector<int> vec2(index);
		std::cout << "with constructor(size) " << std::endl;
		std::cout << "specified size : " << index << std::endl;
		std::cout << "size           : " << vec2.size() << std::endl;
		std::cout << "capacity       : " << vec2.capacity() << std::endl << std::endl;
	}
}


void afficheVector1(const std::vector<int> &vec){

	for(auto e = vec.cbegin(); e != vec.cend(); ++e)
		std::cout << *e << " ";
	std::cout << std::endl;
}


void afficheVector2(const std::vector<int> &vec){

	for(const auto & e :vec )
		std::cout << e << " ";
	std::cout << std::endl;
}

void exo2()
{
	std::vector<int> vec = {2, 4, 6, 8, 10};

	// iterator
	for(auto e = vec.begin(); e != vec.end(); ++e)
		std::cout << *e << " ";
	std::cout << std::endl;

	afficheVector1(vec);
	afficheVector2(vec);
	std::cout << std::endl;
}



void exo3_sort_default(std::vector<int> vec)
{
	std::cout << "vector initial  : ";
	afficheVector2(vec);

	std::sort(vec.begin(),vec.end());	

	std::cout << "vector trié     : ";
	afficheVector2(vec);
}


bool my_sort(const int a, const int b){
	if( (a%2)==(b%2) ) return(),vec.end(), my_sort);	
	std::cout << "vector trié     : ";
	afficheVector2(vec);
}


void exo3_sort_anonymous_lambda(std::vector<int> vec)
{
	std::cout << "vector initial  : ";
	afficheVector2(vec);

	std::sort(vec.begin(),vec.end(),[](const int &a, const int &b){if( (a%2)==(b%2) ) return a<b; return (a%2 == 0); });
	std::cout << "vector trié     : ";
	afficheVector2(vec);
}


void exo3_sort_defined_lambda(std::vector<int> vec)
{
	std::cout << "vector initial  : ";
	afficheVector2(vec);

	std::function<bool(const int, const int)> my_lambda_sort;
	my_lambda_sort = [](const int &a, const int &b){ if( (a%2)==(b%2) ) return a<b; return (a%2 == 0); };
	std::sort(vec.begin(),vec.end(), my_lambda_sort);

	std::cout << "vector trié     : ";
	afficheVector2(vec);
}


void exo3()
{
	std::vector<int> vec = {75, -12, 7, 25, -9, 34};

	std::cout << "\nsort by default" << std::endl;
	exo3_sort_default(vec);

	std::cout << "\nsort with a regular function" << std::endl;
	exo3_sort_function(vec);

	std::cout << "\nsort with an anonymous lambda function" << std::endl;
	exo3_sort_anonymous_lambda(vec);

	std::cout << "\nsort with a defined lambda function" << std::endl;
	exo3_sort_defined_lambda(vec);



	std::cout << "nb occurences 7 : " << std::count(vec.begin(), vec.end(), 7) << std::endl;

	std::vector<int> vec2 = vec;
	std::cout << "inner product   : " << std::inner_product(vec.begin(), vec.end(), vec2.begin(), 0) << std::endl;
	std::cout << std::endl;
}



// int main(){lement in O(1)

// 	exo2();

// 	exo3();

// 	return 0;
// }