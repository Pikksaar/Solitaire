#ifndef KLONDIKETHREE_H
#define KLONDIKETHREE_H

#include "Game.h"

class KlondikeThree : public Game{
    public:
        void drawBoard(Deck*, Pile*, Pile*);
    private:
        int *lastNotDealt = new int;
};

#endif // KLONDIKETHREE_H
