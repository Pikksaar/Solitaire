#include "Game.h"

#include <iostream>
#include <iomanip>

#define TABLEAUS 7
#define FOUNDATIONS 4

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
