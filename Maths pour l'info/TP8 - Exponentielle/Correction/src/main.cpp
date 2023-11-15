#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>
#include <chrono>
#include <functional>
#include <string>



template<typename T>
constexpr T factorial(const unsigned int n){
    return (n == 0) ? 1 : static_cast<T>(n) * factorial<T>(n-1);
}


/*
Pseudocode
```
Taylor(x,nbIter)

  result = 1 
  pow_x = 1
  factoriel_n = 1

  pour i=1 à nbITer
    pow_x *= x
    factoriel_n *= i
    result += pow_x / factoriel_n

  renvoyer result
```
complexité :
- ici O(n)
- 
*/


template<typename T>
T taylor_loop(const T &x){

    T x0 = std::abs(x);

    T result = static_cast<T>(0);
    T value  = static_cast<T>(1);

    for(unsigned int n=0; n<40; ++n){
        result += value;
        value  *= x0 / static_cast<T>(n+1);
    }

    return (x>=static_cast<T>(0)) ? result : static_cast<T>(1) / result;
}


template<typename T>
constexpr T taylor_constexpr(const T &x){

    T x0 =  x >= static_cast<T>(0) ? x : -x; // abs

    T result = static_cast<T>(1) + x0;
    T pow_x  = x0;

    // 2
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(2);

    // 3
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(3);

    // 4
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(4);

    // 5
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(5);

    // 6
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(6);

    // 7
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(7);

    // 8
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(8);    

    // 9
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(9);  

    // 10
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(10);

    // 11
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(11);

    // 12
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(12);

    // 13
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(13);

    // 14
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(14);

    // 15
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(15);

    // 16
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(16);

    // 17
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(17);

    // 18
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(18);

    // 19
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(19);

    // 20
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(20);

    // 21
    pow_x  *= x0;
    result += pow_x / factorial<unsigned long>(21);


    return (x>=static_cast<T>(0)) ? result : static_cast<T>(1) / result;
}




/*
exp(x) = 1 + x ( 1 + x/2 ( 1 + x/3 ( 1 + x/4 (...) ) ) )
Pseudo code
Horner(x, nbIter = 17)
  x0 = |x|
  result = 1 + (x0 / nbIter)

  Pour i=nbIter-1, i>=1, i--
    result = 1 + (x0/i) * result

  si x >= 0 renvoyer result
  sinon renvoyer 1 / result
*/
template<typename T>
T horner(const T &x){

    // work on x>0 and keep track of its original sign
    const T x0 = std::abs(x);

    const unsigned int max_iter = 21; // (int)ceil(x0 * M_E) * 12;
    T result = static_cast<T>(1) +  (x0 / max_iter);

    for(unsigned int i=max_iter-1; i>=1; --i)
        result = static_cast<T>(1) + (x0 / i) * result;

    return (x >= 0) ? result : static_cast<T>(1) / result;
}


/*
Pseudo code
reduced_horner(x, nbIter = 14)
  x0 = |x|

  k = ceil(x0/log(2) - log(2)/2)
  r = x0 - k.log(2);

  result = 1 + (r / nbIter)

  Pour i=nbIter-1, i>=1, i--
    result = 1 + (r/i) * result

  result *= 2^k

  si x >= 0 renvoyer result
  sinon renvoyer 1 / result
*/
template<typename T>
T reduced_horner(const T &x) {

    // work on x>0 and keep track of its original sign
    const T x0 = std::abs(x);
    const unsigned int k = ceil((x0 / M_LN2) - 0.5*M_LN2);
    const T r = x0 - static_cast<T>(k * M_LN2);

    const unsigned int max_iter = 14; // 14 fixed in the reduced form of horner
    T result = static_cast<T>(1) +  (r / max_iter);

    for(unsigned int i=max_iter-1; i>=1; --i)
        result = static_cast<T>(1) + (r / i) * result;

    // e(x) = e(r).2^k
    result *= (1 << k);

    return (x >= 0) ? result : static_cast<T>(1) / result;
}


// https://nic.schraudolph.org/pubs/Schraudolph99.pdf
double exp_fast(const double &x){

    long int y = ((long int) (1512775 * x + 1072632447)) << 32;

    return * ( double * ) & (y);
}


// around 0
double exp_tanh(const double &x){

    const double tanh_half = std::tanh(0.5 * tanh(x));

    return 1.0 + (2.0 * tanh_half) / (1.0 - tanh_half) ;
}


template<typename T>
T relative_error(const T& estimated, const T& expected){
    return std::abs( (estimated - expected ) / expected );
}


void print_data(const std::string &method_name, const double precision, const double time){

    std::cout << method_name 
              << " : [mean error: " << std::fixed  << std::internal << std::setw(7) << std::setprecision(4) << std::setfill('0') << precision << " % ]"
              << "\t [time: "  << std::fixed << std::setprecision(4) << time << " s]" << std::endl;
}


double test_precision(std::function<double(const double&)> f, const unsigned seed, const unsigned int nb_runs, const double range){

    std::mt19937 generator(seed);
    std::uniform_real_distribution<double> distrib(-range,range);

    long double sum = 0;
    for(unsigned int i=0; i<nb_runs; ++i){
        double x = distrib(generator);
        sum += relative_error<double>(f(x),exp(x));
    }
   
    return 100 * sum / nb_runs;
}


int main()
{
    // random setup
    const unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);

    // distribution
    const int max_range_double = 20; //709; // exp(x) should fit in a double
    std::uniform_real_distribution<double> distrib(-max_range_double,max_range_double);

    // computation options
    const unsigned int nb_runs = 1.0e7;
  
    //////////////////////////////////////////////////////////////
    // time tests

    // empty version
    generator.seed(seed);
    auto start = std::chrono::system_clock::now();
    for(unsigned int i=0; i<nb_runs; ++i){
        const volatile double value = distrib(generator);
    }
    auto elapsed = std::chrono::system_clock::now() - start;
    std::chrono::duration<double> elapsed_empty = elapsed;

    // cmath version
    generator.seed(seed);
    start = std::chrono::system_clock::now();
    for(unsigned int i=0; i<nb_runs; ++i){
        const volatile double value = exp(distrib(generator));
    }
    elapsed = std::chrono::system_clock::now() - start;
    std::chrono::duration<double> elapsed_cmath = elapsed;

    // taylor version
    generator.seed(seed);
    start = std::chrono::system_clock::now();
    for(unsigned int i=0; i<nb_runs; ++i){
        const volatile double value = taylor_constexpr<double>(distrib(generator));
    }
    elapsed = std::chrono::system_clock::now() - start;
    std::chrono::duration<double> elapsed_taylor = elapsed;

    // taylor_loop version
    generator.seed(seed);
    start = std::chrono::system_clock::now();
    for(unsigned int i=0; i<nb_runs; ++i){
        const volatile double value = taylor_loop<double>(distrib(generator));
    }
    elapsed = std::chrono::system_clock::now() - start;
    std::chrono::duration<double> elapsed_taylor2 = elapsed;

    // horner version
    generator.seed(seed);
    start = std::chrono::system_clock::now();
    for(unsigned int i=0; i<nb_runs; ++i){
        const volatile double value = horner(distrib(generator));
    }
    elapsed = std::chrono::system_clock::now() - start;
    std::chrono::duration<double> elapsed_horner = elapsed;

    // reduced horner version
    generator.seed(seed);
    start = std::chrono::system_clock::now();
    for(unsigned int i=0; i<nb_runs; ++i){
        const volatile double value = reduced_horner(distrib(generator));
    }
    elapsed = std::chrono::system_clock::now() - start;
    std::chrono::duration<double> elapsed_reduced_horner = elapsed;

    // fast version
    generator.seed(seed);
    start = std::chrono::system_clock::now();
    for(unsigned int i=0; i<nb_runs; ++i){
        const volatile double value = exp_fast(distrib(generator));
    }
    elapsed = std::chrono::system_clock::now() - start;
    std::chrono::duration<double> elapsed_fast = elapsed;



    //////////////////////////////////////////////////////////////
    // precision tests

    double precision_cmath   = 0;
    double precision_taylor  = test_precision(taylor_constexpr<double>, seed, nb_runs, max_range_double);
    double precision_taylor2 = test_precision(taylor_loop<double>, seed, nb_runs, max_range_double);
    double precision_horner  = test_precision(horner<double>, seed, nb_runs, max_range_double);
    double precision_reduced_horner = test_precision(reduced_horner<double>, seed, nb_runs, max_range_double);
    double precision_fast    = test_precision(exp_fast, seed, nb_runs, max_range_double);


    //////////////////////////////////////////////////////////////
    // print results

    print_data("cmath     ", precision_cmath,   (elapsed_cmath  - elapsed_empty).count());
    print_data("taylor    ", precision_taylor,  (elapsed_taylor - elapsed_empty).count());
    print_data("taylor2   ", precision_taylor2, (elapsed_taylor2 - elapsed_empty).count());
    print_data("horner    ", precision_horner,  (elapsed_horner - elapsed_empty).count());
    print_data("red horner", precision_reduced_horner, (elapsed_reduced_horner - elapsed_empty).count());
    print_data("fast      ", precision_fast,    (elapsed_fast   - elapsed_empty).count());
    std::cout << std::endl;



    return 0;
}

