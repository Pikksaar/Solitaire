#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <iostream>

class Deck{
    public:
        Deck();

        Card& dealCard();
        std::string getNextCard();
        Card& getCurrentCard();
        void getPreviousCard();

        void shuffleDeck();
        void printDeck();


    private:
        Card *deck;
        bool onboard;
        int usedCards;
        int notDealt = 0;
};

#endif // DECK_H
