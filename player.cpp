// FILE:  player.h
//
// Created by Abdullah on 4/11/2020.
//
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks
//
#include "player.h"


Player::Player() {
    myName = "Player";
}

//adds a card to the hand
void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {//moves c1 and c2 from hand to books
    myBook.push_back(c1);
    myBook.push_back(c2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
bool Player::checkHandForBook(Card& c1, Card& c2) {
    return false;
}


//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const {
    return false;
}


//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const {
    return Card();
}


//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const {
    for (int i=0; i<myHand.size(); i++){
        if(myHand[i] == c){
            return true;
        }
    }
    return false;
}


//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c) {
    return Card();
}

string Player::showHand() const {
    string visibleHand;
    int i;
    while (i != myHand.size()){
        visibleHand += myHand[i].toString()+" ";
        i++;
    }
    return visibleHand;
}

string Player::showBooks() const {
    string visibleBooks;
    int i;
    while (i != myBook.size()){
        visibleBooks += myBook[i].toString()+" ";
        i++;
    }
    return visibleBooks;
}

int Player::getHandSize() const {
    return myHand.size();
}

int Player::getBookSize() const {
    return myBook.size();
}


//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
bool Player::checkHandForPair(Card& c1, Card& c2) {
    return false;
}


//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c
bool Player::sameRankInHand(Card c) const {
    return false;
}
