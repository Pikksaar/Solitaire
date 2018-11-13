#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include "Pile.h"

#include <iostream>

class Player{
    private:
        std::string warning = "That's not a legal move!";
    public:
        void moveCards(Pile&, Pile&, int);
        void moveCards(Pile&, Pile&);
        void fromDeckToTableau(Deck&, Pile&);
        void fromDeckToFoundation(Deck&, Pile&);
};

#endif // PLAYER_H
