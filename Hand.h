#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include "Packn.h"
#include <iostream>
#include <string>
#include <vector>


class Hand{

 public:
    
    //constructor- initalize the hand with an empty vector and no value 
    Hand();
   
    //get number of cards in the hand
    int getNumCards();
    //get total value of cards in the hand
    int getValue();
    //print the hand 
    void printHand();
    //add card to hand 
    void addCard(const Card &c);
    //returns true if cards in hand add to 21
    bool has21();
    //returns true if the first two cards of the hand equal 21 -- BlackJack
    bool hasBlackjack();
    //returns true if the hand contains an ace
    int hasAce();
    //returns true if hand has two of the same card
    bool hasDoubles();
    //returns true if cards in hand add to over 21
    bool isBusted();
   
   //Prints Hand for Dealer
   void printDealerHand();
    


 private:
    //number of cards in the hand 
    int numCards;
    //vector of cards in the hand 
    std::vector <Card> hand;
    //total value of the cards in hand 
    int value;

};










#endif