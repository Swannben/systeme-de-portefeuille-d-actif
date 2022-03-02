#pragma once
#include<string>

class Actif {
    private:
        int _id;
        string _nom;
        double _prixRevientUnitaire;
        int _quantite;
        static int _idAttribue;
        Actif(const Actif&);
    public:
        Actif(string , int , double );
        int getId() const { return _id; }
        string getNom() const { return _nom; }
        double getPrixRevientUnitaire()const { return _prixRevientUnitaire; }
        int getQuantite()const { return _quantite; }
        static int getDernierIdAttribue() { return _idAttribue; }

        Actif(string, int, double);
        ~Actif();
        void SetId(int id);
        void SetNom(string nom);
        
        void SetIdAttribue(int idA);

};