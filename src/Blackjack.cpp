#include "../include/Blackjack.hpp"
#include <string>

Blackjack::Blackjack()
: m_deck{}, m_dealer("Dealer") {
    std::cout << "Welcome to the game of Blackjack, please enter your name to play: ";
    std::string input_player_name{};
    std::cin >> input_player_name;
    this->m_player{input_player_name};
    this->m_deck.shuffle();
}

Player Blackjack::get_player() const {
    return m_player;
}

Player Blackjack::get_dealer() const {
    return m_dealer;
}

void Blackjack::reset_deck() {
    this->m_deck = Deck{};
    this->m_deck.shuffle();
}

void Blackjack::deal_card(Player& player) {
    if (!this->m_deck) {
        std::cout << "No cards remain, resetting deck...\n";
        this->reset_deck();
    }    
    m_player.add_card(this->m_deck.get_top_card());
}