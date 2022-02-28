#include "../include/Deck.hpp"

std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    out << "Deck with " << deck.m_deck.size() << " cards:\n";
    for (const auto& card : deck.m_deck) {
        out << card << std::endl;
    }
    return out;
}

Deck::Deck() 
: m_shuffled{false} {
    static const std::array<std::string, 4> suit_names {"Spades", "Clubs", "Hearts", "Diamonds"};
    static const std::array<std::string, 13> value_names {"2", "3", "4", "5", "6", "7", "8", "9", "10",
                                                          "Jack", "Queen", "King", "Ace"};
    for (const auto& suit : suit_names) {
        for (const auto& value : value_names) {
            this->m_deck.push_back(Card{suit, value});
        }
    }
}

bool Deck::is_shuffled() const {
    return this->m_shuffled;
}

Card Deck::get_top_card() {
    Card top_card {this->m_deck.back()};
    this->m_deck.pop_back();
    return top_card;
}

void Deck::shuffle() {
    this->m_shuffled = true;
    srand(time(0));
    for (size_t i = 0; i < this->m_deck.size(); i++) {
        size_t random {i + (rand() % (this->m_deck.size() - i))};
        std::swap(this->m_deck.at(i), this->m_deck.at(random));
    }
}