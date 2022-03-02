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
        void SetId(int id);
        void SetNom(string nom);
        void SetIdAttribue(int idA);

};