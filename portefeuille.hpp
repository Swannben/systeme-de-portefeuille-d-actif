#pragma once
#include "actif.hpp"
class Portefeuille {
    private:
        int nba;
        int capacite;
        Actif* actifs;
        void redimensionneTableauActifs(int nouvelleCapacite);
    public: 
        Portefeuille(int = 1);
        Portefeuille(const Portefeuille&);
        ~Portefeuille();
        void achatActif(string,int,double);
        double venteActif(string,int,double);

    
    
};