#ifndef DECKKLONONE_H
#define DECKKLONONE_H

#include "Deck.h"

class DeckKlonOne : public Deck{
    public:
        Card& dealCard();
        Card& getCurrentCard();
        void getPreviousCard();
        void getNextCard();
};

#endif // DECKKLONONE_H
