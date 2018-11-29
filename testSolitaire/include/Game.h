#ifndef GAME_H
#define GAME_H
#include "Pile.h"
#include "Deck.h"

class Game{
    public:
        virtual ~Game();

        static int turn;

        static const int TABLEAUS = 7;
        static const int FOUNDATIONS = 4;

        virtual void drawBoard(Deck*, Pile*, Pile*) = 0;
        void askAction();
        bool gameWon(Pile&, Pile&, Pile&, Pile&);
};

#endif // GAME_H
