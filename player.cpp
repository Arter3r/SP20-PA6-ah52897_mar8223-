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
    removeCardFromHand(c1);
    removeCardFromHand(c2);
}

// Compares two cards. Sorts by rank, then string representation.
bool cardCmp(Card& c1, Card& c2){
    if (c1.getRank() < c2.getRank()){
        return true;

    } else if (c1.getRank() == c2.getRank()){
        return c1.toString() < c2.toString();
    }
    return false;
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
bool Player::checkHandForBook(Card& c1, Card& c2) {
    if (myHand.size() <= 1){
        return false;
    }

    sort(myHand.begin(), myHand.end(), cardCmp); //All books are now side by side.

    for(int i = 1; i < myHand.size(); i++){
        if(myHand[i-1].getRank() == myHand[i].getRank()){
            c1 = myHand[i-1];
            c2 = myHand[i];
            return true;
        }
    }

    return false;
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const {
    for (int i=0; i<myHand.size(); i++){
        if(myHand[i].getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const {
    return myHand[rand()%myHand.size()];
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
//Precondition: Card is in hand.
Card Player::removeCardFromHand(Card c) {
    for(int i = 0; i < myHand.size(); i++){
        if(myHand[i] == c) {
            swap(myHand[i], myHand[myHand.size() - 1]);
            myHand.pop_back();
            break;
        }
    }
    return c;
}

string Player::showHand() const {
    string visibleHand = "";
    int i = 0;
    while (i != myHand.size()){
        visibleHand += myHand[i].toString()+" ";
        i++;
    }
    return visibleHand.substr(0, visibleHand.size()-1);
}

string Player::showBooks() const {
    string visibleBooks = 0;
    int i = 0;
    while (i != myBook.size()){
        visibleBooks += myBook[i].toString()+" ";
        i++;
    }
    return visibleBooks.substr(0, visibleBooks.size()-1);
}

int Player::getHandSize() const {
    return myHand.size();
}

int Player::getBookSize() const {
    return myBook.size();
}
