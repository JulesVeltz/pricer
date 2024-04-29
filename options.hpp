#ifndef __OPTION__
    #define __OPTION__

    class Option
    {
        public:

        Option() = default; //constructeur
        Option(double maturity, double sigma, double spot, double strike, double rrf = 0.01);
        void afficherEtats() const;
        double pricer_BS(int t = 0);
        double pricer_binomial(int n=3);

        private:

        double m_maturity;
        double m_sigma;
        double m_S_0;
        double m_K;
        double m_r;

    };

#endif