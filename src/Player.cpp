#include "../include/Player.hpp"
#include <iostream>

std::string Player::get_name() const {
    return this->m_player_name;
}

std::vector<Card> Player::get_hand() const {
    return this->m_hand;
}

void Player::add_card(const Card& card_to_add) {
    this->m_hand.push_back(card_to_add);
}

void Player::add_win() {
    this->m_rounds_won++;
}

Player::Player(const std::string& input_player_name) 
: m_player_name(input_player_name), m_hand{}, m_hand_value{0}, m_rounds_won{0} {}