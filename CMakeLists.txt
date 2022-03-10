cmake_minimum_required(VERSION 3.20)
project(CardGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(CardGame main.cpp Card.cpp Card.h CardDeck.cpp CardDeck.h)
