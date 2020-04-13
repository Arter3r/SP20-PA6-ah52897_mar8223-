// File Name: card.cpp
//
// Created by Abdullah on 4/11/2020. [Partnering with Sakib Abdur Rahman]
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
#include <iostream>
#include "card.h"

using namespace std;

// default, ace of spades
Card::Card() {//Default Constructor -- default, ace of spades
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Card::Suit s) {//Normal Constructor -- parameter based
    myRank = rank;
    mySuit = s;
}

// return string version e.g. Ac 4h Js
string Card::toString() const {
    return rankString(myRank) + suitString(mySuit);
}

// true if suit same as c
bool Card::sameSuitAs(const Card& c) const {
    return mySuit == c.mySuit;
}

// return rank, 1..13
int Card::getRank() const {
    return myRank;
}

// return "s", "h",...
string Card::suitString(Card::Suit s) const {
    string suitShort;
    if (s == spades){
        suitShort = 's';
    }
    else if (s == hearts){
        suitShort = 'h';
    }
    else if (s == diamonds){
        suitShort = 'd';
    }
    else {
        suitShort = 'c';
    }
    return suitShort;
}

// return "A", "2", ..."Q"
string Card::rankString(int r) const {
    string cardRank;
    if (r == 1){
        cardRank = 'A';
    }
    else if(r == 11){
        cardRank = 'J';
    }
    else if(r == 12){
        cardRank = 'Q';
    }
    else if(r == 13){
        cardRank = 'K';
    }
    else{
        cardRank = to_string(r);
    }
    return cardRank;
}

bool Card::operator==(const Card& rhs) const {
    return myRank == rhs.myRank && mySuit == rhs.mySuit;
}

bool Card::operator!=(const Card& rhs) const {
    return myRank != rhs.myRank || mySuit != rhs.mySuit;
}
