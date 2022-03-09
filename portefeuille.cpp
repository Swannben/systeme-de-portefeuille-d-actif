#include "portefeuille.hpp"
#include <iostream>
#include "actif.hpp"
using namespace std;


Portefeuille::Portefeuille(int capacite /*= 10*/) {
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
double Portefeuille::achatActif(string nom,int quantite,double prix) {
    int i = 0;
    while ( i < _nba-1 && _actifs[i].getNom()!=nom) {
        i++;
    }
    if (this->_actifs[i].getNom() == nom) {
        this->_actifs[i].achat(quantite, prix);
    }
    else if (this->_nba!=_capacite) {
        this->_nba++;
        this->_actifs[this->_nba-1] = Actif(nom, quantite, prix);

    }
    else {
        redimensionneTableauActifs(_capacite*2);
        this->_nba++;
        this->_actifs[this->_nba-1] = Actif(nom, quantite, prix);
}
    return  _actifs[i].getPrixRevientUnitaire() * quantite;;
}
double Portefeuille::venteActif(string nom,int quantite,double prix) {
    int i = 0;
    double prixTotalVendu = quantite * prix;
    
    while (i < _capacite && this->_actifs[i].getNom() != nom) { //parcours le tableau d'actif  dans le portefeuille
        i++;
    }
    
    if (_actifs[i].getNom() == nom) {
        prixTotalVendu = _actifs[i].getPrixRevientUnitaire() * quantite;
        if (_actifs[i].getQuantite() > quantite) {
            _actifs[i].vente(quantite,prix);
        }
        else if (_actifs[i].getQuantite() == quantite) {
            _actifs[i].vente(quantite);
            this->_actifs[i] = this->_actifs[this->_nba-1];
            this->_actifs[this->_nba-1] = Actif();
            _nba--;
            if (_nba < _capacite / 2) {
                redimensionneTableauActifs(_nba);
            }

        }
        else { 
            cout << "vous essayez de vendre plus d'actifs que vous en avez voila la quantite que vous avez " << _actifs[i].getQuantite() << endl;
        }
    }
    else {
        cout << " il n'y a pas d'actif portant ce nom";

    }
    return prixTotalVendu;

}

double Portefeuille::liquiderActif(string nom, double prix) {

    for(int i = 0; i < this->_capacite; i++)
    {
        if(_actifs[i].getNom() == nom)
        {
            return venteActif(nom, _actifs[i].getQuantite(), prix);
        }
    }

    cout << "Vous ne pouvez pas liquider un actif que vous n'avez pas dans votre portefeuille" << endl;

    return -1;
}

void Portefeuille::redimensionneTableauActifs(int nouvCap) {
    Actif* newTab = new Actif[nouvCap];
    copy(&_actifs[0], &_actifs[min(_nba,nouvCap)-1], &newTab[0]);
    _capacite = nouvCap;
    std::swap(_actifs, newTab);
    delete(&newTab);
}

void Portefeuille::afficher() {
    cout << _nba << "\n";
    cout << _capacite << "\n";
    int i = 0;
    while(i < _nba) {
        _actifs[i].afficher();
        i++;
    }
}