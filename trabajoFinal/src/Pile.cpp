#include "Pile.h"
#include <iomanip>

Pile::Pile(){
    pileSize = 0;
}

void Pile::addCard(Card *d){
    this->pile.push_back(d);
    this->pileSize++;
}

void Pile::removeCard(int n = 0){
    if (n > 0)
        this->pile.erase(pile.begin() + pileSize - 1 - n);
    else
        this->pile.pop_back();

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
/*
void Pile::moveCard(Pile &p, Card c){
    p.addCard(c);
    this->pile.pop_back();
    pile[pileSize-1].revealCard();
    this->pileSize--;
}

void Pile::addCard(Card c){
    this->pile.push_back(c);
    this->pileSize++;
}

void Pile::revealLast(){
    pile.back().revealCard();
}

int Pile::getSize(){
    return pileSize;
}

void Pile::printPile(){
    for(Card c : pile)
        std::cout << std::setw(17) << c.printCard() << " ";
    std::cout << std::endl;
}

Card Pile::getCard(int indx){
    return pile[indx];
}
*/
