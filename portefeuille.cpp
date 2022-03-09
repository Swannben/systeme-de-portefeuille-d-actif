#include "portefeuille.hpp"
#include <iostream>
#include "actif.hpp"
using namespace std;


Portefeuille::Portefeuille(int capacite /*= 1*/) {
    this->_nba = 0;
    this->_capacite = capacite;
    this->_actifs = new Actif[capacite] ; 
}
Portefeuille::Portefeuille(const Portefeuille& portefeuille) {
    this->_nba = portefeuille.getNba();
	this->_capacite = portefeuille.getCapacite();
	this->_actifs = portefeuille.getActifs();
}
Portefeuille::~Portefeuille() {
    delete this->_actifs;
}
void Portefeuille::achatActif(string nom,int quantite,double prix) {
    int i = 0;
<<<<<<< HEAD
    while ( i < _nba && _actifs[i].getNom()!=nom) {
=======
    while ( i < _capacite && this->_actifs[i].getNom()!=nom) {
>>>>>>> 34bd86a4cb1c6e4bb52e22638ebd876774b6c968
        i++;
    }
    if (this->_actifs[i].getNom() == nom) {
        this->_actifs[i].achat(quantite, prix);
    }
<<<<<<< HEAD
    else if (_nba!=_capacite) {
        
        _actifs[_nba] = Actif(nom, quantite, prix);
        _nba++;
    }
    else {
        redimensionneTableauActifs(_capacite * 2);
        _nba++;
        _actifs[_nba-1] = Actif(nom, quantite, prix);
=======
    else if (this->_nba!=_capacite) {
        this->_nba++;
        this->_actifs[this->_nba] = Actif(nom, quantite, prix);
    }
    else {
        _capacite++;
        this->_nba++;
        this->_actifs[this->_nba] = Actif(nom, quantite, prix);
>>>>>>> 34bd86a4cb1c6e4bb52e22638ebd876774b6c968
    }
}
double Portefeuille::venteActif(string nom,int quantite,double prix) {
    int i = 0;
    double prixTotalVendu = quantite * prix;
    while (i < _capacite && this->_actifs[i].getNom() != nom) { //parcours le tableau d'actif  dans le portefeuille
        i++;
    

    if (_actifs[i].getNom() == nom) {
        if (_actifs[i].getQuantite() > quantite) {
            _actifs[i].vente(quantite);
        }
        else {
            prixTotalVendu = prix*_actifs[i].getQuantite();
            this->_actifs[i]=this->_actifs[this->_nba];
            this->_actifs[this->_nba] = Actif();   
            cout << "Vous avez vendu cet actif pour une quantité de " << _actifs[i].getQuantite() << endl;
        }
    }
    else {
        cout << " il n'y a pas d'actif portant ce nom";

    }
    }
    return prixTotalVendu;

}
void Portefeuille::redimensionneTableauActifs(int nouvCap) {
    Actif* newTab = new Actif[nouvCap];
    copy(&_actifs[0], &_actifs[min(_nba,nouvCap)-1], &newTab[0]);
    _capacite = nouvCap;
    std::swap(_actifs, newTab);
    delete(&newTab);
}
