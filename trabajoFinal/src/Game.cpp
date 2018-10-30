#include "Game.h"
#include "Pile.h"
#include <iostream>
#include <iomanip>

#define FOUNDATIONS 7
Game::Game(){

}

void Game::drawBoard(Pile tableaus[]){
    for (int i = 0; i < 13; i++){
        for (int j = 0; j < FOUNDATIONS; j++){
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
