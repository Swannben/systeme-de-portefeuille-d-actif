#include "actif.hpp"
#include <iostream>
#include<string>

using namespace std;


Actif::Actif(const Actif&) {

}
Actif::Actif(string nom, int quantite, double pru) {
    _idAttribue += 1;
}
Actif::~Actif() {

}
void Actif::SetId(int id) {
    _id = id;
}
void Actif::SetNom(string nom) {
    _nom = nom;
}

void Actif::SetIdAttribue(int idA) {
    _idAttribue = idA;
}

