#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "actif.hpp"
#include "portefeuille.hpp"

using namespace std;

int main()
{
    Portefeuille* portefeuille = new Portefeuille(10);
    Actif* actif1 = new Actif("actif1", 3, 3.4);
    Actif* actif2 = new Actif("actif2", 3, 3.4);
    Actif* actif3 = new Actif("actif3", 3, 3.4);
    Actif* actif4 = new Actif("Bluby", 3, 3.4);
    Actif* actif5 = new Actif("Bluby", 3, 3.4);

    
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
            double prixAchat;
            int quantiteAchat;
            cin >> quantiteAchat;
            break;
         case 2:
            cout << "\nVente d'un actif";
            int quantiteVente;
            int id;

            break;
        case 3:
            cout << "\n liquidation totale d'un actif";
            break;
        case 4:
            cout << "\n liquidation totale du portefeuille";
            break;
        case 5:
            cout << "\n affichage des caractéristiques du portefeuille";
            portefeuille->afficher();
            break;
         default:
            cout << "\nNumero entre incorrect\n1: Achat d'un actif\n2: Vente d'un actif\n3: Liquidation totale d'un actif\n4: Liquidation totale du portefeuille\n5: Affichage caracteristiques portefeuille\n";
      }
    return EXIT_SUCCESS;
}