// FILE: deck.cpp
//
// Created by Abdullah on 4/11/2020.
//
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck makes it consist of 52 cards in a random order
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.
//
// Calling shuffle again replenishes the deck with 52 cards.

#include "deck.h"

// pristine, sorted deck
Deck::Deck() {
    myIndex = 0;
    int currentIndex = 0;
    for (int cRank=0; cRank<13; cRank++){
        for (int cSuit=0; cSuit<4; cSuit++){
            myCards[currentIndex] = Card(cRank+1,Card::Suit(cSuit));
            currentIndex++;
        }
    }

}

// Returns ints with a uniform distribution
// over the closed interval [low, high]
int uniform_distribution(int low, int high) {
    int range = high - low + 1;
    int max = RAND_MAX - RAND_MAX % range;
    int x;
    x = rand();
    while (x >= max){
        srand(x);
        x = rand();
    }
    return low + x % range;
}

// shuffle the deck, all 52 cards present
void Deck::shuffle() {
    for(int i = 51; i > 0; --i){
        swap(myCards[i], myCards[uniform_distribution(0, i)]);
    }
}

// get a card, after 52 are dealt, fail
// Fail is defined as returning a card with negative rank.
Card Deck::dealCard() {
    if(myIndex > 51){
        return Card(-1, Card::clubs);
    }
    myIndex++;
    return myCards[myIndex-1];
}


// # cards left in the deck
int Deck::size() const {
    return SIZE-myIndex;
}
