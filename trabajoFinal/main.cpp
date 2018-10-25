#include <iostream>
#include "Card.h"
#include "Deck.h"
#include <string.h>
#include <ctime>
#include <vector>
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>

//using namespace sf;
using namespace std;

Deck deck;

//vector<Card> playingBoard[7];
/*
Card cardsLeft[24];
Card heartsPile[13];
Card spadesPile[13];
Card clubsPile[13];
Card diamondsPile[13];
*/
//Sprite figures[52]; // images

//string filename(string, int);
/*
void revealCard(Card c){
    if(!c.getRevealed())
        c.setRevealed(true);
}

void moveCard(vector<Card> vec[], int i, int j, int ni, int nj){
    vec[ni-1].push_back(vec[i-1][j-1]);
    vec[i-1].pop_back();
}

void printBoard(vector<Card> vec[]){
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < vec[i].size(); j++){
            if (vec[i][j].getRevealed())
                cout << vec[i][j].getCard() << " ";
            else
                cout << "????? ";
        }
        cout << endl;
    }
}

string filename(string s, int n){
    string a = "images/cards/" + s + "/" + to_string(n) + ".png";
    return a;
}
*/
void createCards();
void chooseCards();

int main(){
    bool gameFinished = false;

    //createCards();
    //chooseCards();

    cout << "Ya estoy corriendo" << endl;
    cout << endl;

    deck.printDeck();

    cout << endl;
    deck.shuffleDeck();
    deck.printDeck();
    cout << endl;
    deck.shuffleDeck();
    deck.printDeck();
    cout << endl;
    deck.shuffleDeck();
    deck.printDeck();

/*    while(!gameFinished){
        printBoard(playingBoard);
        cin >> i >> j;
        cin >> ni >> nj;
        moveCard(playingBoard, i, j, ni, nj);
        revealCard(playingBoard[i-1][j-2]);
    }



/*
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
/*
void chooseCards(){
    srand(time(NULL));
    int row = 0; int column = 1;
    int randomNumber;

    while (column < 7){
        randomNumber = (rand() % 52);
        if (deck[randomNumber].getOnboard() == false){
            deck[randomNumber].setOnboard(true);
            playingBoard[column].push_back(deck[randomNumber]);
            row++;
        }
        if (row == column){
            column++;
            row = 0;
        }
    }

    row = 0;

    while (row < 7){
        randomNumber = (rand() % 52);
        if (deck[randomNumber].getOnboard() == false){
            deck[randomNumber].setOnboard(true);
            deck[randomNumber].setRevealed(true);
            playingBoard[row].push_back(deck[randomNumber]);
            row++;
        }
    }
}
*/
