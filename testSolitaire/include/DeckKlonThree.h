#ifndef DECKKLONTHREE_H
#define DECKKLONTHREE_H

#include "Deck.h"

class DeckKlonThree : public Deck{
    public:
        Card& dealCard();
        Card& getCurrentCard();
        void getPreviousCard();
        void getNextCard();
};

#endif // DECKKLONTHREE_H
