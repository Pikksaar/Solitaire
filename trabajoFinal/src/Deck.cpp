#include "Deck.h"
#include <vector>
#include <ctime>
#include <iostream>
#include <iomanip>

#define CARDS_IN_DECK 52

Deck::Deck(){
    usedCards = 0;

    std::string faces[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
            "Nine", "Ten", "Jack", "Queen", "King"};
    std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    std::string colours[] = {"Red", "Black"};
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    deck = new Card[CARDS_IN_DECK];

    for(int cont = 0; cont < CARDS_IN_DECK; cont++){ // Populate deck
        deck[cont].setFace(faces[cont % 13]);
        deck[cont].setNumber(numbers[cont % 13]);
        deck[cont].setSuit(suits[cont / 13]);
        deck[cont].setColour(colours[cont / 26]);
    }
}

Deck::~Deck(){
    delete[] deck;
}

void Deck::shuffleDeck(){
    usedCards = 0;

    srand(time(NULL));
    for (int first = 0; first < CARDS_IN_DECK; first++){
        int second = (rand() + time(0)) % CARDS_IN_DECK;

        Card temp = deck[first];
        deck[first] = deck[second];
        deck[second] = temp;
    }
}

void Deck::printDeck(){
    for(int i = 0; i < CARDS_IN_DECK; i++){
        std::cout << std::setw(19) << deck[i].printCard();
        if((i +1) % 4 == 0)
            std::cout << std::endl;
    }
}

void Deck::setNotDealt(int n){
    notDealt = n;
}

int Deck::getNotDealt() const{
    return notDealt;
}

Card& Deck::getCard(int i) const{
    return deck[i];
}
