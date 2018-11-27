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

    private:
        bool onboard;
        int usedCards;
        int notDealt = 0;
        Card *deck;
};

#endif // DECK_H
