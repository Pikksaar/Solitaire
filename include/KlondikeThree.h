#ifndef KLONDIKETHREE_H
#define KLONDIKETHREE_H

#include "Game.h"

class KlondikeThree : public Game{
  private:
    static KlondikeThree* instance;
    KlondikeThree(){}
    int *lastNotDealt = new int;
  public:
    static KlondikeThree *getInstance(){
      if (instance == nullptr)
        instance = new KlondikeThree;
      return instance;
    }
    void drawBoard(Deck*, Pile*, Pile*);
};

#endif // KLONDIKETHREE_H
