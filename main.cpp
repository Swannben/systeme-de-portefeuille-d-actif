#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "actif.hpp"
#include "portefeuille.hpp"

using namespace std;


Portefeuille* portefeuille = new Portefeuille(10);

void AchatActif() {
    string nomActifAchat;
    double prixAchat;
    int quantiteAchat;
    double valeurAchat;
    cout << "Nom de l'actif que vous souhaitez acheter : \n";
    cin >> nomActifAchat;
    cout << "Quantite que vous souhaitez acheter : \n";
    cin >> quantiteAchat;
    cout << "prix d'achat unitaire \n";
    cin >> prixAchat;
    valeurAchat=portefeuille->achatActif(nomActifAchat, quantiteAchat, prixAchat);
    cout << "vous avez achete pour " << valeurAchat << " de " << nomActifAchat<< endl;
}

void VenteActif() {

    portefeuille->afficher();
    string nomActifVente;
    double prixVente, valeurVente;
    int quantiteVente;

    cout << "Nom de l'actif que vous souhaitez vendre : \n";
    cin >> nomActifVente;
    cout << "Quantite que vous souhaitez vendre : \n";
    cin >> quantiteVente;
    cout << "prix de vente unitaire \n";
    cin >> prixVente;
    valeurVente=portefeuille->venteActif(nomActifVente, quantiteVente, prixVente);
    cout << "vous avez vendu pour " << valeurVente << " de " << nomActifVente << endl;
}

void LiquidAct() {
    string nomActifLiquid;
    double prixActifLiquid;
    portefeuille->afficher();
    cout << "Nom de l'actif que vous souhaitez liquider\n";
    cin >> nomActifLiquid;
    cout << "Prix de l'actif que vous souhaitez liquider\n";
    cin >> prixActifLiquid;
    portefeuille->liquiderActif(nomActifLiquid, prixActifLiquid);

}

void LiquidPort() {
    int i = 0;
    while(i < portefeuille->getNba() +1 ) {
        portefeuille->liquiderActif(portefeuille->getActifs()[i].getNom(), portefeuille->getActifs()[i].getPrixRevientUnitaire());
        i++;
    }
}


int main()
{
    bool continuer = true;
    
    cout << "\n1: Achat d'un actif\n2: Vente d'un actif\n3: Liquidation totale d'un actif\n4: Liquidation totale du portefeuille\n5: Affichage caracteristiques portefeuille\n6: sortir  du menu\n";
     int menu;
     cin>>menu;
     while (continuer) {
         cout << "\n1: Achat d'un actif\n2: Vente d'un actif\n3: Liquidation totale d'un actif\n4: Liquidation totale du portefeuille\n5: Affichage caracteristiques portefeuille\n";
         cin >> menu;
         switch (menu)
         {
         case 1:
             cout << "\nAchat d'un actif";
             AchatActif();
             break;
         case 2:
             cout << "\nVente d'un actif";
             VenteActif();
             break;
         case 3:
             cout << "\n liquidation totale d'un actif";
             LiquidAct();
             break;
         case 4:
             cout << "\n liquidation totale du portefeuille";
             LiquidPort();
             break;
         case 5:
             cout << "\n affichage des caracteristiques du portefeuille";
             portefeuille->afficher();
             break;
         case 6:
             continuer = false;
             break;
         default:
             cout << "\nNumero entre incorrect";
         }
     }
    return EXIT_SUCCESS;
}
