#include <iostream>
#include <cmath>

#include "curve.hpp"



using namespace std;

Curve::Curve(vector<double> existing, vector<double> maturities) : m_existing(existing), m_maturities(maturities)
{
}


vector<double> Curve::make_ZC_curve()
{
    int N{m_existing.size()};
    vector<double> ZC{};
    ZC.push_back(m_existing[0]/100);

    for(int i{1}; i < N; ++i)
    {
        double past_zc{0};
        for(int j{0}; j < i; ++j)
        {
        past_zc = past_zc + m_existing[i]/(pow((1+ZC[j]),j+1));
        }
        ZC.push_back(pow((100+m_existing[i])/(100-past_zc), 1.0/(i+1)) -1 );
    }
    return ZC;
}

//linear interpolation
double Curve::interpol(vector<double> ZC_curve, double f1)
{
    double fZ1;
    double fZ2;
    double Z1;
    double Z2;
    int i {0};
    // searching for the closest maturity in ZC curve
    for(auto mat : m_maturities)
    {
        if(f1 < mat) {
            fZ1 = m_maturities[i-1];
            fZ2 = mat;
            Z1 = ZC_curve[i-1];
            Z2 = ZC_curve[i];
            break;
        }
        i++;
    }


    return ((f1 - fZ1) * Z2 + (fZ2-f1) * Z1)/(fZ2-fZ1);
}