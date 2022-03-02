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


Actif::Actif(const Actif& actif) {
	this->_id = actif.getId();
	this->_prixRevientUnitaire = actif.getPrixRevientUnitaire();
	this->_nom = actif.getNom();
	this -> _quantite =actif.getQuantite();
}



