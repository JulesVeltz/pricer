#include <string>
#include <vector>
#include <array>

#ifndef __CURVE__
    #define __CURVE__

    class Curve
    {

        public:

        Curve() = default; //constructeur
        Curve(std::vector<double> existing, std::vector<double> maturities);
        std::vector<double> make_ZC_curve();
        double interpol(std::vector<double> ZC_curve, double f1);

        private:
        std::vector<double> m_existing;
        std::vector<double> m_maturities;

    };
#endif