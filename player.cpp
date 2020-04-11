// FILE:  player.h
//
// Created by Abdullah on 4/11/2020.
//
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks
//
#include "player.h"



Player::Player() {

}


//adds a card to the hand
void Player::addCard(Card c) {

}



void Player::bookCards(Card c1, Card c2) {

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
    return false;
}


//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c) {
    return Card();
}



string Player::showHand() const {
    return "";
}



string Player::showBooks() const {
    return "";
}



int Player::getHandSize() const {
    return 0;
}



int Player::getBookSize() const {
    return 0;
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
