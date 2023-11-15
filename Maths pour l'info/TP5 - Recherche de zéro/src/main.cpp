#include <iostream>
#include <iomanip>
#include <functional>
#include <cmath> // M.pi
#include <numbers> // std::number::pi_v<double> si C++ 20


double dichotomy(std::function<double(const double&)> &f, 
                  double lowerBound, 
                  double upperBound, 
                  const unsigned int nbIterations){
    double mid = (lowerBound + upperBound)*0.5;
    for (unsigned int i = 0; i < nbIterations+1; i++)
    {
        mid = (lowerBound + upperBound)*0.5;
        if (f(lowerBound)*f(mid) < 0)
            upperBound = mid;
        else
            lowerBound = mid;
    }
    
    return mid;
}

unsigned int dichotomyNbIteration(const double &lowerBound, const double &upperBound, const double &precision){
    return ((log((upperBound-lowerBound)/precision))/log(2))-1;
}


double Newton(std::function<double(const double&)> &f, 
              std::function<double(const double&)> &derivative, 
              const double &input,
              const double &threshold,
              int &maxIterations) // ref just to get back the number of iterations
{
    double sol = input;
    int i = 0;
    while (std::abs(f(sol)) > threshold && i < maxIterations)
    {
        sol -= f(sol)/derivative(sol);
        i++;
    }
    return sol;
}

void mainDichotomy()
{
    std::function<double(const double&)> f = [](const double&x){return std::cos(x) - 2*x;};
    const double precision = 1.0e-7;
    const unsigned int nbIterations = dichotomyNbIteration(-std::numbers::pi_v<double>,std::numbers::pi_v<double>,precision);

    std::cout << "requested precision  : " << precision << std::endl;
    std::cout << "suggested iterations : " << nbIterations << std::endl;
    double root = dichotomy(f,-std::numbers::pi_v<double>,std::numbers::pi_v<double>,nbIterations);
    std::cout << "dichotomy            : " << root << std::endl;
    std::cout << "f(root)              : " << f(root) << std::endl << std::endl;
}

void mainNewton()
{
    std::function<double(const double&)> f, derivative;
    f = [](const double&x){return ((std::exp(x)-1.0)/(std::exp(x)+1.0)) + (3.0/4.0) ;};
    derivative = [](const double&x){return 2.0*std::exp(x) / ((std::exp(x)+1.0)*(std::exp(x)+1.0)) ;};
    // f = [](const double&x){return cos(x) - 2*x;};
    // derivative = [](const double&x){return -sin(x) - 2;};

    const double precision = 1.0e-7;
    int maxIterations = 20;
    const double x = 0.0;

    std::cout << "requested precision  : " << precision << std::endl;
    std::cout << "input estimattion    : " << x << std::endl;
    double root = Newton(f,derivative,x,precision,maxIterations);
    std::cout << "Newton               : " << root << std::endl;
    std::cout << "f(root)              : " << f(root) << std::endl;
    std::cout << "nb iterations        : " << maxIterations << std::endl;
}


int main()
{
    mainDichotomy();

    mainNewton();

    return 0;
}

