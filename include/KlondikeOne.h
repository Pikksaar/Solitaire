#ifndef KLONDIKEONE_H
#define KLONDIKEONE_H

#include "Game.h"

class KlondikeOne : public Game{
  private:
    static KlondikeOne* instance;
    KlondikeOne(){}
  public:
    static KlondikeOne *getInstance(){
      if (instance == nullptr)
        instance = new KlondikeOne;
      return instance;
    }
    void drawBoard(Deck*, Pile*, Pile*);
};

#endif // KLONDIKEONE_H
