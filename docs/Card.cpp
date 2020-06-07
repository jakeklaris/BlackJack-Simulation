#include <iostream>
#include <string>
#include "Card.h"



using namespace std;


// rank and suit names -- do not remove these
constexpr const char* const Card::RANK_TWO;
constexpr const char* const Card::RANK_THREE;
constexpr const char* const Card::RANK_FOUR;
constexpr const char* const Card::RANK_FIVE;
constexpr const char* const Card::RANK_SIX;
constexpr const char* const Card::RANK_SEVEN;
constexpr const char* const Card::RANK_EIGHT;
constexpr const char* const Card::RANK_NINE;
constexpr const char* const Card::RANK_TEN;
constexpr const char* const Card::RANK_JACK;
constexpr const char* const Card::RANK_QUEEN;
constexpr const char* const Card::RANK_KING;
constexpr const char* const Card::RANK_ACE;

constexpr const char* const Card::SUIT_SPADES;
constexpr const char* const Card::SUIT_HEARTS;
constexpr const char* const Card::SUIT_CLUBS;
constexpr const char* const Card::SUIT_DIAMONDS;

// add your code below

void check_valid_rank(const string &rank){
    bool is_valid = false;
    if((rank == "Two")||(rank == "Three")||(rank == "Four")||(rank == "Five")){
        is_valid = true;
    }
    else if((rank == "Six")||(rank == "Seven")||(rank == "Eight")||(rank == "Nine")){
        is_valid = true;
    }
    else if((rank == "Ten")||(rank == "Jack")||(rank == "Queen")||(rank == "King")){
        is_valid = true;
    }
    else if(rank == "Ace"){
        is_valid = true;
    }

    assert(is_valid);

}

void check_valid_suit(const string &suit){
    assert((suit=="Spades")||(suit=="Hearts")||(suit=="Diamonds")||(suit=="Clubs"));
}


Card::Card() 
 : rank(RANK_TWO), suit(SUIT_SPADES) { }


Card::Card(const string &rank_in, const string &suit_in)
 : rank(rank_in), suit(suit_in) { 
    check_valid_suit(suit_in);
    check_valid_rank(rank_in);
    value = setValue(rank_in);
}

int Card::get_value() const{
    return value;
}

void Card::SetAceValue(const int &AValue){
    assert(AValue == 1 || AValue == 11);
    assert(rank == "Ace");
    value = AValue;
}

int Card::setValue(const string &rank) const{
    if(rank == "Two"){
        return 2;
    }
    else if(rank == "Three"){
        return 3;
    }
    else if(rank == "Four"){
        return 4;      
    }
    else if(rank == "Five"){
        return 5;      
    }
    else if(rank == "Six"){
        return 6;           
    }
    else if(rank == "Seven"){
        return 7;           
    }
    else if(rank == "Eight"){
        return 8;           
    }
    else if(rank == "Nine"){
        return 9;          
    }
    else if(rank == "Ace"){
        return 11;
    }    
    else {
        return 10;
    }
}

bool isBlackJack(const Card &c1, const Card &c2){
    if((c1+c2) == 21){
        return true;
    }
    else{
        return false;
    }
}

bool Card::is_jack() const{
    if(rank == "Jack"){
        return true;
    }
    else{
        return false;
    }
}

string Card::get_rank() const {
    return rank;
}

string Card::get_suit() const {
    return suit;
}


bool Card::is_face() const {
    bool face = false;
    if((rank == ("Jack")) || (rank == "Queen")|| (rank == "King") || (rank == "Ten")) {
        face = true;
    }

    return face;

}

bool Card::is_ace() const{
    if(rank == "Ace"){
        return true;
    }
    else{
        return false;
    }
}




bool operator<(const Card &lhs, const Card &rhs){

    if(lhs.get_value() < rhs.get_value()){
        return true;
    }
    else{
        return false;
    }

}

bool operator>(const Card &lhs, const Card &rhs){
    if(lhs.get_value() > rhs.get_value()){
        return true;
    }
    else{
        return false;
    }

}


bool operator==(const Card &lhs, const Card &rhs){
    if(lhs.get_rank() == rhs.get_rank()){
        return true;
    }
    else{
        return false;
    }

}

bool operator!=(const Card &lhs, const Card &rhs){
    if(lhs.get_rank() != rhs.get_rank()){
        return true;
    }
    else{
        return false;
    }

} 

ostream & operator<<(ostream &os,const Card &card){
    os << card.get_rank() << " of " << card.get_suit() << " : " << card.get_value();
    return os;
}

int operator+(const Card &lhs, const Card &rhs){
    return lhs.get_value() + rhs.get_value();
}
