#ifndef CHIPS_H
#define CHIPS_H
#include <iostream>
#include <string>
#include <vector>

class Chip {
 public:
    //Constructor 
    Chip();
    Chip(const int &value_in, const std::string &color_in);

    //gets value
    int get_value() const;

    //gets color
    std::string get_color() const;


 private:
    int value;
    std::string color;
};


//Value : 10
class BlueChip : public Chip{
 public:
    //Constructor 
    BlueChip();

};

//Value : 5
class RedChip : public Chip{
 public:   
    //Constructor 
    RedChip();
};

//Value : 25
class GreenChip : public Chip{
 public:   
    //Constructor 
    GreenChip();
};

//Value : 1
class WhiteChip : public Chip{
 public:  
    //Constructor 
    WhiteChip();
};

//Value : 100
class BlackChip : public Chip{
  public:  
    //Constructor 
    BlackChip();
};


//operator overload 
int operator+(const Chip &lhs, const Chip &rhs);

int totalValue(const std::vector <Chip> &chips);

//operator overload
int operator+(const int &num, const Chip &rhs);

//operator overload 
int operator+(const Chip &lhs, const int &num);

//prints summary of chips in hand 
void printChipSummary(const std::vector <Chip> &chips);

bool operator==(const Chip &lhs, const Chip &rhs);

#endif