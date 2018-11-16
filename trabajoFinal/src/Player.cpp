#include "Player.h"

using namespace std;

void Player::moveCards(Pile &dealer, Pile &receiver, int cards){
    Card *cardToMove = &dealer.getCard(dealer.getSize()-cards);
    Card *topCard;

    if (cardToMove->getRevealed() == false){
        cout << warning << endl;
        return;
    }

    if (receiver.getSize() == 0){
        if (cardToMove->getNumber() != 13){
            cout << warning << endl;
            return;
        }
    }

    else{
        topCard = &receiver.getLastCard();

        if ((cardToMove->getNumber() != (topCard->getNumber() - 1)) || ((cardToMove->getColour() == topCard->getColour()))){
            cout << warning << endl;
            return;
        }
    }

    int j = cards;
    for (int i = 0; i < j; i++){
        receiver.addCard(cardToMove);
        dealer.removeCard(cards);
        cards--;
        cardToMove = &dealer.getCard(dealer.getSize()-cards);
    }
    if (dealer.getSize() > 0)
        dealer.revealLast();
}

void Player::moveCards(Pile &dealer, Pile &receiver){
    Card *cardToMove = &dealer.getCard(dealer.getSize()-1);
    Card *topCard;

    if (receiver.getSize() == 0){
        if (cardToMove->getNumber() != 1){
            cout << warning << endl;
            return;
        }
    }

    if (receiver.getSize() > 0){
        topCard = &receiver.getLastCard();

        if ((cardToMove->getNumber() != (topCard->getNumber() + 1)) || ((cardToMove->getColour() != topCard->getColour()))){
            cout << warning << endl;
            return;
        }
    }

    receiver.addCard(cardToMove);
    dealer.removeCard(1);

    if (dealer.getSize() > 0)
        dealer.revealLast();
}

void Player::fromDeckToTableau(Deck &deck, Pile &receiver){
    Card *cardToMove = &deck.getCurrentCard();
    Card *topCard;

    if (receiver.getSize() == 0){
        if (cardToMove->getNumber() != 13){
            cout << warning << endl;
            return;
        }
    }
    else{
        topCard = &receiver.getLastCard();

        if ((cardToMove->getNumber() != (topCard->getNumber() - 1)) || (cardToMove->getColour() == topCard->getColour())){
            cout << warning << endl;
            return;
        }
    }

    receiver.addCard(&(deck.dealCard()));
    deck.getPreviousCard();
}

void Player::fromDeckToFoundation(Deck &deck, Pile &receiver){
    Card *cardToMove = &deck.getCurrentCard();
    Card *topCard;

    if (receiver.getSize() == 0){
        if (cardToMove->getNumber() != 1){
            cout << warning << endl;
            return;
        }
    }
    else{
        topCard = &receiver.getLastCard();

        if ((cardToMove->getNumber() != (topCard->getNumber() + 1)) || (cardToMove->getSuit() != topCard->getSuit())){
            cout << warning << endl;
            return;
        }
    }

    receiver.addCard(&(deck.dealCard()));
    deck.getPreviousCard();
}
