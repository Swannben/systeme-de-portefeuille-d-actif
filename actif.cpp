#include "actif.hpp"
#include <iostream>
#include <string>

using namespace std;

Actif::Actif( std::string nom, int quantite, double prixRevientUnitaire) {
	_idAttribue++;
	this->_id = _idAttribue;
	this->_prixRevientUnitaire = prixRevientUnitaire;
	this->_nom = nom;
	this->_quantite = quantite;
}
Actif::~Actif() {
}

Actif::Actif() {

}

Actif::Actif(const Actif& actif) {
	this->_id = actif.getId();
	this->_prixRevientUnitaire = actif.getPrixRevientUnitaire();
	this->_nom = actif.getNom();
	this -> _quantite =actif.getQuantite();
}
void Actif::setId(int id) {
    _id = id;
}
void Actif::setNom(string nom) {
    _nom = nom;
}

void Actif::setIdAttribue(int idA) {
    _idAttribue = idA;
}


void Actif::achat(int quantite, double prix = 0) {
    if (prix == 0) {
        prix = this-> _prixRevientUnitaire;
    }
    
    this->_quantite += quantite;
    
    this->_prixRevientUnitaire = prix;
}

void Actif::vente(int quantite, double prix = 0) {
    if (prix == 0) {
        prix = this-> _prixRevientUnitaire;
    }
    
    int oldQuantite = this->_quantite;
    
    if (oldQuantite - quantite > 0) {
        this->_quantite -= quantite;
    }
    else {
        cout << "Quantité insuffisante pour vendre";
    }
    
    this->_prixRevientUnitaire = prix;
}

void Actif::afficher() {
    cout << "ID" << this->_id;
    cout << "Nom" << this->_nom;
    cout << "Prix de revient unitaire" << this->_prixRevientUnitaire;
    cout << "Quantite" << this->_quantite;
}