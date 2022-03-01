#pragma once

#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"

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
    void deal_card();
    void start_round();
};