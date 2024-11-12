#include "curve.hpp"
#include <string>
#include <vector>

#ifndef __BOND__
    #define __BOND__

    class Bond
    {
        public:

        Bond() = default; //constructeur
        Bond(Curve curve_zc, double maturity, double coupon);
        double price();
        std::vector <double> make_coupon_date_list();
        double price_market(double yield);

        private:
        Curve m_curve;
        double m_maturity;
        double m_coupon;

    };
#endif