cmake_minimum_required(VERSION 3.15)
project(GoFish)

set(CMAKE_CXX_STANDARD 11)

add_executable(GoFish card_demo.cpp card.cpp card.h deck.cpp deck.h player.cpp player.h)