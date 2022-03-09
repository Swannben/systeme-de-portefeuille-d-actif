#pragma once
#include <string>
using namespace std;
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
        Actif();
        int getId() const { return _id; }
        string getNom() const { return _nom; }
        double getPrixRevientUnitaire()const { return _prixRevientUnitaire; }
        int getQuantite()const { return _quantite; }
        static int getDernierIdAttribue() { return _idAttribue; }
        ~Actif();
        void setId(int id);
        void setNom(string nom);
        void setIdAttribue(int idA);
        void achat(int quantite, double prix = 0);
        void vente(int quantite, double prix = 0);
        void afficher();
        

};