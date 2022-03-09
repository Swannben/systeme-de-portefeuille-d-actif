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
    while ( i < _nba && _actifs[i].getNom()!=nom) {
        i++;
    }
    if (_actifs[i].getNom() == nom) {
        _actifs[i].achat(quantite, prix);
    }
    else if (_nba!=_capacite) {
        
        _actifs[_nba] = Actif(nom, quantite, prix);
        _nba++;
    }
    else {
        redimensionneTableauActifs(_capacite * 2);
        _nba++;
        _actifs[_nba-1] = Actif(nom, quantite, prix);
    }
}
double Portefeuille::venteActif(string nom,int quantite,double prix) {
    int i = 0;
    while (i < _capacite && _actifs[i].getNom() != nom) {
        i++;
    }
    if (_actifs[i].getNom() == nom) {
        if (_actifs[i].getQuantite() > quantite) {
            _actifs[i].vente(quantite);
        }
        else {
            _actifs[i]=_actifs[_nba];
            _actifs[_nba] = Actif();
        }
    }
    else {
        cout << " il n'y a pas d'actif portant ce nom";
    }
}

void Portefeuille::redimensionneTableauActifs(int nouvCap) {
    Actif* newTab = new Actif[nouvCap];
    copy(&_actifs[0], &_actifs[min(_nba,nouvCap)-1], &newTab[0]);
    _capacite = nouvCap;
    std::swap(_actifs, newTab);
    delete(&newTab);
}
