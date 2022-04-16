//
// Created by 秋至 on 2022/3/9.
//

#include "Card.h"
#include "CardDeck.h"
#include <algorithm>
#include <exception>
#include <iostream>

/// 将卡堆内卡片依序输出至标准输出流
void CardDeck::Display() {
    if (cards_.empty()) {
        std::cout << "EMPTY\n";
        return;
    }
    int cnt = 0;
    for (auto c = cards_.rbegin(); c != cards_.rend(); c++) {
        c->Display();
        cnt += 1;
        if (cnt % 4 == 0 || cnt == cards_.size())
            std::cout << std::endl;
        else
            std::cout << '\t';
    }
}

/// 初始化卡堆
/// \return CardDeck 初始化后的卡堆
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

/// 随机切洗卡堆
/// \return 随机切洗后的卡堆
CardDeck &CardDeck::Shuffle() {
    try {
        if (cards_.empty()) {
            std::cerr << "Deck is empty.\n";
            throw std::bad_exception();
        }
        std::random_shuffle(cards_.begin(), cards_.end());
    } catch (std::bad_exception& e) {
        throw e;
    }
    return *this;
}

/// 删除指定卡片
/// \param card 需要删除的卡片
/// \return CardDeck 删除指定卡片后的卡堆
CardDeck &CardDeck::Erase(Card card) {
    try {
        auto it = std::find(cards_.begin(), cards_.end(), card);
        if (it == cards_.end()) {
            std::cerr << "Couldn't find the expected card.\n";
            throw std::bad_exception();
        }
        cards_.erase(it);
    } catch (std::bad_exception& e) {
        throw e;
    }
    return *this;
}

/// 删除卡堆顶部的卡片
/// \return CardDeck 删除顶部卡片后的卡堆
CardDeck &CardDeck::EraseTop() {
    try {
        if (cards_.empty()) {
            std::cerr << "Deck is empty.\n";
            throw std::bad_exception();
        }
        cards_.pop_back();
    } catch (std::bad_exception& e) {
        throw e;
    }
    return *this;
}

/// 删除卡堆顶部的指定数量卡片
/// \param n 删除卡片数量
/// \return CardDeck 删除顶部卡片后的卡堆
CardDeck &CardDeck::EraseTop(int n) {
    try {
        for (int i = 0; i < n; i++)
            EraseTop();
    } catch (std::bad_exception& e) {
        throw e;
    }
    return *this;
}

/// 转移牌堆顶端卡片到指定目标
/// \param target 转移目标牌堆
/// \return CardDeck 转移后的原牌堆
CardDeck &CardDeck::SendDeck(CardDeck &target) {
    try {
        if (cards_.empty()) {
            std::cerr << "Deck is empty.\n";
            throw std::bad_exception();
        }
        target.cards_.emplace_back(cards_.back());
        cards_.pop_back();
    } catch (std::bad_exception& e) {
        throw e;
    }
    return *this;
}

/// 转移牌堆顶端指定数量卡片到指定目标
/// \param target 转移目标牌堆
/// \param n 转移卡片数量
/// \return CardDeck 转移后的原牌堆
CardDeck &CardDeck::SendDeck(CardDeck &target, int n) {
    try {
        for (int i = 0; i < n; i++)
            SendDeck(target);
    } catch (std::bad_exception &e) {
        throw e;
    }
    return *this;
}

/// 转移牌堆指定卡片到指定目标
/// \param target 转移目标牌堆
/// \param card 指定卡片
/// \return CardDeck 转移后的原牌堆
CardDeck &CardDeck::SendDeck(CardDeck &target, Card card) {
    try {
        Erase(card);
        target.cards_.emplace_back(card);
    } catch (std::bad_exception& e) {
        throw e;
    }
    return *this;
}
