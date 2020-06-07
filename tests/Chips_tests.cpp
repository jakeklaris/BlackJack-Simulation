#include "Chips.h"
#include "unit_test_framework.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static vector<Chip> addChips(){
    vector <Chip> chips;
    BlueChip b1;
    chips.push_back(b1);
    BlueChip b2;
    chips.push_back(b2);
    BlueChip b3;   
    chips.push_back(b3);
    RedChip r1;
    chips.push_back(r1);
    RedChip r2;
    chips.push_back(r2);
    WhiteChip w1;
    chips.push_back(w1);
    WhiteChip w2;    
    chips.push_back(w2);
    BlackChip bl1;
    chips.push_back(bl1);
    GreenChip g1;
    chips.push_back(g1);

    return chips;
}




TEST(test_chip_values) {
    vector <Chip> chips = addChips();
    printChipSummary(chips);
}



TEST_MAIN()
