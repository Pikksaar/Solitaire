#ifndef DECK_H
#define DECK_H

#include "Card.h"

#include <iostream>

class Deck{
    public:
        Deck();
        ~Deck();

        void shuffleDeck();
        void printDeck();

        virtual Card& dealCard() = 0;
        virtual Card& getCurrentCard() = 0;
        virtual void getPreviousCard() = 0;
        virtual void getNextCard() = 0;

        int notDealt = 0;
    protected:
        Card *deck;

        bool onboard;

        int usedCards;
};

#endif // DECK_H
