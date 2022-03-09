#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "actif.hpp"
#include "portefeuille.hpp"

using namespace std;

int main()
{
    Portefeuille* portefeuille = new Portefeuille(1);
    Actif* actif1 = new Actif("actif1", 10, 8.4);
    Actif* actif2 = new Actif("actif2", 20, 9.9);
    Actif* actif3 = new Actif("actif3", 13, 12.4);
    Actif* actif4 = new Actif("actif4", 20, 4.53);
    Actif* actif5 = new Actif("actif5", 15, 10.5);
    
    cout << "1: Achat d'un actif\n2: Vente d'un actif\n3: Liquidation totale d'un actif\n4: Liquidation totale du portefeuille\n5: Affichage caracteristiques portefeuille\n";
     int menu;
     cin>>menu;
     
     switch ( menu )
      {
         case 1:
            cout << "\nAchat d'un actif";
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

            break;
         case 2:
            cout << "\nVente d'un actif";
            portefeuille->afficher();
            string nomActifVente;
            double prixVente;
            int quantiteVente;
            cin >> nomActifVente;
            cin >> quantiteVente;
            cin >> prixVente;
            portefeuille->venteActif(nomActifVente, quantiteVente, prixVente);
            break;
        case 3:
            cout << "\n";
            break;
        case 4:
            cout << "\naurevoir";
            break;
        case 5:
            cout << "\naurevoir";
            break;
         default:
            cout << "\nNumero entre incorrect\n1: Achat d'un actif\n2: Vente d'un actif\n3: Liquidation totale d'un actif\n4: Liquidation totale du portefeuille\n5: Affichage caracteristiques portefeuille\n";
      }
    return EXIT_SUCCESS;
}