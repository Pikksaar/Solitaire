#ifndef CARD_H
#define CARD_H
#include <iostream>

class Card{
    public:
        Card();

        std::string getSuit();
        std::string getFace();
        bool getRevealed();
        bool getOnboard();

        //void setSprite(const std::string &filename);

        void setSuit(std::string);
        void setFace(std::string);
        void setRevealed(bool);
        void setOnboard(bool);

        std::string print();

    protected:

    private:
        std::string suit;
        std::string face;
        bool revealed, onboard;
        //sf::Texture cTexture;
        //sf::Sprite cSprite;
};

#endif // CARD_H
