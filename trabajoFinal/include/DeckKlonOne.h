#ifndef DECKKLONONE_H
#define DECKKLONONE_H

#include "Deck.h"

class DeckKlonOne : public Deck{
    private:
        static DeckKlonOne* instance;
        DeckKlonOne(){}
    public:
        static DeckKlonOne* getInstance(){
            if (instance == nullptr)
                instance = new DeckKlonOne;
            return instance;
        }

        Card& dealCard();
        Card& getCurrentCard();
        void getPreviousCard();
        void getNextCard();
};

#endif // DECKKLONONE_H
