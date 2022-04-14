//
// Created by 秋至 on 2022/3/9.
//

#ifndef CARDGAME_CARD_H
#define CARDGAME_CARD_H


#include <string>

struct SuitType {
public:
    enum type { JOKER = 0, DIAMOND, CLUB, HEART, SPADE };

    SuitType() : value_(type()) { };
    SuitType(SuitType const &val) = default;
    SuitType(type const val) : value_(val) { }

    SuitType &operator=(SuitType const &val) = default;
    bool operator==(SuitType const &val) const { return (value_ == val.value_);}
    bool operator<(SuitType const &val) const { return (value_ < val.value_);}

    SuitType &operator=(type const val) { value_ = val; return *this;}
    bool operator==(type const val) const { return (value_ == val);}
    bool operator<(type const val) const { return (value_ < val);}

    operator type() const { return value_;}

    std::string to_string() const;
private:
    type value_;
};

class Card {
private:
    SuitType suit_;
    int rank_ = 0;
public:
    Card() = default;
    Card(SuitType suit, int rank) : suit_(suit), rank_(rank) { }

    bool operator<(Card const &c) const;
    bool operator==(Card const &c) const;

    void Display() const;
    std::string rank_to_string() const;
};


#endif //CARDGAME_CARD_H
