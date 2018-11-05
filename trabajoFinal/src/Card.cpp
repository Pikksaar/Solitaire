#include "Card.h"
#include <iostream>
#include <iomanip>
#include <string.h>

Card::Card(){
    revealed = true;
    onboard = false;
}

// GETTERS
std::string Card::getFace(){
    return face;
}

std::string Card::getSuit(){
    return suit;
}

std::string Card::getColour(){
    return colour;
}

int Card::getNumber(){
    return number;
}

bool Card::getOnboard(){
    return onboard;
}

bool Card::getRevealed(){
    return revealed;
}

//SETTERS
void Card::setFace(const std::string n){
    face = n;
}

void Card::setSuit(const std::string s){
    suit = s;
}

void Card::setOnboard(const bool b){
    onboard = b;
}

void Card::setRevealed(const bool b){
    revealed = b;
}

void Card::setNumber(const int n){
    number = n;
}

void Card::setColour(const std::string s){
    colour = s;
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
