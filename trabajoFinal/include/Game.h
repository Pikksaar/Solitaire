#ifndef GAME_H
#define GAME_H
#include "Pile.h"
#include "Deck.h"

class Game{
    public:
        virtual void drawBoard(Deck deck, Pile tableaus[], Pile foundations[]) = 0;
        void askAction();
        bool gameWon(Pile &f1, Pile &f2, Pile &f3, Pile &f4);

        ~Game();

    protected:

    private:
};

#endif // GAME_H
