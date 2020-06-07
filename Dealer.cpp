#include "Dealer.h"
#include <iostream>
#include <vector>
#include <string>
#include "Hand.h"
#include "Bankroll.h"

using namespace std;

//bankroll set to 0, hand set to empty
Dealer::Dealer() : name("Dealer"), hand(), bankroll() {}


const string& Dealer::get_name(){
    return name;
}

void Dealer::printHand(){
    hand.printDealerHand();
}

void Dealer::addMoney(){

    //400 Whites
    for(int i = 0; i < 100; ++i){
        bankroll.buyIn(4);
    }
    //200 reds
    for(int i = 0; i < 200; ++i){
        bankroll.buyIn(5);
    }
    //200 Blues 
    for(int i = 0; i < 200; ++i){
        bankroll.buyIn(10);
    }
    //200 greens 
    for(int i = 0; i < 100; ++i){
        bankroll.buyIn(50);
    }
    //200 blacks
    for(int i = 0; i < 10; ++i){
        bankroll.buyIn(2000);
    }    
 
}

void Dealer::printChips(){

    bankroll.printChips();
 
}



bool Dealer::hit(){
    if(hand.getValue() >= 17){
        return false;
    }
    else{
        return true;
    }
}

