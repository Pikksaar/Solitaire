#ifndef KLONDIKE_H
#define KLONDIKE_H

#include "Game.h"

class Klondike : public Game{
    public:
        Klondike();
        void drawBoard(Deck, Pile*, Pile*);

    protected:

    private:
};

#endif // KLONDIKE_H
