#ifndef BANKROLL_H
#define BANKROLL_H
#include <iostream>
#include <string>
#include <vector>
#include "Chips.h"
#include <cassert>

class Bankroll{
 public:
    //Constructor
    Bankroll();

    void printChips();
    
    int getChipValue();

    //EFFECTS: Adds Chip
    //specific chip object (chip1)
    void addChip(const Chip &c);
    //color of the chip
    void addChip(const std::string &color);
    //value of the chip
    void addChip(const int &value);

    //get into game with a cetain amount of chips 
    void buyIn(const int &amount);

    //get change for a certain colored chip in some other chip 
    //void getChange(const std::string &oldChip, const std::string &newChip);

    //EFFECTS: Lose Chip
    void loseChip(const Chip &c);
    void loseChip(const std::string &color);
    void loseChip(const int &value);


    void winBet(const int &betAmount);
    void loseBet(const int &betAmount);
    void winBlackJack(const int &betAmount);
    
 private: 
    int chipValue;
    int chipCount;
    std::vector <Chip> chips;

};


void checkColor(const std::string &color);
void checkValue(const int &value);






#endif