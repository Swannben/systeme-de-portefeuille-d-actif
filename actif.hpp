#pragma once
#include<string>

class Actif {
    private:
        int id;
        string nom;
        double prixRevientUnitaire;
        int quantite;
        static int idAttribue;
    public:
        Actif(string, int, double);
        Actif(const Actif&);

};