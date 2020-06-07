#ifndef DEALER_H
#define DEALER_H

#include "Bankroll.h"
#include "Packn.h"
#include <iostream>
#include <string>
#include <vector>
#include "Hand.h"


class Dealer{

 public:
   
   //constructor
   Dealer();

   const std::string & get_name();

   void printHand();

   void printChips();

   bool hit();

   void addMoney();

   //virtual void double();
   //virtual void split();

   virtual ~Dealer() {}

 private:
   std::string name;
   Hand hand;
   Bankroll bankroll;

};




#endif