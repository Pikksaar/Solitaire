#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <iostream>

class Deck{
    public:
        Deck();

        Card& dealCard();
        Card& getCurrentCard();
        void getPreviousCard();
        void getNextCard();

        void shuffleDeck();
        void printDeck();

        int notDealt = 0;
        Card *deck;

    private:
        bool onboard;
        int usedCards;
        Card blan;
};

#endif // DECK_H
