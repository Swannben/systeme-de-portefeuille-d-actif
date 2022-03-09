#pragma once
#include "actif.hpp"

using namespace std;

class Portefeuille {
    private:
        int _nba;
        int _capacite;
        Actif* _actifs;
    public: 
        Portefeuille(int = 10);
        Portefeuille(const Portefeuille&);
        ~Portefeuille();
        void achatActif(string,int,double);
        double venteActif(string,int,double);
        int getNba() const { return _nba; }
        int getCapacite() const { return _capacite; }
        Actif* getActifs() const { return _actifs; }
        void redimensionneTableauActifs(int nouvCap);
        void afficher();
};