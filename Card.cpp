//
// Created by 秋至 on 2022/3/9.
//

#include "Card.h"
#include <iostream>
#include <iomanip>

std::string SuitType::to_string() const {
    switch (*this) {
        case JOKER:
            return "JOKER";
        case DIAMOND:
            return "DIAMOND";
        case CLUB:
            return "CLUB";
        case HEART:
            return "HEART";
        case SPADE:
            return "SPADE";
        default:
            return "";
    }
}

bool Card::operator<(const Card &c) const {
    if (suit_ == c.suit_)
        return rank_ < c.rank_;
    else
        return suit_ < c.suit_;
}

void Card::Display() const {
    std::cout << std::left << std::setw(7) << suit_.to_string() << ' ' << std::setw(2) << rank_to_string();
}

std::string Card::rank_to_string() const {
    if(suit_ == SuitType::JOKER) {
        return std::to_string(rank_);
    } else
    switch (rank_) {
        case 1:
            return "A";
        case 11:
            return "J";
        case 12:
            return "Q";
        case 13:
            return "K";
        default:
            return std::to_string(rank_);
    }
}
