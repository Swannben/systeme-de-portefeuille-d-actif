#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "actif.hpp"
#include "portefeuille.hpp"

using namespace std;

int main()
{
    cout << "1: Achat d'un actif";
    cout << "2: Vente d'un actif";
    cout << "3: Liquidation totale d'un actif";
    cout << "4: Liquidation totale du portefeuille";
    cout << "5: Affichage caractéristiques portefeuille";
    
    return EXIT_SUCCESS;
}