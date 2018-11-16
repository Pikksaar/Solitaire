#include <iostream>
#include <iomanip>

#include <string.h>
#include <ctime>
#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Pile.h"

#include "KlondikeOne.h"

#include "Player.h"

#define TABLEAUS 7

using namespace std;

Player player;
KlondikeOne game;
Deck deck;

Pile foundations[4];
Pile tableaus[7];

void moveCards(Pile&);
void moveCards(Pile&, Pile&);
void moveCards(Pile&, Pile&, int);

void fromDeckToFoundation(Pile&);
void fromDeckToTableau(Pile&);


int main(){

    deck.shuffleDeck();

    for (int i = 0; i < TABLEAUS; i++){
        for (int j = 0; j < i+1; j++){
            tableaus[i].addCard(&(deck.dealCard()));
            tableaus[i].getCard(j).setRevealed(false);
        }
    }

    for (Pile tableau : tableaus){
        tableau.revealLast();
    }

    int choice;

    while (!game.gameWon(foundations[0], foundations[1], foundations[2], foundations[3])){
        game.drawBoard(deck, tableaus, foundations);

        game.askAction();
        cin >> choice;

        int fromPile, toPile, cards;
        switch(choice){
            case 1:
                deck.getNextCard();
                break;
            case 2:
                cin >> toPile;
                player.fromDeckToTableau(deck, tableaus[toPile-1]);
                break;
            case 3:
                cin >> toPile;
                player.fromDeckToFoundation(deck, foundations[toPile-1]);
                break;
            case 4:
                cin >> fromPile >> toPile >> cards;

                if (cards > tableaus[fromPile-1].getSize()){
                    cout << "That's not a legal move!" << endl;
                    break;
                }

                player.moveCards(tableaus[fromPile-1], tableaus[toPile-1], cards);
                break;
            case 5:
                cin >> fromPile >> toPile;

                if (tableaus[fromPile-1].getSize() == 0){
                    cout << "That's not a legal move!" << endl;
                    break;
                }

                player.moveCards(tableaus[fromPile-1], foundations[toPile-1]);
                break;
            default:
                cout << "Choose one of the given options!" << endl;
                break;
        }
        cout << "\n\n";
    }
    return 0;
}
