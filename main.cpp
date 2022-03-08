#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "actif.hpp"
#include "portefeuille.hpp"

using namespace std;

int main()
{
    Portefeuille* portefeuille = new Portefeuille();
    Actif* actif1 = new Actif("Bluby", 3, 3.4);
    actif1->afficher();
    
    cout << "1: Achat d'un actif\n2: Vente d'un actif\n3: Liquidation totale d'un actif\n4: Liquidation totale du portefeuille\n5: Affichage caracteristiques portefeuille\n";
     int menu;
     cin>>menu;
     
     switch ( menu )
      {
         case 1:
            cout << "\nAchat d'un actif";
            double prix;
            int quantiteAchat;
            cin >> prix;
            cin >> quantiteAchat;
            break;
         case 2:
            cout << "\nVente d'un actif";
            int quantiteVente;
            int id;
            
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