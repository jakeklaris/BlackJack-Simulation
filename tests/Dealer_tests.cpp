#include "Dealer.h"
#include "unit_test_framework.h"
#include <iostream>

using namespace std;


TEST(test_dealer_bankroll){
    Dealer dealer;
    dealer.addMoney();
    dealer.printChips();

}


TEST_MAIN()