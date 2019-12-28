#include "DeckKlonThree.h"
#include "iostream"

DeckKlonThree* DeckKlonThree::instance = nullptr;

Card& DeckKlonThree::dealCard(){
  if (usedCards >= 28) return dealCardToTable();

  usedCards++;
  deck[notDealt].setOnboard(true);
  return deck[notDealt++];
}

Card& DeckKlonThree::dealCardToTable(){
  std::cout << "ENTRE" << std::endl;
  deck[notDealt].setOnboard(true);
  return deck[notDealt];
}

void DeckKlonThree::getPreviousCard(){
  int cont = 0;
  while ((notDealt >= 28) && (cont < 3)){
    notDealt--;
    if (deck[notDealt].getOnboard() == false)
      cont++;
  }
}

Card& DeckKlonThree::getCurrentCard(){
  return deck[notDealt];
}

void DeckKlonThree::getNextCard(){
  notDealt++;
  if (notDealt == 52){
    return;
  }

  if (notDealt > 52)
    notDealt = 28;

  while (deck[notDealt].getOnboard() == true && notDealt < 52)
    notDealt++;
}
