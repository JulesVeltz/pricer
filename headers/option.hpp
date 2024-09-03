#include <string>
#include <vector>

#ifndef __OPTION__
    #define __OPTION__

    class Option
    {
        public:

        Option() = default; //constructeur
        Option(double maturity, double sigma, double spot, double strike, double rrf = 0.01, std::string style = "European");
        void afficherEtats() const;
        double pricer_BS(int t = 0);
        double pricer_binomial(int n = 262);
        virtual double bs(double d1, double d2, int t);
        virtual void payoff(const std::vector<double>& S, std::vector<double>& C, int n);

        protected:

        double m_maturity;
        double m_sigma;
        double m_S_0;
        double m_K;
        double m_r;
        std::string m_style;
        std::string m_type{"no type"};

    };

#endif