#include "Game.h"

#include <iostream>
#include <iomanip>

#define TABLEAUS 7
#define FOUNDATIONS 4
Game::Game(){

}

void Game::drawBoard(Deck deck, Pile tableaus[], Pile foundations[]){
    std::cout << std::setw(19) << "Deck: " << std::setw(19) << deck.getNextCard() << "\n\n";

    for (int i = 0; i < 13; i++){
        for (int j = 0; j < TABLEAUS; j++){
            if (tableaus[j].getSize() == 0){
                std::cout << std::setw(19) << " ";
            }
            else if (tableaus[j].getSize() <= i){
                std::cout << std::setw(19) << " ";
            }
            else{
                std::cout << std::setw(19) << tableaus[j].getCard(i).printCard();
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::setw(19) << "1. HEARTS" << std::setw(19) << "2. SPADES" << std::setw(19) << "3. DIAMONDS" << std::setw(19) << "4. CLUBS" << std::endl;

    for (int i = 0; i < 13; i++){
        for (int j = 0; j < FOUNDATIONS; j++){
            if (foundations[j].getSize() == 0){
                std::cout << std::setw(19) << " ";
            }
            else if (foundations[j].getSize() <= i){
                std::cout << std::setw(19) << " ";
            }
            else{
                std::cout << std::setw(19) << foundations[j].getCard(i).printCard();
            }
        }
        std::cout << std::endl;
    }
}

void Game::askAction(){
    std::cout << "To see the next card in the deck, press 1." << std::endl;
    std::cout << "To move a card from the deck to a tableau, press 2." << std::endl;
    std::cout << "To move a card from the deck to a foundation, press 3." << std::endl;
    std::cout << "To move a card from one tableau to another, press 4." << std::endl;
    std::cout << "To move a card from a tableau to a foundation, press 5." << std::endl;
}

bool Game::gameWon(Pile &f1, Pile &f2, Pile &f3, Pile &f4){ // f = fundation
    if((f1.getSize() == 13) && (f2.getSize() == 13) && (f3.getSize() == 13) & (f4.getSize() == 13))
        return true;
    return false;
}

Game::~Game()
{
    //dtor
}
