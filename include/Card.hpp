#pragma once

#include <string>
#include <iostream>

struct Card {

    enum class Rank : unsigned char {
        Ace     = 1,
        Two     = 2,
        Three   = 3,
        Four    = 4,
        Five    = 5,
        Six     = 6,
        Seven   = 7,
        Eight   = 8,
        Nine    = 9,
        Ten     = 10,
        Jack    = 11,
        Queen   = 12,
        King    = 13
    };

    enum class Suit : unsigned char {
        Hearts,
        Diamonds,
        Clubs,
        Spades
    };

    Rank m_rank;
    Suit m_suit;

    Card(const Rank& rank, const Suit& suit);
    std::string suit_to_string() const;
    std::string rank_to_string() const;
    friend bool operator==(const Card& card_1, const Card& card_2);
    friend std::ostream& operator<<(std::ostream& out, const Card& card);

};