#include "Card.h"
#include <iostream>
#include <string.h>

Card::Card(){
    revealed = false;
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

bool Card::getOnboard(){
    return onboard;
}

void Card::setFace(std::string n){
    face = n;
}

void Card::setSuit(std::string s){
    suit = s;
}
/*
void Card::setSprite(const std::string &filename){
    cTexture.loadFromFile(filename);
    sf::Sprite cSprite(cTexture);
}
*/
void Card::setRevealed(bool x){
    revealed = x;
}

void Card::setOnboard(bool x){
    onboard = x;
}

std::string Card::print(){
    return face + " de " + suit;
}
