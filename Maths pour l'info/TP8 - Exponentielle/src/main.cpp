#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>
#include <chrono>
#include <functional>
#include <string>



template<typename T>
constexpr T factorial(const unsigned int n)
{
    return (n == 0) ? 1 : static_cast<T>(n) * factorial<T>(n-1);
}

template<typename T>
T taylor(const T &x)
{
    T save = 1;
    T sum = 1;
    T a = std::abs(x);
    for (int n = 0; n < 40; n++)
    {
        save *= a / (n + 1);
        sum += save;
    }
    return (x >= 0) ? sum : T(1)/sum;
}



// exp(x) = 1 + x(  1 + x/2 ( 1 + x/3 ( 1 + ..) ) )
template<typename T>
T horner(const T &x)
{
    T sum = 1;
    T a = std::abs(x);
    for (int n = 12; n > 0; n--)
    {
        sum = 1 + sum * a/n;
    }
    return (x >= 0) ? sum : T(1)/sum;
}



template<typename T>
T reduced_horner(const T &x)
{
    T k = floor(x/M_LN2 - M_LN2/2) + 1;
    T r = x - k * M_LN2;
    T result = 0;
    return result = horner(r) * pow(2,k);
}


// https://nic.schraudolph.org/pubs/Schraudolph99.pdf
double exp_fast(const double &x){

    long int y = ((long int) (1512775 * x + 1072632447)) << 32;

    return * ( double * ) & (y);
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
    const int max_range_double = 10; //709; // exp(x) should fit in a double
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
        const volatile double value = taylor(distrib(generator));
    }
    elapsed = std::chrono::system_clock::now() - start;
    std::chrono::duration<double> elapsed_taylor = elapsed;

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

    double precision_cmath = 0;
    double precision_taylor = test_precision(taylor<double>, seed, nb_runs, max_range_double);
    double precision_horner = test_precision(horner<double>, seed, nb_runs, max_range_double);
    double precision_reduced_horner = test_precision(reduced_horner<double>, seed, nb_runs, max_range_double);
    double precision_fast   = test_precision(exp_fast, seed, nb_runs, max_range_double);


    //////////////////////////////////////////////////////////////
    // print results

    print_data("cmath     ", precision_cmath,  (elapsed_cmath  - elapsed_empty).count());
    print_data("taylor    ", precision_taylor, (elapsed_taylor - elapsed_empty).count());
    print_data("horner    ", precision_horner, (elapsed_horner - elapsed_empty).count());
    print_data("red horner", precision_reduced_horner, (elapsed_reduced_horner - elapsed_empty).count());
    print_data("fast      ", precision_fast,   (elapsed_fast   - elapsed_empty).count());
    std::cout << std::endl;



    return 0;
}

