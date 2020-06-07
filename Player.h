#ifndef PLAYER_H
#define PLAYER_H

#include "Bankroll.h"
#include "Packn.h"
#include <iostream>
#include <string>
#include <vector>
#include "Hand.h"


class Player{

 public:

   virtual const std::string & get_name() const = 0;

   virtual void bet(const int &betAmount) = 0;

   virtual bool hit(const Card &upcard, const int &numCards) = 0;

   virtual void buyIn() = 0;

   virtual void doubleDown() = 0;

    //Prints Players Hands
   virtual void printHand() = 0;

    //Prints summary of players chips
   virtual void printChips() = 0;
   

   //virtual void double();
   //virtual void split();

   virtual ~Player() {}

};

//EFFECTS: Returns a pointer to a player with the given name and strategy
//To create an object that won't go out of scope when the function returns,
//use "return new Simple(name)" or "return new Human(name)"
//Don't forget to call "delete" on each Player* after the game is over
Player * Player_factory(const std::string &name, const std::string &playerType);

//EFFECTS: Prints player's name to os
std::ostream & operator<<(std::ostream &os, const Player &p);




#endif