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

void Player::set_name(const std::string& input_name) {
    this->m_player_name = input_name;
}

void Player::set_hand_value(unsigned int hand_val) {
    this->m_hand_value = hand_val;
}

unsigned char Player::get_hand_value() const {
    return this->m_hand_value;
}

unsigned int Player::get_rounds_won() const {
    return this->m_rounds_won;
}

void Player::clear_hand() {
    this->m_hand.clear();
}

Player::Player() 
: m_player_name{}, m_hand{}, m_hand_value{0}, m_rounds_won{0} {}