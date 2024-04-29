#include <iostream>
#include "options.hpp"

using namespace std;

int main()
{
    Option europe(1.0, 0.2, 100.0, 95.0);
    double price;
    price = europe.pricer_BS();
    cout << "option price:  " << price << endl;
    europe.pricer_binomial();

    return 0;
}