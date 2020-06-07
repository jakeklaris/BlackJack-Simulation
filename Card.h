#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>


class Card {
public:
  // rank and suit names
  static constexpr const char* const RANK_TWO = "Two";
  static constexpr const char* const RANK_THREE = "Three";
  static constexpr const char* const RANK_FOUR = "Four";
  static constexpr const char* const RANK_FIVE = "Five";
  static constexpr const char* const RANK_SIX = "Six";
  static constexpr const char* const RANK_SEVEN = "Seven";
  static constexpr const char* const RANK_EIGHT = "Eight";
  static constexpr const char* const RANK_NINE = "Nine";
  static constexpr const char* const RANK_TEN = "Ten";
  static constexpr const char* const RANK_JACK = "Jack";
  static constexpr const char* const RANK_QUEEN = "Queen";
  static constexpr const char* const RANK_KING = "King";
  static constexpr const char* const RANK_ACE = "Ace";

  static constexpr const char* const SUIT_SPADES = "Spades";
  static constexpr const char* const SUIT_HEARTS = "Hearts";
  static constexpr const char* const SUIT_CLUBS = "Clubs";
  static constexpr const char* const SUIT_DIAMONDS = "Diamonds";

  //EFFECTS Initializes Card to the Two of Spades
  Card();

  //REQUIRES rank is one of "Two", "Three", "Four", "Five", "Six", "Seven",
  //  "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"
  //  suit is one of "Spades", "Hearts", "Clubs", "Diamonds"
  //EFFECTS Initializes Card to specified rank and suit
  Card(const std::string &rank_in, const std::string &suit_in);

  //EFFECTS Returns the rank
  std::string get_rank() const;

  //EFFECTS Returns the suit.  Does not consider trump.
  std::string get_suit() const;
  
  //EFFECTS sets the value of a card
  int setValue(const std::string &rank) const;

  //EFFECTS sets aces value to 1 or 11 depedning on input
  void SetAceValue(const int &AValue);

  //EFFECTS: Returns the value of the card.
  int get_value() const;

  //EFFECTS Returns true if card is a face card (Ten, Jack, Queen, King)
  bool is_face() const;

  //EFFECTS Returns true if card is Ace
  bool is_ace() const;

  bool is_jack() const;

private:
  std::string rank;
  std::string suit;
  int value;

};

// Suits in order from lowest suit to highest suit.
constexpr const char* const SUIT_NAMES_BY_WEIGHT[] = {
  Card::SUIT_SPADES,
  Card::SUIT_HEARTS,
  Card::SUIT_CLUBS,
  Card::SUIT_DIAMONDS
};
const int NUM_SUITS = 4;

// Ranks in order from lowest rank to highest rank.
constexpr const char* const RANK_NAMES_BY_WEIGHT[] = {
  Card::RANK_TWO,
  Card::RANK_THREE,
  Card::RANK_FOUR,
  Card::RANK_FIVE,
  Card::RANK_SIX,
  Card::RANK_SEVEN,
  Card::RANK_EIGHT,
  Card::RANK_NINE,
  Card::RANK_TEN,
  Card::RANK_JACK,
  Card::RANK_QUEEN,
  Card::RANK_KING,
  Card::RANK_ACE
};
const int NUM_RANKS = 13;


//EFFECTS: Checks requires clause for initialization
void check_valid_rank(const std::string &rank);

//EFFECTS: checks the suit is valid
void check_valid_suit(const std::string &suit);


//EFFECTS Returns true if lhs is lower value than rhs.
//  Does not consider trump.
bool operator<(const Card &lhs, const Card &rhs);

//EFFECTS Returns true if lhs is higher value than rhs.
//  Does not consider trump.
bool operator>(const Card &lhs, const Card &rhs);

//EFFECTS Returns true if lhs is same card as rhs.
//  Does not consider trump.
bool operator==(const Card &lhs, const Card &rhs);

//EFFECTS Returns true if lhs is not the same card as rhs.
//  Does not consider trump.
bool operator!=(const Card &lhs, const Card &rhs);

//EFFECTS Returns the combined value of two cards
int operator+(const Card &lhs, const Card &rhs);

//EFFECTS Returns true if cards add to 21
bool isBlackJack(const Card &c1, const Card &c2);


//EFFECTS Prints Card to stream, for example "Two of Spades"
std::ostream & operator<<(std::ostream &os, const Card &card);



#endif
