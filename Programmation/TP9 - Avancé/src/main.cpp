#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


// Exercice 1
template<typename T>
constexpr int my_abs(const T x)
noexcept
{
  return x < static_cast<T>(0) ? x * static_cast<T>(-1) : x;
}

template<typename T>
constexpr int sgn(const T x)
noexcept
{
  return x > static_cast<T>(0) ? 1 : (x < static_cast<T>(0) ? -1 : 0);
}


// Exercice 2
double pow1(const double &x, const unsigned int n)
{
  return n == 0 ? 1 : x * pow1(x, n-1);
}

template<typename T>
constexpr double pow2(const T &x, const T n)
noexcept
{
  return n == static_cast<T>(0) ? 1 : x * pow2(x, n-1);
}


// Exercice 3
template<typename T>
constexpr T product(const T &var)
noexcept
{
  return var;
}

template<typename T, typename ... Args>
constexpr T product(const T& var, const Args ... args)
{
  return var * product(args ...);
}

// Exercice 4


int main()
{
  std::cout << std::endl << "Exercice 1" << std::endl;
  static_assert(sgn(0) == 0, "test of 'sng' at compile time");

  static_assert(my_abs(-12) == 12, "test of 'my_abs' at compile time");
  std::cout << "my_abs(-12)= " << my_abs(-12) << std::endl;


  std::cout << std::endl << "Exercice 2" << std::endl;
  std::cout << "pow1(2,2)= " << pow1(2, 2) << std::endl;

  static_assert(pow2(2,2) == 4, "test of 'pow2' at compile time");
  std::cout << "pow2(2,2)= " << pow2(2, 2) << std::endl;


  std::cout << std::endl << "Exercice 3" << std::endl;
  static_assert(product(1,2,3,4,5) == 120, "test of 'product' at compile time");
  static_assert(product(5,5,5) == 125, "test of 'product' at compile time");

  std::cout << "product(1,2,3,4,5)= " << product<unsigned int>(1,2,3,4,5) << std::endl;
  std::cout << "product(5,5,5)= " << product<double>(5,5,5) << std::endl;


  std::cout << std::endl << "Exercice 4" << std::endl;


  return 0;
}
