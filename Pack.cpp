#include <cassert>
#include <iostream>
#include <string>
#include "Packn.h"
#include "Card.h"
#include <cassert>
#include <array>

using namespace std;

const char * const * getRankPtr(const Card &c2){
    const char * const * ptr4 = RANK_NAMES_BY_WEIGHT;
    if(c2.get_rank() == "Three"){
        ptr4 += 1;
    }
    else if(c2.get_rank() == "Four"){
        ptr4 += 2;
    }
    else if(c2.get_rank() == "Five"){
        ptr4 += 3;
    }   
    else if(c2.get_rank() == "Six"){
        ptr4 += 4;
    }
    else if(c2.get_rank() == "Seven"){
        ptr4 += 5;
    }
    else if(c2.get_rank() == "Eight"){
        ptr4 += 6;
    }
    else if(c2.get_rank() == "Nine"){
        ptr4 += 7;
    }
    else if(c2.get_rank() == "Ten"){
        ptr4 += 8;
    }
    else if(c2.get_rank() == "Jack"){
        ptr4 += 9;
    }
    else if(c2.get_rank() == "Queen"){
        ptr4 += 10;
    }
    else if(c2.get_rank() == "King"){
        ptr4 += 11;
    }
    else if(c2.get_rank() == "Ace"){
        ptr4 += 12;
    }
    return ptr4;
}

const char * const * getSuitPtr(const Card &c){
    const char * const * ptr1 = SUIT_NAMES_BY_WEIGHT;
 
    if(c.get_suit() == "Hearts"){
        ptr1 += 1;
    }
    else if(c.get_suit() == "Clubs"){
        ptr1 += 2;
    }
    else if(c.get_suit() == "Diamonds"){
        ptr1 += 3;
    }

    return ptr1;
}

void Pack::printPack(){
    for(int i = 0; i < 208; ++i){
        cout << "Card " << i << ": " << cards[i] << endl;
    }
}


Pack::Pack() : packSize(208), next(0) {
    Card c1("Two", "Spades");

    const char * const * rankPtr = getRankPtr(c1);
    const char * const * suitPtr = getSuitPtr(c1);

    int index = 0;

    for(int i = 0; i < 4; ++i){
        rankPtr = getRankPtr(c1);
        suitPtr = getSuitPtr(c1);
        for(int suit = 0; suit < 4; ++suit){
            for(int rank = 0; rank < 13; ++rank){
                Card cTemp(*(rankPtr + rank),*(suitPtr + suit));
                cards[index] = cTemp;
                ++index;
            }
        }
    }

}

Pack::Pack(const int &size_in, istream &pack_input) : packSize(size_in), next(0) {

    string rank, word, suit;

    for(int i = 0; i < size_in; ++i){
        pack_input >> rank >> word >> suit;
        Card c(rank,suit);
        cards[i] = c;
    }

}

Card Pack::deal_one(){
    Card c;
    c = cards[next];
    if(empty()){
        reset();
    }
    else{
        ++next;
    }
    return c;
}

void Pack::reset(){
    next = 0;
}

void Pack::shuffle(const int &numShuff){

    array<Card, 208> newCards;
    
    for(int z = 0; z < numShuff; ++z){
        for(int i = 0; i < 7; ++i){
            int j = 1;
            for(int front = 0; front < 104; ++front){
                newCards[j] = cards[front];
                j += 2;
            }
            int k = 0;
            for (int back = 104; back < 208; ++back){
                newCards[k] = cards[back];
                k += 2;
            }
            cards = newCards;
        }
        reset();
    }
    reset();
}
  
bool Pack::empty() const{
    if(next > (packSize - 1)){
        return true;
    }
    else {
        return false;
    }
}
