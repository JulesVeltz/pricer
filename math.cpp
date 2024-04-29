#include <iostream>
#include <cmath>
#include <array>
#include "math.hpp"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif


using namespace std;

// An approximation to the cumulative distribution function
// for the standard normal distribution
// Note: This is a recursive function
double N(const double& x) {
    // Abramowitz & Stegun's (1964) approximation !!

    /* Refer to https://www.ijser.org/researchpaper/Approximations-to-Standard-Normal-Distribution-Function.pdf
       for potentially more efficient approximations wrt M.A.E. and corresponding z-score */
    double k = 1.0/(1.0 + 0.2316419*x);
    double k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));

    if (x >= 0.0) {
        return (1.0 - (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x) * k_sum);
    } else {
        return 1.0 - N(-x);
    }
}