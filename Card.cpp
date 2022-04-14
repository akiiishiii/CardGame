//
// Created by 秋至 on 2022/3/9.
//

#include "Card.h"
#include <iostream>
#include <iomanip>

/// 将花色类型转为字符串
/// \return string 花色类型
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

bool Card::operator<(Card const &c) const {
    if (suit_ == c.suit_)
        return rank_ < c.rank_;
    else
        return suit_ < c.suit_;
}

bool Card::operator==(Card const &c) const {
    return ((suit_ == c.suit_) && (rank_ == c.rank_));
}

/// 将卡片花色及大小输出至标准输出流
void Card::Display() const {
    if (suit_ == SuitType::JOKER)
        std::cout << std::left << std::setw(11) << rank_to_string();
    else
        std::cout << std::left << std::setw(8) << suit_.to_string() << ' ' << std::setw(3) << rank_to_string();
}

/// 将卡牌大小转换为字符串
/// \return string 卡片大小
std::string Card::rank_to_string() const {
    if(suit_ == SuitType::JOKER) {
        if (rank_ == 2)
            return "RED JOKER";
        else
            return "BLACK JOKER";
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
