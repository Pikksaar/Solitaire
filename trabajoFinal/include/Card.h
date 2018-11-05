#ifndef CARD_H
#define CARD_H
#include <iostream>

class Card{
    public:
        Card();

        std::string getSuit();
        std::string getFace();
        std::string getColour();
        bool getOnboard();
        bool getRevealed();
        int getNumber();

        //void setSprite(const std::string &filename);

        void setSuit(const std::string);
        void setFace(const std::string);
        void setOnboard(const bool);
        void setRevealed(const bool);
        void setNumber(const int);
        void setColour(const std::string);

        void revealCard();

        std::string printCard();

    protected:

    private:
        std::string suit;
        std::string face;
        std::string colour;
        bool revealed, onboard;
        int number;

        //sf::Texture cTexture;
        //sf::Sprite cSprite;
};

#endif // CARD_H
