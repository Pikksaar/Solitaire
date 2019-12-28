#ifndef DECKKLONTHREE_H
#define DECKKLONTHREE_H

#include "Deck.h"

class DeckKlonThree : public Deck{
  private:
    static DeckKlonThree* instance;
    DeckKlonThree(){}
  public:
    static DeckKlonThree* getInstance(){
      if (instance == nullptr)
        instance = new DeckKlonThree;
      return instance;
    }

    Card& dealCard();
    Card& dealCardToTable();
    Card& getCurrentCard();
    void getPreviousCard();
    void getNextCard();
};

#endif // DECKKLONTHREE_H
