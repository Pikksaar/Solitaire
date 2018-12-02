#include <iostream>
#include <iomanip>

#include <string.h>
#include <ctime>
#include <vector>
#include <typeinfo>
#include <limits>

#include "Card.h"
#include "Pile.h"
#include "DeckKlonOne.h"
#include "DeckKlonThree.h"

#include "KlondikeOne.h"
#include "KlondikeThree.h"

#include "Player.h"

#define TABLEAUS 7

using namespace std;
/*
KlondikeOne* KlondikeOne::instance = nullptr;
KlondikeThree* KlondikeThree::instance = nullptr;*/

Player player;

Deck *deck;
Game *game;

Pile foundations[4];
Pile tableaus[7];

void fillTableaus(Pile[]);
void chooseGame();
void promptChoices(int, int&, int&, int&);

int main(){
    // Choose gamemode
    chooseGame();

    // Start the table
    deck->shuffleDeck();
    fillTableaus(tableaus);

    // Game Loop
    int choice;
    while (!game->gameWon(foundations[0], foundations[1], foundations[2], foundations[3])){
        game->drawBoard(deck, tableaus, foundations);

        game->askAction();

        int fromPile=0, toPile=0, cards=0;
        bool illegalMove;
        do{
            illegalMove = false;

            cin >> choice;
            while(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                cout << "Bad entry. Enter a NUMBER: ";
                cin >> choice;
            }

            switch(choice){
                case 1:
                    deck->getNextCard();
                    break;
                case 2:
                    promptChoices(1, fromPile, toPile, cards);
                    player.fromDeckToTableau(deck, tableaus[toPile-1]);
                    break;
                case 3:
                    promptChoices(1, fromPile, toPile, cards);
                    player.fromDeckToFoundation(deck, foundations[toPile-1]);
                    break;
                case 4:
                    promptChoices(3, fromPile, toPile, cards);

                    if (cards > tableaus[fromPile-1].getSize()){
                        illegalMove = true;
                        break;
                    }

                    player.moveCards(tableaus[fromPile-1], tableaus[toPile-1], cards);
                    break;
                case 5:
                    promptChoices(2, fromPile, toPile, cards);

                    if (tableaus[fromPile-1].getSize() == 0){
                        illegalMove = true;
                        break;
                    }

                    player.moveCards(tableaus[fromPile-1], foundations[toPile-1]);
                    break;
                default:
                    cout << "Choose one of the given options!: ";
                    break;
            }

            cout << "\n\n";
            if (illegalMove == true)
                cout << "That's not a legal move!" << endl;
        } while ((choice < 1) || (choice > 5) || (illegalMove == true));
    }

    cout << "Congratulations! You've won the game!" << endl;
    delete deck;
    delete game;

    return 0;
}

void promptChoices(int choice, int &fp, int &tp, int &cards){
    switch(choice){
        case 1:
            cout << "Which is your target pile?: "; cin >> tp;
            break;
        case 2:
            cout << "From which pile will you take a card?: "; cin >> fp;
            cout << "Which is your target pile?: "; cin >> tp;
            break;
        case 3:
            cout << "From which pile will you take a card?: "; cin >> fp;
            cout << "Which is your target pile?: "; cin >> tp;
            cout << "How many cards do you want to move?: "; cin >> cards;
            break;
    }
}

void chooseGame(){
    // Game Choice
    cout << "Choose a gamemode: " << endl;
    cout << "\t 1. Klondike (Draw 1)" << endl;
    cout << "\t 2. Klondike (Draw 3)" << endl;

    int gameChoice;
    while ((gameChoice < 1) || (gameChoice > 2)){
        cin >> gameChoice;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "Bad entry. Enter a NUMBER: ";
            cin >> gameChoice;
        }

        switch(gameChoice){
            case 1:
                deck = DeckKlonOne::getInstance();
                game = KlondikeOne::getInstance();
                break;
            case 2:
                deck = DeckKlonThree::getInstance();
                game = KlondikeThree::getInstance();
                break;
            default:
                cout << "Choose a valid gamemode!: ";
                break;
        }
    }

    cout << "\n\n\n\n\n\n\n\n\n\n" << "The game has started! \n" << endl;
}

void fillTableaus(Pile tableaus[]){
    // Fill the tableaus AND Reveal its last cards
    for (int i = 0; i < TABLEAUS; i++){
        for (int j = 0; j < i+1; j++){
            tableaus[i].addCard(&(deck->dealCard()));
            tableaus[i].getCard(j).setRevealed(false);
        }
        tableaus[i].revealLast();
    }
}
