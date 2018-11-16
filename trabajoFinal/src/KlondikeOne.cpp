#include "KlondikeOne.h"
#include <iomanip>

#define TABLEAUS 7
#define FOUNDATIONS 4

void KlondikeOne::drawBoard(Deck deck, Pile tableaus[], Pile foundations[]){
    int notDealt = deck.notDealt;

    std::string p;
    if (deck.getCurrentCard().printCard() == "?????")
        p = " ";
    else p = deck.getCurrentCard().printCard();

    std::cout << std::setw(19) << "Deck: " << std::setw(19) << p << std::setw(19) << "\n\n";

    for (int i = 0; i < 13; i++){
        for (int j = 0; j < TABLEAUS; j++){
            if (tableaus[j].getSize() == 0){
                std::cout << std::setw(19) << " ";
            }
            else if (tableaus[j].getSize() <= i){
                std::cout << std::setw(19) << " ";
            }
            else{
                std::cout << std::setw(19) << tableaus[j].getCard(i).printCard();
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::setw(19) << "1. FOUNDATION" << std::setw(19) << "2. FOUNDATION"
        << std::setw(19) << "3. FOUNDATION" << std::setw(19) << "4. FOUNDATION" << std::endl;

    for (int i = 0; i < 13; i++){
        for (int j = 0; j < FOUNDATIONS; j++){
            if (foundations[j].getSize() == 0){
                std::cout << std::setw(19) << " ";
            }
            else if (foundations[j].getSize() <= i){
                std::cout << std::setw(19) << " ";
            }
            else{
                std::cout << std::setw(19) << foundations[j].getCard(i).printCard();
            }
        }
        std::cout << std::endl;
    }
}
