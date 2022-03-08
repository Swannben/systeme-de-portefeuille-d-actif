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
    delete _actifs;
}
void Portefeuille::achatActif(string nom,int quantite,double prix) {
    int i = 0;
    while ( i < _capacite && _actifs[i].getNom()!=nom) {
        i++;
    }
    if (_actifs[i].getNom() == nom) {
        _actifs[i].achat(quantite, prix);
    }
    else if (_nba!=_capacite) {
        _nba++;
        _actifs[_nba] = Actif(nom, quantite, prix);
    }
    else {
        _capacite++;
        _nba++;
        _actifs[_nba] = Actif(nom, quantite, prix);
    }
}
<<<<<<< HEAD
double Portefeuille::venteActif(string nom,int quantite,double prix) {
    int i = 0;
    while (i < _capacite && _actifs[i].getNom() != nom) {
        i++;
    }
    if (_actifs[i].getNom() == nom) {
        if (_actifs[i].getQuantite() > quantite) {
            _actifs[i].vente(quantite, prix);
        }
        else {
            _actifs[i]=_actifs[_nba];
            _actifs[_nba] = Actif();
        }
    }
    else {
        cout << " il n'y a pas d'actif portant ce nom";
    }
=======
double Portefeuille::venteActif(string,int,double) {
    return 3;
>>>>>>> 152e80fc86858669e05845554611558767c4cd4a
}

void Portefeuille::redimensionneTableauActifs(int nouvCap) {
    Actif* newTab = new Actif[nouvCap];
    copy(&_actifs[0], &_actifs[min(_nba,nouvCap)-1], &newTab[0]);
    std::swap(_actifs, newTab);
    delete(newTab);
}
