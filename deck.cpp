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

}


// shuffle the deck, all 52 cards present
void Deck::shuffle() {

}


// get a card, after 52 are dealt, fail
Card Deck::dealCard() {
    return Card();
}


// # cards left in the deck
int Deck::size() const {
    return 0;
}
