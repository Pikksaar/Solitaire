#include "KlondikeThree.h"
#include <iomanip>

KlondikeThree* KlondikeThree::instance = nullptr;

void KlondikeThree::drawBoard(Deck *deck, Pile tableaus[], Pile foundations[]){

    int lim;
    if (turn == 0){
        lim = 2;
        *lastNotDealt = deck->getNotDealt();
    }
    else if (deck->getNotDealt() < 28){
        if (deck->getNotDealt() == 26)
            lim = 0;
        else if (deck->getNotDealt() == 27)
            lim = 1;

        deck->setNotDealt(28);
    }
    else{
        int cont = 0;
        for (int i = deck->getNotDealt(); i < 52; i++){
            if (deck->getCard(i).getOnboard() == false)
                cont++;
            if (cont > 2) break;
        }

        if (cont == 1)
            lim = 0;
        else if (cont == 2)
            lim = 1;
        else
            lim = 2;
    }

    std::string p;
    if (deck->getCurrentCard().printCard() == "?????")
        p = " ";
    else{
        if ((deck->getNotDealt()+1) >= 52)
            deck->setNotDealt(deck->getNotDealt()-2);
        else if ((deck->getNotDealt()+2) >= 52)
            deck->setNotDealt(deck->getNotDealt()-1);

        if (*lastNotDealt == deck->getNotDealt()-2) deck->setNotDealt(deck->getNotDealt()-2);
        p = deck->getCurrentCard().printCard();
    }

    std::cout << std::setw(19) << "Deck: ";
    std::cout << std::setw(19) << p << std::setw(19) << deck->getNotDealt() << std::endl;

    if (p != " "){
        for (int i = 0; i < lim; i++){
            deck->getNextCard();
            p = deck->getCurrentCard().printCard();
            std::cout << std::setw(38) << p << std::setw(19) << deck->getNotDealt() << std::endl;
        }
    }

    std::cout << "\n\n";

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

    turn++;
}
