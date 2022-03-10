//
// Created by 秋至 on 2022/3/9.
//

#ifndef CARDGAME_CARDDECK_H
#define CARDGAME_CARDDECK_H

#include <vector>

class Card;

class CardDeck {
private:
    std::vector<Card> cards_;
public:
    CardDeck() = default;

    void Display();
    CardDeck &Initial();
    CardDeck &Shuffle();
    CardDeck &DeleteTop();
    CardDeck &SendDeck(CardDeck &c);
};


#endif //CARDGAME_CARDDECK_H
