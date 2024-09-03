#include "option.hpp"
#include <string>
#include <vector>

#ifndef __PUT__
    #define __PUT__

    class Put : public Option
    {
        using Option::Option;

        public:

        Put() = default; //constructeur
        Put(double maturity, double sigma, double spot, double strike, double rrf = 0.01);
        double bs(double d1, double d2, int t) override;
        void payoff(const std::vector<double>& S, std::vector<double>& C, int n) override;

        private:


    };
#endif