#include "Card.h"
#include <iostream>
#include <iomanip>
#include <string.h>

Card::Card(){
    revealed = true;
    onboard = false;
}

std::string Card::getFace(){
    return face;
}

std::string Card::getSuit(){
    return suit;
}

bool Card::getRevealed(){
    return revealed;
}

void Card::setFace(const std::string n){
    face = n;
}

void Card::setSuit(const std::string s){
    suit = s;
}
/*
void Card::setSprite(const std::string &filename){
    cTexture.loadFromFile(filename);
    sf::Sprite cSprite(cTexture);
}
*/
void Card::revealCard(){
    revealed = true;
}


std::string Card::printCard(){
    if (revealed)
        return face + " of " + suit;
    return "?????";
}
