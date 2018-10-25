#include "Deck.h"
#include "Card.h"
#include <vector>
#include <ctime>
#include <iostream>
#include <iomanip>

#define CARDS_IN_DECK 52

Deck::Deck(){
    usedCards = 0;

    std::string faces[] = {"As", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho",
            "Nueve", "Diez", "Jack", "Queen", "King"};
    std::string suits[] = {"Corazones", "Diamantes", "Treboles", "Espadas"};

    deck = new Card[CARDS_IN_DECK];
    for(int cont = 0; cont < CARDS_IN_DECK; cont++){ // Populate deck
        deck[cont].setFace(faces[cont % 13]);
        deck[cont].setSuit(suits[cont / 13]);
    }
}

void Deck::shuffleDeck(){
    usedCards = 0;

    for (int first = 0; first < CARDS_IN_DECK; first++){
        int second = (rand() + time(0)) % CARDS_IN_DECK;

        Card temp = deck[first];
        deck[first] = deck[second];
        deck[second] = temp;
    }
}

void Deck::printDeck(){
    for(int i = 0; i < CARDS_IN_DECK; i++){
        std::cout << std::setw(21) << deck[i].print();
        if((i +1) % 4 == 0)
            std::cout << std::endl;
    }
}

Card Deck::getNextCard(){

}
