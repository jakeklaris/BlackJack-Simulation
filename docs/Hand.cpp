#include "Hand.h"
#include <iostream>
#include <vector>
#include <string>


using namespace std;


Hand::Hand() : numCards(0), value(0) {}

int Hand::getNumCards(){
    return numCards;
}

int Hand::getValue(){
    return value;
}

void Hand::printHand(){
    for(int j = 0; j < numCards; ++j){
        cout << "Card " << j << ": " << hand[j] << endl;
    }
    cout << "Total Value: " << value << endl;
}

void Hand::addCard(const Card &c){
    value += c.get_value();
    hand.push_back(c);
    ++numCards;
}


bool Hand::has21(){
    if(value == 21){
        return true;
    }
    else {
        return false;
    }
}

bool Hand::hasBlackjack(){
    if(has21() && numCards == 2){
        return true;
    }
    else {
        return false;
    }
}

int Hand::hasAce(){
    bool ace = -1;
    for(int i = 0; i < numCards; ++i){
        if(hand[i].get_suit() == "Ace"){
            ace = i;
        }
    }
    return ace;
}

bool Hand::hasDoubles(){
    if(numCards == 2) {
        if(hand[0] == hand[1]){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool Hand::isBusted(){
    if(value > 21){
        if(hasAce() == -1){
            return true;
        }
        else{
            hand[hasAce()].SetAceValue(1);
            return false;
        }
    }
    else{
        return false;
    }

}

void Hand::printDealerHand(){
    if(numCards == 2){
        cout << "Card 0: Hidden" << endl;
        cout << "Card 1: " << hand[1] << endl;
        cout << "Total Value: " << hand[1] << " + Hidden" << endl;
    }
    else {
        for(int j = 0; j < numCards; ++j){
            cout << "Card " << j << ": " << hand[j] << endl;
        }        
        cout << "Total Value: " << value << endl;
    }
    
}