#include <iostream>
#include <string>
#include <vector>
#include "Bankroll.h"

using namespace std;



Bankroll::Bankroll() : chipValue(0), chipCount(0) {}


void Bankroll::addChip(const Chip &c) {
    chips.push_back(c);
    ++chipCount;
    chipValue += c.get_value();
}

void checkColor(const string &color){
    assert(color == "White" || color == "Red" || color == "Blue"|| color == "Green" || color == "Black");
}

int Bankroll::getChipValue(){
    return chipValue;
}

//void getChange(const string &oldChip, const string &newChip){}

void Bankroll::buyIn(const int &amount){
    int value = amount;

    while(value > .99){
        if(value >= 100){
            addChip(100);
            value -= 100;
        }
        else if(amount >= 25){
            addChip(25);
            value -= 25;
        }
        else if(amount >= 10){
            addChip(10);
            value -= 10;
        }
        else if(amount >= 5){
            addChip(5);
            value -= 5;
        }
        else { // 1$
            addChip(1);
            value -= 1;
        }
    }    

}

void Bankroll::printChips(){
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

void Bankroll::addChip(const string &color){
    checkColor(color);
    Chip c;
    if(color == "White"){   
        WhiteChip w1;
        c = w1;
    }
    else if(color == "Red"){
        RedChip r1;
        c = r1;
    }
    else if(color == "Blue"){
        BlueChip b1;
        c = b1;
    }
    else if(color == "Green"){
        GreenChip g1;
        c = g1;
    }
    else {
        BlackChip bl1;
        c = bl1;
    }

    chips.push_back(c);
    chipValue += c.get_value();
    ++chipCount;

}

void checkValue(const int &value){
    assert(value == 1 || value == 5 || value == 10 || value == 25 || value == 100);
}

void Bankroll::addChip(const int &value){
    checkValue(value);
    Chip c;
    if(value == 1){   
        WhiteChip w1;
        c = w1;
    }
    else if(value == 5){
        RedChip r1;
        c = r1;
    }
    else if(value == 10){
        BlueChip b1;
        c = b1;
    }
    else if(value == 25){
        GreenChip g1;
        c = g1;
    }
    else {
        BlackChip bl1;
        c = bl1;
    }    

    chips.push_back(c);
    chipValue += c.get_value();
    ++chipCount;
}




void Bankroll::loseChip(const string &color){
    int index = 0;
    for(int i = 0; i < chipCount; ++i){
        if(color == chips[i].get_color()){
            index = i;
            break;
        }
    }

    chips.erase(chips.begin() + index);
    chipValue -= chips[index].get_value();
    --chipCount;
}


void Bankroll::loseChip(const Chip &c){
    int index = 0;
    for(int i = 0; i < chipCount; ++i){
        if(c == chips[i]){
            index = i;
            break;
        }
    }    

    chips.erase(chips.begin() + index);
    chipValue -= chips[index].get_value();
    --chipCount;   

}

void Bankroll::loseChip(const int &value){
    int index = 0;
    for(int i = 0; i < chipCount; ++i){
        if(value == chips[i].get_value()){
            index = i;
            break;
        }
    }    

    chips.erase(chips.begin() + index);
    chipValue -= chips[index].get_value();
    --chipCount;       
}

void Bankroll::winBet(const int &betAmount){
    int amount = betAmount;

    while(amount > .99){
        if(amount >= 100){
            addChip(100);
            amount -= 100;
        }
        else if(amount >= 25){
            addChip(25);
            amount -= 25;
        }
        else if(amount >= 10){
            addChip(10);
            amount -= 10;
        }
        else if(amount >= 5){
            addChip(5);
            amount -= 5;
        }
        else { // 1$
            addChip(1);
            amount -= 1;
        }
    }

}

void Bankroll::loseBet(const int &betAmount){
    int amount = betAmount;
    while(amount > .99){
        if(amount >= 100){
            loseChip(100);
            amount -= 100;
        }
        else if(amount >= 25){
            loseChip(25);
            amount -= 25;
        }
        else if(amount >= 10){
            loseChip(10);
            amount -= 10;
        }
        else if(amount >= 5){
            loseChip(5);
            amount -= 5;
        }
        else { // 1$
            loseChip(1);
            amount -= 1;
        }        
    }

}


void Bankroll::winBlackJack(const int &betAmount){
    int win = (betAmount * 1.5);
    winBet(win);
}