#pragma once

#include "Card.hpp"
#include <vector>
#include <array>

class Deck {

friend std::ostream& operator<<(std::ostream& out, const Deck& deck);

private:
    std::vector<Card> m_cards;
    bool m_shuffled;

public:
    Deck();
    std::vector<Card> get_deck() const;
    bool is_shuffled() const;
    Card get_top_card();
    void shuffle();
};