#ifndef PILE_H
#define PILE_H
#include "Card.h"
#include <vector>

class Pile{
    public:
        Pile();

        void addCard(Card *d);
        void removeCard(int);
        void revealLast();

        int getSize();
        Card& getCard(int);
        Card& getLastCard();

    private:
        std::vector<Card*> pile;
        int pileSize;
};

#endif // PILE_H
