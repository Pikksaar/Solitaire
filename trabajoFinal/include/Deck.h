#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <iostream>

class Deck{
    public:
        Deck();
        void shuffleDeck();
        Card getNextCard();
        void printDeck();

    private:
        Card *deck;
        int usedCards;
};

#endif // DECK_H
