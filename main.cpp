#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "actif.hpp"
#include "portefeuille.hpp"

using namespace std;


Portefeuille* portefeuille = new Portefeuille(10);
Actif* actif1 = new Actif("actif1", 10, 8.4);
Actif* actif2 = new Actif("actif2", 20, 9.9);
Actif* actif3 = new Actif("actif3", 13, 12.4);
Actif* actif4 = new Actif("actif4", 20, 4.53);
Actif* actif5 = new Actif("actif5", 15, 10.5);

void AchatActif() {
    actif1->afficher();
    actif2->afficher();
    actif3->afficher();
    actif4->afficher();
    actif5->afficher();
    string nomActifAchat;
    double prixAchat;
    int quantiteAchat;
    cout << "Nom de l'actif que vous souhaitez acheter : \n";
    cin >> nomActifAchat;
    cout << "Quantite que vous souhaitez acheter : \n";
    cin >> quantiteAchat;
    cout << "prix d'achat unitaire (laisser 0 si prix de revient definit)";
    cin >> prixAchat;
    portefeuille->achatActif(nomActifAchat, quantiteAchat, prixAchat);
    cout << "vous avez achete pour " << quantiteAchat << " de " << nomActifAchat;
}

void VenteActif() {

    portefeuille->afficher();
    string nomActifVente;
    double prixVente;
    int quantiteVente;

    cout << "Nom de l'actif que vous souhaitez vendre : \n";
    cin >> nomActifVente;
    cout << "Quantite que vous souhaitez vendre : \n";
    cin >> quantiteVente;
    cout << "prix de vente unitaire (laisser 0 si c'est le prix de revient definit)";
    cin >> prixVente;
    portefeuille->venteActif(nomActifVente, quantiteVente, prixVente);
}

void LiquidActifByName(string nom) {
    
}
void LiquidAct() {
    string nomActifLiquid
    cout << "Nom de l'actif que vous souhaitez liquider\n";
    cin >> nomActifLiquid;
    LiquidActifByName(nomActifLiquid);

}

void LiquidPort() {

}



int main()
{
    setvbuf(stdout, nullptr, _IOFBF, 1000);
    bool continuer = true;
    
    cout << "\n1: Achat d'un actif\n2: Vente d'un actif\n3: Liquidation totale d'un actif\n4: Liquidation totale du portefeuille\n5: Affichage caracteristiques portefeuille\n";
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
         default:
             cout << "\nNumero entre incorrect";
         }
     }
    return EXIT_SUCCESS;
}
