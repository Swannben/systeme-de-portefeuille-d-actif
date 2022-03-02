#pragma once
#include<string>

class Actif {
    private:
        int _id;
        string _nom;
        double _prixRevientUnitaire;
        int _quantite;
        static int _idAttribue;
    public:
        Actif(string, int, double);
        Actif(const Actif&);
        ~Actif();
        void setId(int id);
        void setNom(string nom);
        void setIdAttribue(int idA);
        void achat(int quantite, double prix = 0);
        void vente(int quantite, double prix = 0);


};