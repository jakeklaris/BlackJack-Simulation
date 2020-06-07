#include <iostream>
#include "Chips.h"
#include <string>
#include <cmath>


using namespace std;

Chip::Chip() : value(0), color("Orange") {}
Chip::Chip(const int &value_in, const string &color_in)
    : value(value_in), color(color_in) {}

int Chip::get_value() const {
    return value;
}

string Chip::get_color() const {
    return color;
}

BlueChip::BlueChip() : Chip(10,"Blue"){}

RedChip::RedChip() : Chip(5,"Red") {}

GreenChip::GreenChip() : Chip(25, "Green") {}

WhiteChip::WhiteChip() : Chip(1, "White") {}

BlackChip::BlackChip() : Chip(100, "Black") {}


int operator+(const Chip &lhs, const Chip &rhs) {
    return (lhs.get_value() + rhs.get_value());
}

int operator+(const int &num, const Chip &rhs){
    return (num + rhs.get_value());
}

int operator+(const Chip &lhs, const int &num){
    return(lhs.get_value() + num);
}

int totalValue(const vector <Chip> &chips){
    int total = 0;

    for(int i = 0; i < chips.size(); ++i){
        total += chips[i].get_value();
    }

    return total;
}

void printChipSummary(const vector <Chip> &chips){
    int whiteCount = 0, redCount = 0, blueCount = 0, greenCount = 0, blackCount = 0;
    int whiteValue = 0, redValue = 0, blueValue = 0, greenValue = 0, blackValue = 0;
    int total = 0;
    for(int i = 0; i < chips.size(); ++i) {
        if(chips[i].get_color() == "White"){
            ++whiteCount;
        }
        else if(chips[i].get_color() == "Red"){
            ++redCount;
        }
        else if(chips[i].get_color() == "Blue"){
            ++blueCount;
        }
        else if(chips[i].get_color() == "Green"){
            ++greenCount;
        }
        else if(chips[i].get_color() == "Black"){
            ++blackCount;
        }
        else {

        }
    }

    whiteValue = (whiteCount * 1);
    redValue = (redCount * 5);
    blueValue = (blueCount * 10);
    greenValue = (greenCount * 25);
    blackValue = (blackCount * 100);
    total = (whiteValue + redValue + blueValue + greenValue + blackValue);

    cout << "Chip Summary: " << endl;
    cout << "Number of White Chips (Total White Chip Value): " << whiteCount << " ("
         << whiteValue << "$)" << endl;
    cout << "Number of Red Chips (Total Red Chip Value): " << redCount << " ("
         << redValue << "$)" << endl;
    cout << "Number of Blue Chips (Total Blue Chip Value): " << blueCount << " ("
         << blueValue << "$)" << endl;
    cout << "Number of Green Chips (Total Green Chip Value): " << greenCount << " ("
         << greenValue << "$)" << endl;
    cout << "Number of Black Chips (Total Black Chip Value): " << blackCount << " ("
         << blackValue << "$)" << endl;
    cout << "Total Value of Chips: " << total << "$" << endl;

}

bool operator==(const Chip &lhs, const Chip &rhs){
    if(lhs.get_value() == rhs.get_value()){
        return true;
    }
    else{
        return false;
    }
}