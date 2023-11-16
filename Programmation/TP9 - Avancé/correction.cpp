#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


// g++ -Wall -O2 -std=c++14 main.cpp



///////////////////////////////////////////////////
/// ex1
template<typename T>
constexpr int sgn(const T x)
noexcept
{
  return x > static_cast<T>(0) ? 1 : ( x < static_cast<T>(0) ? -1 : 0 );
}

template<typename T>
constexpr
T my_abs(const T x)
noexcept
{
  return x < static_cast<T>(0) ? -x : x;
}


///////////////////////////////////////////////////
/// ex2
double pow1(const double &x, const unsigned int n)
{
  if(n==0) return 1.0;
  else return x * pow1(x,n-1);
}

template<typename T>
T pow2(const T &x, const unsigned int n)
{
  if(n==0) return static_cast<T>(1);
  else return x * pow2<T>(x,n-1);
}

template <typename T>
constexpr T pow3(const T &x, const unsigned int n){
  return (n==0) ? static_cast<T>(1) : x * pow3<T>(x, n-1);
}

constexpr unsigned int fact(const unsigned int n){
  return (n == 0) ? 1 : n * fact(n-1);
}


///////////////////////////////////////////////////
/// ex3
template<typename T>
constexpr
T product(const T &v) {
  return v;
}

template<typename T, typename... Args>
constexpr
T product(const T &first, Args... args) {
  return first * product(args...);
}


///////////////////////////////////////////////////
/// ex4
template<typename T>
T multVec1(const std::vector<T> &vec){
  T res = static_cast<T>(1);
  for(const auto &v : vec)
    res *= v;

  return res;
}

template<typename T>
T multVec2(const std::vector<T> &vec){
  T res = static_cast<T>(1);
  std::for_each(vec.begin(), vec.end(), [&res] (const T &v){res *= v;} );
  return res;
}

template<typename T>
T multVec3(const std::vector<T> &vec){
  return std::accumulate(vec.begin(), vec.end(), static_cast<T>(1), std::multiplies<T>());
}

template<typename T>
std::vector<T> generateVector(const unsigned int size){
  std::vector<T> vec(size);
  T value = static_cast<T>(1);
  std::generate(vec.begin(), vec.end(), [&value] { return value++; });
  return vec;
}




///////////////////////////////////////////////////
int main(){

  // exo1
  std::cout << "Exo1 ------------------------- " << std::endl;
  static_assert(sgn(-5) == -1, "test of sgn at compile time");
  std::cout << "my_abs(-6)   = " << my_abs(-6) << std::endl;
  std::cout << "my_abs(-6.5) = " << my_abs(-6.5) << std::endl;
  std::cout << "my_abs(-0)   = " << my_abs(-0) << std::endl;
  std::cout << "my_abs(42.0) = " << my_abs(42.0) << std::endl;
  static_assert(my_abs(-5) == 5, "test of ’my_abs’ at compile time");

  // exo2
  std::cout << std::endl << "Exo2 ------------------------- " << std::endl;
  std::cout << "pow1(5,3) = " << pow1(5,3) << std::endl;
  std::cout << "pow2(5,3) = " << pow2(5,3) << std::endl;
  std::cout << "pow3(5,3) = " << pow3(5,3) << std::endl;
  static_assert(pow3(5,3) == 125, "test of ’pow3’ at compile time");
  static_assert(fact(5) == 120, "test of ’fact’ at compile time");

  // exo3
  std::cout << std::endl << "Exo3 ------------------------- " << std::endl;
  std::cout << "product(5,5,5)     = " << product(5,5,5) << std::endl;
  std::cout << "product(1,2,3,4,5) = " << product(1,2,3,4,5) << std::endl;
  static_assert(product(5,5,5) == 125, "test of 'product' at compile time");
  constexpr auto res = product<double>(1,2.333333f,3.5f,4,5);
  std::cout << "product(1,2.333333f,3.5f,4,5) = " << res 
            << "  -- with type : " << typeid(res).name() << std::endl;

  // exo4
  std::cout << std::endl << "Exo4 ------------------------- " << std::endl;
  std::cout << "vector initialisation : ";
  std::vector<int> vec1 = {1,2,3,4,5};
  for(const auto & v : vec1)
    std::cout << v << " ";
  std::cout << std::endl;

  std::cout << "multVec1(vec1) = " << multVec1(vec1) << std::endl;
  std::cout << "multVec2(vec1) = " << multVec2(vec1) << std::endl;
  std::cout << "multVec3(vec1) = " << multVec3(vec1) << std::endl;

  std::vector<int> vec2 = generateVector<int>(20);
  std::cout << "generate a bigger vector with tab[i]=i  : ";
  for(const auto & v : vec2)
    std::cout << v << " ";
  std::cout << std::endl;


  return 0;
}