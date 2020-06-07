#include "Packn.h"
#include "unit_test_framework.h"
#include <iostream>

using namespace std;

// TEST(test){
//     Pack pack;
//     pack.printPack();
// }

TEST(test_shuffle){
    Pack pack;
    pack.shuffle(4);
    pack.printPack();
}

TEST_MAIN()
