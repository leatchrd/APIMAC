#include<iostream>
#include<vector>


// g++ -Wall -O2 TP1_ex3.cpp -o ex3

int main(int argc, char *argv[])
{
    //-------------------------------------- 1
    std::vector<int> my_vector;

    // ------------------------------------- 2
    size_t vec_size = 10;
    std::cout << "vector size: " << vec_size << std::endl;

    // push_back
    for (size_t i = 0; i < vec_size; ++i)
    {
        my_vector.push_back(2*i);
    }

    // ------------------------------------- 3
    std::cout << "size : " << my_vector.size() << std::endl;

    // ------------------------------------- 4
    for(size_t i=0; i<my_vector.size(); ++i)
        std::cout << my_vector[i] << " ";
    std::cout << std::endl;

    // ------------------------------------- 5
    std::cout << "size of an element   : " << sizeof(my_vector[0]) << " bites" << std::endl;
    for(size_t i=0; i<5; ++i)
        std::cout << "address of element " << i << " : " << &my_vector[i] << std::endl;

    // ------------------------------------- 6
    my_vector.pop_back();
    std::cout << "new size : " << my_vector.size() << std::endl;

    // ------------------------------------- 7
    my_vector.clear();
    std::cout << "new size : " << my_vector.size() << std::endl;

    return 0;
}