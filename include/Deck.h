#ifndef DECK_H
#define DECK_H

#include "Card.h"

#include <iostream>

class Deck{
  public:
    Deck();
    virtual ~Deck();

    void shuffleDeck();
    void printDeck();
    void setNotDealt(int);
    int getNotDealt() const;
    Card& getCard(int) const;

    virtual Card& dealCard() = 0;
    virtual Card& getCurrentCard() = 0;
    virtual void getPreviousCard() = 0;
    virtual void getNextCard() = 0;

  protected:
    Card *deck;
    int notDealt = 0, usedCards;
};

#endif // DECK_H
