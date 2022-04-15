//
// Created by 秋至 on 2022/3/9.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Card.h"
#include "CardDeck.h"

int main() {
    /// 初始化随机数种子
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    CardDeck deck, players[4];

    /// 初始化牌堆
    std::cout << "Press Enter to initalize a card deck.\n";
    std::system("pause");
    deck.Initial();
    std::cout << "Initialization completed.\n\n";

    std::cout << "Current card deck:\n";
    deck.Display();
    std::cout << std::endl;

    /// 切洗牌堆
    std::cout << "Press Enter to shuffle the card deck.\n";
    std::system("pause");
    deck.Shuffle();
    std::cout << "Shuffling completed.\n\n";

    std::cout << "Current card deck:\n";
    deck.Display();
    std::cout << std::endl;

    /// 去掉牌堆顶端两张卡牌
    std::cout << "Press Enter to erase TWO cards form the top of the card deck.\n";
    std::system("pause");
    deck.EraseTop(2);
    std::cout << "Erasing completed.\n\n";

    std::cout << "Current card deck:\n";
    deck.Display();
    std::cout << std::endl;

    /// 将卡片分给四人
    std::cout << "Press Enter to seperate the cards.\n";
    std::system("pause");
    {
        int cnt = 0;
        while (deck.Size() != 0)
            deck.SendDeck(players[cnt++ % 4]);
    }
    std::cout << "Seperation completed.\n\n";

    for (int i = 0; i < 4; i++) {
        std::cout << "Player " << i + 1 << "'s card deck:\n";
        players[i].Display();
        std::cout << std::endl;
    }

    std::cout << std::endl << "Press Enter to quit.\n";
    std::system("pause");
    return 0;
}
