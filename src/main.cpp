#include <iostream>
#include "call.hpp"
#include "put.hpp"

using namespace std;

int main()
{
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

    return 0;
}