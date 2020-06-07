#include "Player.h"
#include <iostream>
#include <vector>
#include <string>
#include "Hand.h"
#include "Bankroll.h"
#include "Packn.h"
#include <cassert>

using namespace std;


class CPU : public Player{

 public:
   //constructor
   CPU(const string &name_in);

    //gets players name 
   const string & get_name() const override;

    //returns bet amount
   int getBetAmount();

    //bets a certain amount
   void bet(const int &betAmountIn) override;

    //Returns true if player wants to hit
   bool hit(const Card &upcard, const int &numCards) override;

    //Buy in for a certain amount
   void buyIn() override;

   void doubleDown() override;

    //Prints Players Hands
   void printHand() override;

    //Prints summary of players chips
   void printChips() override;

    //Destructor
   ~CPU() {}

 private:
   string name;
   Hand hand;
   Bankroll bankroll;
   int betAmount;

};

class Human : public Player{

 public:
   //constructor
   Human(const string &name_in);

    //gets players name 
   const string & get_name() const override;

    //returns bet amount
   int getBetAmount();

    //bets a certain amount
   void bet(const int &betAmountIn) override;

    //Returns true if player wants to hit
   bool hit(const Card &upcard, const int &numCards) override;

    //Buy in for a certain amount
   void buyIn() override;

   void doubleDown() override;

    //Prints Players Hands
   void printHand() override;

    //Prints summary of players chips
   void printChips() override;

    //Destructor
   ~Human() {}

 private:
   string name;
   Hand hand;
   Bankroll bankroll;
   int betAmount;

};


Human::Human(const string &name_in) : name(name_in), hand(), bankroll(), betAmount(0){}

const string & Human::get_name() const{
    return name;
}

//returns bet amount
int Human::getBetAmount(){
    return betAmount;
}

//bets a certain amount
void Human::bet(const int &betAmountIn) {
    printHand();
    cout << get_name() << ", How much would you like to bet? " << endl;
    cout << "Please type in denominations of 5 Chips" << endl;
    printChips();
    int bet;
    cin >> bet;
    assert(bet < bankroll.getChipValue());
    betAmount = bet;
}

//Returns true if player wants to hit
bool Human::hit(const Card &upcard, const int &numCards) {
    printHand();
    cout << "Dealer's upcard: " << upcard << endl;
    cout << "Would you like to hit? (Yes or No)" << endl;
    string hit;
    cin >> hit;
    assert(hit == "Yes" || hit == "No");
    if(hit == "Yes"){
        return true;
    }
    else{// hit == No
        return false;
    }
}

//Buy in for a certain amount
void Human::buyIn() {
    cout << "How much ($) would you like to buy in for? " << endl;
    int amount;
    cin >> amount;
    bankroll.buyIn(amount);
}

void Human::doubleDown() {
    betAmount *= 2;
}

//Prints Players Hands
void Human::printHand() {
    hand.printHand();
}

//Prints summary of players chips
void Human::printChips() {
    bankroll.printChips();
}



CPU::CPU(const string &name_in) : name (name_in), hand(), bankroll(), betAmount(0) {}


const string & CPU::get_name() const{
    return name;
}

int CPU::getBetAmount(){
    return betAmount;
}

void CPU::doubleDown(){
    betAmount *= 2;
}

void CPU::bet(const int &betAmountIn){
    betAmount = betAmountIn;
}

bool CPU::hit(const Card &upcard, const int &numCards){
    if(numCards == 2){// First round of hitting/Standing
        if(!hand.hasAce()){//No ace in hand 
            if(hand.getValue() <= 8 ){ return true; }
            else if(hand.getValue() == 9){
                if(upcard.get_value() >= 3 && upcard.get_value() <= 6){
                    doubleDown();
                    return true;
                }
                else{ //2, 7-A
                    return true;
                }
            }
            else if(hand.getValue() == 10){
                if(upcard.get_value() > 9){ return true; }
                else{
                    doubleDown();
                    return true;
                }
            }
            else if(hand.getValue() == 11){
                if(upcard.get_value() == 11){ return true; }
                else{
                    doubleDown();
                    return true;
                }
            }            
            else if(hand.getValue() == 12){
                if(upcard.get_value() >= 4 && upcard.get_value() <= 6){
                    return false;
                }
                else{ //2-3, 7-A
                    return true;
                }                
            }
            else if(hand.getValue() >= 13 && hand.getValue() <= 16){
                if(upcard.get_value() <= 6){
                    return false;
                }
                else{ return true; }
            }
            else { //greater than 17 (17-21)
                return false;
            }
        }
        else{//has Ace (soft situation)
            if(hand.getValue() <=14){ //13 or 14
                if(upcard.get_value() == 5 || upcard.get_value() == 6){
                    doubleDown();
                    return true;
                }
                else{ return true;}
            }
            else if(hand.getValue() == 15 || hand.getValue() == 16){//15 or 16
                if(upcard.get_value() >= 4 && upcard.get_value() <= 6){
                    doubleDown();
                    return true;
                }
                else{ return true;}
            }
            else if(hand.getValue() == 17){//17
                if(upcard.get_value() >= 3 && upcard.get_value() <= 6){
                    doubleDown();
                    return true;
                }
                else{ return true; }
            }
            else if(hand.getValue() == 18){//18
                if(upcard.get_value() >= 9){ return true; }
                else if(upcard.get_value() >= 3 && upcard.get_value() <= 6){
                    doubleDown();
                    return true;
                }
                else{ return false;}
            }
            else {// 19-20
                return false;
            }
        }
    }
    else{//more than 2 cards
        if(hand.getValue() <= 11 ){ return true; }      
        else if(hand.getValue() == 12){
            if(upcard.get_value() >= 4 && upcard.get_value() <= 6){
                return false;
            }
            else{ //2-3, 7-A
                return true;
            }                
        }
        else if(hand.getValue() >= 13 && hand.getValue() <= 16){
            if(upcard.get_value() <= 6){ return false; }
            else{ return true; }
        }
        else { //greater than 17 (17-21)
            return false;
        }
    }
}

void CPU::buyIn(){
    //Green Chips: 100 (2500$)
    for(int i = 0; i < 50; ++i){
        bankroll.buyIn(50);
    }

}

void CPU::printChips(){
    bankroll.printChips();
}

void CPU::printHand(){
    hand.printHand();
}



Player * Player_factory(const string &name, const string &playerType){

    if(playerType == "CPU"){
        return new CPU(name);
    }
    else if(playerType == "Human"){
        return new Human(name);
    }
    else {
        assert(false);
        return nullptr;
    }
}


ostream & operator<<(ostream &os, const Player &p){
    os << p.get_name();
    return os;

}