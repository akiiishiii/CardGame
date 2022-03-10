#include <iostream>
#include "Card.h"
#include "CardDeck.h"

int main(int argc, char const *argv[]) {
    CardDeck deck;
    deck.Initial();
    deck.Display();
    std::cout << std::endl;
    deck.Shuffle();
    deck.Display();
    std::cout << std::endl;
    deck.DeleteTop();
    deck.Display();
    std::cout << std::endl;
    return 0;
}
