#include "Bankroll.h"
#include "unit_test_framework.h"
#include <iostream>
#include <vector>

using namespace std;

TEST(test_bankroll){
    Bankroll money;
    money.buyIn(150);
    money.printChips();
    money.loseBet(50);
    money.printChips();
    money.winBet(500);
    money.printChips();
}

TEST_MAIN()
