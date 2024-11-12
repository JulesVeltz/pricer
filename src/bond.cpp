#include <iostream>
#include <cmath>

#include "bond.hpp"
#include "curve.hpp"
#include "math.hpp"

using namespace std;

Bond::Bond(Curve curve_zc, double maturity, double coupon) : m_curve(curve_zc), m_maturity(maturity), m_coupon(coupon)
{
}

double Bond ::price()
{
    double price{0.0};
    int final{0};
    int i{0};
    vector<double> courbe_zc = m_curve.make_ZC_curve();
    vector<double> list_coupon_date{(*this).make_coupon_date_list()};

 for (double coupon_date : list_coupon_date) {

        if (coupon_date == m_maturity)
        {
            final = 1;
        }

        if (courbe_zc[i] == coupon_date)
        {
            price += (100*final + m_coupon)/pow(1+courbe_zc[i], coupon_date);
        }
        else
        {
            price += (100*final + m_coupon)/pow(1+(m_curve.interpol(courbe_zc,list_coupon_date[i])), coupon_date);
        }
        i++;
    }

    return price;
}

vector <double> Bond :: make_coupon_date_list()
{
    double coupon_date { m_maturity - trunc(m_maturity)};
    vector <double> list_coupon_date;
    for (int i{0}; i < trunc(m_maturity) + 1; i++)
    {
        list_coupon_date.push_back(coupon_date + i);
    }
    return list_coupon_date;
}

double Bond :: price_market(double yield)
{
    double ran_coupon{m_maturity - trunc(m_maturity)};
    //runed coupon
    double price{(m_coupon*ran_coupon)};
    for (int i{1}; i < trunc(m_maturity)+1; i++)
    {
        price += (m_coupon) / pow((1 + yield/100),i);
    }
    //final refund
    price += 100/pow((1+yield/100), trunc(m_maturity));
    return price;
}