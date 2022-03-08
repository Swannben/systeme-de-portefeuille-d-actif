#include "portefeuille.hpp"
#include <iostream>
#include "actif.hpp"
using namespace std;


Portefeuille::Portefeuille(int capacite = 1) {
    this->_nba = 0;
    this->_capacite = capacite;
    this->_actifs;
}
Portefeuille::Portefeuille(const Portefeuille& portefeuille) {
    this->_nba = portefeuille.getNba();
	this->_capacite = portefeuille.getCapacite();
	this->_actifs = portefeuille.getActifs();
}
Portefeuille::~Portefeuille() {
}
void Portefeuille::achatActif(string,int,double) {
}
double Portefeuille::venteActif(string,int,double) {
}

