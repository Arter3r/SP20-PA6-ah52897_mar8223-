// File Name: card.cpp
//
// Created by Abdullah on 4/11/2020.
//
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13

#include "card.h"


// default, ace of spades
Card::Card() {

}


Card::Card(int rank, Card::Suit s) {

}


// return string version e.g. Ac 4h Js
string Card::toString() const {
    return nullptr;
}


// true if suit same as c
bool Card::sameSuitAs(const Card& c) const {
    return false;
}


// return rank, 1..13
int Card::getRank() const {
    return 0;
}


// return "s", "h",...
string Card::suitString(Card::Suit s) const {
    return nullptr;
}


// return "A", "2", ..."Q"
string Card::rankString(int r) const {
    return nullptr;
}



bool Card::operator==(const Card& rhs) const {
    return false;
}



bool Card::operator!=(const Card& rhs) const {
    return false;
}
