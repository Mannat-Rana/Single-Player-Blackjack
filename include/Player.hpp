#pragma once

#include "Card.hpp"
#include "Deck.hpp"
#include <vector>
#include <string>

class Player {

private:
    unsigned char m_hand_value;
    unsigned int m_rounds_won;
    std::string m_player_name;
    std::vector<Card> m_hand;

public:
    std::string get_name() const;
    std::vector<Card> get_hand() const;
    void add_card(const Card& card_to_add);
    void add_win();
    void set_name(const std::string& input_name);
    void set_hand_value(unsigned int);
    unsigned char get_hand_value() const;
    unsigned int get_rounds_won() const;
    void clear_hand();
    Player();
};