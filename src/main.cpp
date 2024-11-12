#include <iostream>
#include <cmath>
#include "call.hpp"
#include "put.hpp"
#include "curve.hpp"
#include "bond.hpp"

using namespace std;

int main()
{
    //Equity Derivatives
    // Option(double maturity, double sigma, double spot, double strike, double rrf = 0.01);
    Call call_europe(1.0, 0.2, 100.0, 95.0, 0.06);
    Put put_europe(1.0, 0.2, 100.0, 95.0, 0.06);
    Call americaine(1.0, 0.2, 100.0, 95.0, 0.06, "American");

    double call_price_bs;
    double put_price_bs;
    double call_price_binomial;
    double put_price_binomial;
    double call_price_us;

    call_price_bs = call_europe.pricer_BS();
    call_price_binomial = call_europe.pricer_binomial(150);

    put_price_bs = put_europe.pricer_BS();
    put_price_binomial = put_europe.pricer_binomial();

    call_price_us = americaine.pricer_binomial();

    cout << "price BS:  " << call_price_bs << " | "<< put_price_bs << "\n";
    cout << "price binomial:  " << call_price_binomial << " | " << put_price_binomial  << endl;
    cout << "call amricaine: "<< call_price_us << endl;

    // Fixed Income
    vector<double> bond_coupon{3.5, 3.0, 2.5, 2.15, 1.95, 1.90, 2.0, 2.25, 2.65, 3.20, 3.90, 4.75};
    vector<double> bond_maturities{0.5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    Curve courbe(bond_coupon,bond_maturities);

    Bond bond1(courbe, 4.5, 2);
    Bond bond2(courbe, 9.5, 4.5);
    double price_bond_1;
    double price_bond_2;
    price_bond_1 = bond1.price();
    price_bond_2 = bond2.price();

    cout << " price bond 1: " << price_bond_1 << endl;
    cout << " price bond 2: " << price_bond_2 <<endl;

    double price_bond_market_1 {bond1.price_market(1.85)};
    double price_bond_market_2 {bond2.price_market(3.60)};
    cout << "market price bond 1: " << price_bond_market_1 << endl;
    cout << "market price bond 2: " << price_bond_market_2 << endl;

    return 0;
}