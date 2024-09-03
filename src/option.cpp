#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

#include "option.hpp"
#include "math.hpp"


using namespace std;

Option::Option(double maturity, double sigma, double spot, double strike, double rrf, string style) : m_maturity(maturity), m_sigma(sigma), m_S_0(spot), m_K(strike), m_r(rrf), m_style(style)
{
}

double Option::bs(double d1, double d2, int t)
{
    return 0.0;
}


double Option::pricer_BS(int t)
{
    double d1;
    double d2;

    d1 = (log(m_S_0/m_K) + (m_r + 0.5*m_sigma*m_sigma) * (m_maturity- t))/(m_sigma * sqrt(m_maturity - t));

    d2 = d1 - m_sigma * sqrt(m_maturity - t);


    return bs(d1,d2,t);
}


void Option::payoff(const std::vector<double>& S, std::vector<double>& C, int n)
{
}

double Option::pricer_binomial(int n)
{
    //initialisation
    double dt{m_maturity/n};
    double u{exp(m_sigma*sqrt(dt))};
    double d{1/u};
    double p{(exp(m_r*dt) -d )/(u-d)};

    if (dt > m_sigma*m_sigma/(m_r*m_r)) {
        cout << "dt not small enought, a.k.a n must be greater"<< "\n";
    }
    if (p<0) {
        cout << "p est inférieur à 0" << "\n";
        cout << p << "\n";
    }

    // Construction de l'arbre (dernier noeud)
    vector<double> S{};
    S.push_back(m_S_0*pow(d,n));
    for(auto i{1}; i < n+1; ++i)
    {
        S.push_back(S[i-1]*u/d);

    }

    // Calcul du Payoff de chaque noeud final en fonction du type de l'Option
    vector<double> C{};
    payoff(S,C, n);

    // Calcul de la valeur binomial du time d'avant pour arriver à t=0
    for(auto i{n}; i > 0; --i)
    {
        for (auto j{0}; j < i ; j++)
        {
            C[j] = exp(-m_r * dt) * ( p * C[j+1] + (1-p) * C[j]);
            if (m_style == "American"){
                C[j] = max(C[j], S[j] - m_K);
            }
        }
    }

    return C[0];

}