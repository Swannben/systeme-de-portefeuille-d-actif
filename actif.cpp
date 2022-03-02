#include "actif.hpp"
#include <iostream>
#include <string>

using namespace std;


Actif::Actif(const Actif&) {

}
Actif::Actif(string nom, int quantite, double pru) {
}
Actif::~Actif() {

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
    
    
}

void Actif::vente(int quantite, double prix = 0) {
    if (prix == 0) {
        prix = this-> _prixRevientUnitaire;
    }
    
    int oldQuantite = this->_quantite;
    
    if (oldQuantite - quantite > 0) {
        this->_quantite -= quantite;
    }
    
    
}