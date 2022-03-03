#pragma once

#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include <chrono>
#include <thread>

class Blackjack {

private:
    Deck m_deck;
    Player m_dealer;
    Player m_player;

public:
    Blackjack();
    Player get_player() const;
    Player get_dealer() const;
    void reset_deck();
    void deal_card(Player& player);
    void start_round();
    void print_hand(const Player& player) const;
    unsigned int get_card_value(const Card& card) const;
    unsigned int solve_hand_value(const std::vector<Card>& hand);
    void play_player_round();
    void play_dealer_round();
    void evaluate_round_winner();
    void wait(int seconds) const;
    void start_game();
};