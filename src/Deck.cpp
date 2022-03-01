#include "../include/Deck.hpp"

std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    out << "Deck with " << deck.m_cards.size() << " cards:\n";
    for (auto&& card : deck.m_cards) {
        out << card << std::endl;
    }
    return out;
}

Deck::Deck() 
: m_shuffled{false} {
    static constexpr auto suits = {
        Card::Suit::Hearts,
        Card::Suit::Diamonds,
        Card::Suit::Clubs,
        Card::Suit::Spades
    };

    static constexpr auto ranks = {
        Card::Rank::Two,
        Card::Rank::Three,
        Card::Rank::Four,
        Card::Rank::Five,
        Card::Rank::Six,
        Card::Rank::Seven,
        Card::Rank::Eight,
        Card::Rank::Nine,
        Card::Rank::Ten,
        Card::Rank::Jack,
        Card::Rank::Queen,
        Card::Rank::King,
        Card::Rank::Ace,
    };

    this->m_cards.clear();
    this->m_cards.reserve(suits.size() * ranks.size());
    for (auto&& suit : suits) {
        for (auto&& rank : ranks) {
            this->m_cards.emplace_back(rank, suit);
        }
    }
}

bool Deck::is_shuffled() const {
    return this->m_shuffled;
}

Card Deck::get_top_card() {
    Card top_card {this->m_cards.back()};
    this->m_cards.pop_back();
    return top_card;
}

void Deck::shuffle() {
    this->m_shuffled = true;
    srand(time(0));
    for (size_t i = 0; i < this->m_cards.size(); i++) {
        size_t random {i + (rand() % (this->m_cards.size() - i))};
        std::swap(this->m_cards.at(i), this->m_cards.at(random));
    }
}