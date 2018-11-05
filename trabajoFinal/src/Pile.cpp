#include "Pile.h"
#include <iomanip>

Pile::Pile(){
    pileSize = 0;
}

void Pile::addCard(Card *d){
    this->pile.push_back(d);
    this->pileSize++;
}

void Pile::removeCard(int n){
    this->pile.erase(pile.end() - n);
    this->pileSize--;
}

void Pile::revealLast(){
    (*(pile[pileSize-1])).revealCard();
}

int Pile::getSize(){
    return pileSize;
}

void Pile::printPile(){
    for(Card *d : pile)
        std::cout << std::setw(17) << (*d).printCard() << " ";
    std::cout << std::endl;
}

Card& Pile::getCard(int indx){
    return *pile[indx];
}

Card& Pile::getLastCard(){
    return *pile[pileSize-1];
}
