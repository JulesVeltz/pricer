#include <iostream>
#include "options.hpp"
#include "math.hpp"
#include <array>
#include <vector>
#include <cmath>


using namespace std;

Option::Option(double maturity, double sigma, double spot, double strike, double rrf) : m_maturity(maturity), m_sigma(sigma), m_S_0(spot), m_K(strike), m_r(rrf)
{
}

void Option::afficherEtats() const
{
    cout << "maturity: " << m_maturity << endl;
    cout << "sigma: "<< m_sigma << endl;
    cout << "S_0: " << m_S_0 << endl;
}


double Option::pricer_BS(int t)
{
    double d1;
    double d2;

    d1 = (log(m_S_0/m_K) + (m_r + 0.5*m_sigma*m_sigma) * (m_maturity- t))/(m_sigma * sqrt(m_maturity - t));

    d2 = d1 - m_sigma * sqrt(m_maturity - t);

    return N(d1) * m_S_0 - N(d2) * m_K * exp(-m_r * (m_maturity - t));
}


double Option::pricer_binomial(int n)
{
    double dt{t/n};
    double u{exp(m_sigma*sqrt(m_maturity/n))};
    double d{1/u};
    double p{exp(m_r*dt)* -d / (u-d)};
    vector<double> S{};
    S.push_back(m_S_0*pow(d,n));
    cout<< "S: " << S[0] << endl;
    for(auto i{1}; i < n+1; ++i)
    {
        S.push_back(S[i-1]*u/d);

    }

    vector<double> C{};
    for(auto i{0}; i < n+1; ++i)
    {
        C.push_back(max(0,S[j] - m_K));

    }

    return 0;

}