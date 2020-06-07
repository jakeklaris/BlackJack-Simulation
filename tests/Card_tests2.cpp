#include "Card.h"
#include "unit_test_framework.h"
#include <iostream>

using namespace std;

TEST(test_card_ctor) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::RANK_ACE, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit());
    ASSERT_EQUAL(11,c.get_value());
    c.SetAceValue(1);
    ASSERT_EQUAL(1,c.get_value());
}


// Add more test cases here

TEST(test_card_ctor_default){
    Card c("King", "Spades");
    ASSERT_EQUAL(Card::SUIT_SPADES, c.get_suit());
    ASSERT_EQUAL(Card::RANK_KING,c.get_rank());
    ASSERT_EQUAL(10,c.get_value());
}

TEST(test_operator_plus){
    Card c("King", "Spades");
    Card c2(Card::RANK_ACE, Card::SUIT_HEARTS);    

    int add = c + c2;
    ASSERT_EQUAL(21,add);

}

// TEST(test_get_rank){
//     Card c("Jack", "Diamonds");
//     Card c2("Two", "Clubs");
//     ASSERT_EQUAL(Card::RANK_JACK, c.get_rank());
//     ASSERT_EQUAL(Card::RANK_TWO,c2.get_rank());
// }

// TEST(test_get_suit){
//     Card c("Jack", "Diamonds");
//     Card c2("Two", "Clubs");
//     ASSERT_EQUAL(Card::SUIT_DIAMONDS, c.get_suit());
//     ASSERT_EQUAL(Card::SUIT_CLUBS,c2.get_suit());

// }



// TEST(test_is_face){
//     Card c("Jack", "Hearts");
//     Card c2("Nine", "Diamonds");
//     Card c3("Ace","Clubs");
//     ASSERT_TRUE(c.is_face());
//     ASSERT_FALSE(c2.is_face());
//     ASSERT_TRUE(c3.is_face());
// }



// TEST(test_operator_less){
//     Card c1("Jack", "Spades");
//     Card c2("Two", "Spades"); 
//     Card c3("Jack", "Hearts");
//     Card c4("Jack", "Diamonds");
//     Card c5("Jack","Clubs");
//     Card c6("Nine", "Diamonds");  
//     Card c7("King", "Spades");

//     ASSERT_TRUE(c3 < c7);
//     ASSERT_TRUE(c1 < c5);
//     ASSERT_TRUE(c2 < c4);
//     ASSERT_TRUE(c6 < c3);
//     ASSERT_TRUE(c5 < c4);//Error
//     ASSERT_FALSE(c7 < c3);
//     ASSERT_FALSE(c3 < c2);
//     ASSERT_FALSE(c6 < c2);
//     ASSERT_FALSE(c4 < c1);

// }

// TEST(test_operator_greater){
//     Card c1("Jack", "Spades");
//     Card c2("Two", "Spades"); 
//     Card c3("Jack", "Hearts");
//     Card c4("Jack", "Diamonds");
//     Card c5("Jack","Clubs");
//     Card c6("Nine", "Diamonds");  
//     Card c7("King", "Spades");

//     ASSERT_FALSE(c3 > c7);
//     ASSERT_FALSE(c1 > c5);
//     ASSERT_FALSE(c2 > c4);
//     ASSERT_FALSE(c6 > c3);
//     ASSERT_FALSE(c5 > c4);
//     ASSERT_TRUE(c7 > c3);
//     ASSERT_TRUE(c3 > c2);
//     ASSERT_TRUE(c6 > c2);
//     ASSERT_TRUE(c4 > c1);
// }

// TEST(test_operator_equal){
//     Card c1("Jack", "Spades");
//     Card c2("King", "Spades"); 
//     Card c3("Nine", "Diamonds");
//     Card c4("Jack","Clubs");
//     Card c5("Nine", "Diamonds");  
//     Card c6("King", "Spades");

//     ASSERT_TRUE(c2 == c6);
//     ASSERT_TRUE(c5 == c3);
//     ASSERT_FALSE(c1 == c4);
//     ASSERT_FALSE(c1 == c2);
// }

// TEST(test_operator_not_equal){
//     Card c1("Jack", "Spades");
//     Card c2("King", "Spades"); 
//     Card c3("Nine", "Diamonds");
//     Card c4("Jack","Clubs");
//     Card c5("Nine", "Diamonds");  
//     Card c6("King", "Spades");

//     ASSERT_FALSE(c2 != c6);
//     ASSERT_FALSE(c5 != c3);
//     ASSERT_TRUE(c1 != c4);
//     ASSERT_TRUE(c1 != c2);

// }

// TEST(test_os_operator){

//     Card c1("Jack", "Spades");
//     Card c2("Two", "Diamonds");
//     ostringstream os;
//     ostringstream os2;
//     string correct = "Jack of Spades";
//     string correct2 = "Two of Diamonds";

//     os << c1;
//     ASSERT_EQUAL(os.str(), correct);
//     os2 << c2;
//     ASSERT_EQUAL(os2.str(), correct2);
    

// }



TEST_MAIN()
