// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

void doTurn(Deck &d, Player& p1, Player& p2, int numPlayers);

bool ask(Deck& d, Player& currentTurn, Player& other);

ofstream out;


int main( )
{
    srand(time(NULL));
    out.open("gofish_results.txt");
    int numCards = 7;
    
    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    //TODO: Remove debug prints
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    out << p1.getName() <<" has : " << p1.showHand() << endl;
    out << p2.getName() <<" has : " << p2.showHand() << endl;

    //While there are still valid playing cards
    while(!(d.size() == 0 && p1.getHandSize() == 0 && p2.getHandSize() == 0)){
        doTurn(d, p1, p2, 2);
    }
    //TODO:Who won?
    cout<<"Game Finished!"<<endl;
    out<<"Game Finished!"<<endl;
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   
void doTurn(Deck& d, Player& p1, Player& p2, int numPlayers){
    static int turn = 1;

    //TODO: Remove debug prints
    cout <<endl<< "Turn #" << turn << ":\n";
    out <<endl<< "Turn #" << turn << ":\n";
    Card book1, book2;
    while(p1.checkHandForBook(book1, book2)){
        p1.bookCards(book1, book2);
        cout << p1.getName() << " books initial cards." << endl;
        out << p1.getName() << " books initial cards." << endl;

    }
    while(p2.checkHandForBook(book1, book2)){
        p2.bookCards(book1, book2);
        cout << p2.getName() << " books initial cards." << endl;
        out << p2.getName() << " books initial cards." << endl;
    }

    cout << p1.getName() << "'s Cards: " << p1.showHand() << "\nBooks: " << p1.showBooks() << "\n" << endl;
    out << p1.getName() << "'s Cards: " << p1.showHand() << "\nBooks: " << p1.showBooks() << "\n" << endl;
    cout << p2.getName() << "'s Cards: " << p2.showHand() << "\nBooks: " << p2.showBooks() << "\n" << endl;
    out << p2.getName() << "'s Cards: " << p2.showHand() << "\nBooks: " << p2.showBooks() << "\n" << endl;

    while(ask(d, p1, p2));
    while(ask(d, p2, p1));
    turn++;
}

bool ask(Deck& d, Player& currentTurn, Player& other){

    if(currentTurn.getHandSize() == 0){
        if(d.size()>0) {
            currentTurn.addCard(d.dealCard());
            cout << currentTurn.getName() << " Picks up a card from the deck to continue playing." << endl;
            out << currentTurn.getName() << " Picks up a card from the deck to continue playing." << endl;
        }else{
            cout << currentTurn.getName() << "'s turn is skipped since no cards in hand and no cards in deck." << endl;
            out << currentTurn.getName() << "'s turn is skipped since no cards in hand and no cards in deck." << endl;
            return false;
        }
    }

    Card askingFor = currentTurn.chooseCardFromHand();
    //TODO: Remove debug prints
    cout << endl    << currentTurn.getName()
         << " asks - Do you have a "
         << askingFor.rankString(askingFor.getRank())
         << "?" << endl;
    out << endl    << currentTurn.getName()
         << " asks - Do you have a "
         << askingFor.rankString(askingFor.getRank())
         << "?" << endl;
    Card othersCard = askingFor;
    bool otherHasRankInHand = other.rankInHand(othersCard);

    if (otherHasRankInHand){
        //TODO: Remove debug prints
        cout << other.getName()
             << " says - Yes. I have a "
             << askingFor.rankString(askingFor.getRank())
             << "." << endl;
        out << other.getName()
             << " says - Yes. I have a "
             << askingFor.rankString(askingFor.getRank())
             << "." << endl;
        currentTurn.addCard(other.removeCardFromHand(othersCard));
        Card book1, book2;
        if(currentTurn.checkHandForBook(book1, book2)){
            currentTurn.bookCards(book1, book2);
        } else {
            cout << "\n Didn't have a book even after own turn." << endl;
            out << "\n Didn't have a book even after own turn." << endl;
        }
        //TODO: Remove debug prints
        cout << currentTurn.getName()
             << " books the "
             << askingFor.rankString(book1.getRank())
             << "." << endl;
        out << currentTurn.getName()
             << " books the "
             << askingFor.rankString(book1.getRank())
             << "." << endl;
        return true;
    }
    else{
        //TODO: Remove debug prints
        cout << other.getName() << " says - Go Fish!" << endl;
        out << other.getName() << " says - Go Fish!" << endl;
        if (d.size() <= 0){
            cout<<"Deck is empty! Not fishing."<<endl;
            out<<"Deck is empty! Not fishing."<<endl;
            return false;
        }else{
            Card fished = d.dealCard();
            currentTurn.addCard(fished);
            Card book1, book2;
            cout << currentTurn.getName() << " picks up " << fished.toString();
            out << currentTurn.getName() << " picks up " << fished.toString();
            if(currentTurn.checkHandForBook(book1, book2)){
                currentTurn.bookCards(book1, book2);
                cout << ", and books it." << endl;
                out << ", and books it." << endl;
                return false;
            } else {
                cout << "." << endl;
                out << "." << endl;
                return false;
            }

        }


    }
}

