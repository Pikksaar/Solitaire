#ifndef CARD_H
#define CARD_H
#include <iostream>

class Card{
    public:
        Card();

        std::string getSuit();
        std::string getFace();
        bool getRevealed();

        //void setSprite(const std::string &filename);

        void setSuit(const std::string);
        void setFace(const std::string);
        void revealCard();

        std::string printCard();

    protected:

    private:
        std::string suit;
        std::string face;
        bool revealed, onboard;
        //sf::Texture cTexture;
        //sf::Sprite cSprite;
};

#endif // CARD_H
