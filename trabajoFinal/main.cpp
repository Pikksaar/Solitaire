#include <iostream>
#include <iomanip>

#include <string.h>
#include <ctime>
#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Pile.h"
#include "Game.h"

#define TABLEAUS 7
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>

//using namespace sf;
using namespace std;


//string filename(string, int);
/*
string filename(string s, int n){
    string a = "images/cards/" + s + "/" + to_string(n) + ".png";
    return a;
}
*/
Game game;
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
                fromDeckToTableau(tableaus[toPile-1]);
                break;
            case 3:
                cin >> toPile;
                fromDeckToFoundation(foundations[toPile-1]);
                break;
            case 4:
                cin >> fromPile >> toPile >> cards;

                if (cards > tableaus[fromPile-1].getSize()){
                    cout << "That's not a legal move!" << endl;
                    break;
                }

                moveCards(tableaus[fromPile-1], tableaus[toPile-1], cards);
                break;
            case 5:
                cin >> fromPile >> toPile;

                if (tableaus[fromPile-1].getSize() == 0){
                    cout << "That's not a legal move!" << endl;
                    break;
                }

                moveCards(tableaus[fromPile-1], foundations[toPile-1]);
                break;
            default:
                cout << "Choose one of the given options!" << endl;
                break;
        }

        cout << "\n\n";
        //int choosePile, toPile, quant;
        //cin >> choosePile >> toPile >> quant;

        //moveCards(tableaus[choosePile-1], foundations[toPile-1], quant);
    }

/*    while(!gameFinished){
        printBoard(playingBoard);
        cin >> i >> j;
        cin >> ni >> nj;
        moveCard(playingBoard, i, j, ni, nj);
        revealCard(playingBoard[i-1][j-2]);
    }

    RenderWindow window(VideoMode(678, 848), "Solitaire!");

    Texture t1;
    //t1.loadFromFile("images/cards/hearts/2.png");
    t1.loadFromFile("images/cards/hearts/2.png");
    Sprite s(t1);

    Texture t2;
    t2.loadFromFile("images/bg.png");
    Sprite board(t2);

    bool isMove = false;
    float dx = 0, dy = 0;

    while ((!gameFinished) && (window.isOpen())){
        Vector2i pos = Mouse::getPosition(window);

        Event e;
        while (window.pollEvent(e)){
            if (e.type == Event::Closed)
                window.close();

            ///////drag and drop///////
            if (e.type == Event::MouseButtonPressed)
                if (e.key.code == Mouse::Left)
                    if (s.getGlobalBounds().contains(pos.x, pos.y)){
                        isMove = true;
                        dx = pos.x - s.getPosition().x;
                        dy = pos.y - s.getPosition().y;
                    }

            if (e.type == Event::MouseButtonReleased)
                if (e.key.code == Mouse::Left)
                    isMove = false;
        }

        if (isMove) s.setPosition(pos.x-dx, pos.y-dy);

        window.clear();
        window.draw(board);
        window.draw(s);
        window.display();
    }
*/
    return 0;
}

string warning = "That's not a legal move!";

void moveCards(Pile &dealer, Pile &receiver, int cards){
    Card *cardToMove = &dealer.getCard(dealer.getSize()-cards);
    Card *topCard;

    if (receiver.getSize() == 0){
        if (cardToMove->getNumber() != 13){
            cout << warning << endl;
            return;
        }
    }

    else{
        topCard = &receiver.getLastCard();

        if ((cardToMove->getNumber() != (topCard->getNumber() - 1)) || ((cardToMove->getColour() == topCard->getColour()))){
            cout << warning << endl;
            return;
        }
    }

    int j = cards;
    for (int i = 0; i < j; i++){
        receiver.addCard(cardToMove);
        dealer.removeCard(cards);
        cards--;
        cardToMove = &dealer.getCard(dealer.getSize()-cards);
    }
    if (dealer.getSize() > 0)
        dealer.revealLast();
}

void moveCards(Pile &dealer, Pile &receiver){
    Card *cardToMove = &dealer.getCard(dealer.getSize()-1);
    Card *topCard;

    if (receiver.getSize() == 0){
        if (cardToMove->getNumber() != 1){
            cout << warning << endl;
            return;
        }
    }

    if (receiver.getSize() > 0){
        topCard = &receiver.getLastCard();

        if ((cardToMove->getNumber() != (topCard->getNumber() + 1)) || ((cardToMove->getColour() != topCard->getColour()))){
            cout << warning << endl;
            return;
        }
    }

    receiver.addCard(cardToMove);
    dealer.removeCard(1);

    if (dealer.getSize() > 0)
        dealer.revealLast();
}

void fromDeckToTableau(Pile &receiver){
    Card *cardToMove = &deck.getCurrentCard();
    Card *topCard;

    if (receiver.getSize() == 0){
        if (cardToMove->getNumber() != 13){
            cout << warning << endl;
            return;
        }
    }
    else{
        topCard = &receiver.getLastCard();

        if ((cardToMove->getNumber() != (topCard->getNumber()-1)) || (cardToMove->getColour() == topCard->getColour())){
            cout << warning << endl;
            return;
        }
    }

    receiver.addCard(&(deck.dealCard()));
    deck.getPreviousCard();
}

void fromDeckToFoundation(Pile &receiver){
    Card *cardToMove = &deck.getCurrentCard();
    Card *topCard;

    if (receiver.getSize() == 0){
        if (cardToMove->getNumber() != 1){
            cout << warning << endl;
            return;
        }
    }
    else{
        topCard = &receiver.getLastCard();

        if ((cardToMove->getNumber() != (topCard->getNumber() + 1)) || (cardToMove->getSuit() != topCard->getSuit())){
            cout << warning << endl;
            return;
        }
    }

    receiver.addCard(&(deck.dealCard()));
    deck.getPreviousCard();
}
