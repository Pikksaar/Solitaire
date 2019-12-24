#include "DeckKlonOne.h"

DeckKlonOne* DeckKlonOne::instance = nullptr;

Card& DeckKlonOne::dealCard(){
    deck[notDealt].setOnboard(true);
    return deck[notDealt++];
}

void DeckKlonOne::getPreviousCard(){
    notDealt--;
    while (deck[notDealt].getOnboard() == true && notDealt >= 28)
        notDealt--;

    if (notDealt < 28)
        notDealt = 52;
}

Card& DeckKlonOne::getCurrentCard(){
    return deck[notDealt];
}

void DeckKlonOne::getNextCard(){
    notDealt++;
    if (notDealt > 52){
        notDealt = 28;
    }
    while (deck[notDealt].getOnboard() == true && notDealt < 52)
        notDealt++;
}
