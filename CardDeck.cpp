//
// Created by 秋至 on 2022/3/9.
//

#include "Card.h"
#include "CardDeck.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>

void CardDeck::Display() {
    for (auto const &c : cards_) {
        c.Display();
        std::cout << std::endl;
    }
}

CardDeck &CardDeck::Initial() {
    while (!cards_.empty())
        cards_.pop_back();
    cards_.emplace_back(SuitType::JOKER, 1);
    cards_.emplace_back(SuitType::JOKER, 2);
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 13; j++)
            cards_.emplace_back(SuitType::type(i), j);
    return *this;
}

CardDeck &CardDeck::Shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards_.begin(), cards_.begin(), std::default_random_engine(seed));
    return *this;
}

CardDeck &CardDeck::DeleteTop() {
    if(!cards_.empty())
        cards_.pop_back();
    return *this;
}

CardDeck &CardDeck::SendDeck(CardDeck &c) {
    c.cards_.emplace_back(cards_.back());
    cards_.pop_back();
    return *this;
}
