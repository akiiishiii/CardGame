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
    int Size() { return static_cast<int>(cards_.size()); }
    CardDeck &Initial();
    CardDeck &Shuffle();
    CardDeck &Erase(Card card);
    CardDeck &EraseTop();
    CardDeck &EraseTop(int n);
    CardDeck &SendDeck(CardDeck &target);
    CardDeck &SendDeck(CardDeck &target, int n);
    CardDeck &SendDeck(CardDeck &target, Card card);
};


#endif //CARDGAME_CARDDECK_H
