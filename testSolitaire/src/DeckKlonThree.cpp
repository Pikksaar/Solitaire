#include "DeckKlonThree.h"

Card& DeckKlonThree::dealCard(){
    deck[notDealt].setOnboard(true);
    return deck[notDealt++];
}

void DeckKlonThree::getPreviousCard(){
    notDealt -= 2;
    while (deck[notDealt].getOnboard() == true && notDealt >= 28)
        notDealt--;

    if (notDealt < 28)
        notDealt = 52;
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
