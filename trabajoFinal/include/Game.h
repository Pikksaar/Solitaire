#ifndef GAME_H
#define GAME_H
#include "Pile.h"


class Game
{
    public:
        Game();
        void drawBoard(Pile tableaus[]);
        bool gameWon(Pile &f1, Pile &f2, Pile &f3, Pile &f4);

        ~Game();

    protected:

    private:
};

#endif // GAME_H
