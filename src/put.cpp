#include <iostream>
#include <string>
#include <cmath>

#include "option.hpp"
#include "put.hpp"
#include "math.hpp"

using namespace std;

Put::Put(double maturity, double sigma, double spot, double strike, double rrf) : Option(maturity,sigma,spot,strike,rrf)
{
}

double Put::bs(double d1, double d2, int t)
{
    return -N(-d1) * m_S_0 + N(-d2) * m_K * exp(-m_r * (m_maturity - t));
}

void Put::payoff(const std::vector<double>& S, std::vector<double>& C, int n)
{
    for(auto i{0}; i < n+1; ++i)
    {
            C.push_back(max(0.0, m_K - S[i]));
    }
}