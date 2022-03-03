#include "../include/Card.hpp"

Card::Card(const Rank& rank, const Suit& suit) 
: m_rank{rank}, m_suit{suit} {};

Card::Rank Card::get_rank() const {
    return m_rank;
}

std::string Card::suit_to_string() const {
    switch(this->m_suit) {
        case Suit::Hearts:
            return "Hearts";
        case Suit::Diamonds:
            return "Diamonds";
        case Suit::Clubs:
            return "Clubs";
        default:
            return "Spades";
    }
}

std::string Card::rank_to_string() const {
    switch(this->m_rank) {
        case Rank::Ace:
            return "Ace";
        case Rank::Jack:
            return "Jack";
        case Rank::Queen:
            return "Queen";
        case Rank::King:
            return "King";
        default:
            return std::to_string(static_cast<int>(this->m_rank));
    }
}

bool operator==(const Card& card_1, const Card& card_2) {
    return ((card_1.m_rank == card_2.m_rank) && (card_1.m_suit == card_2.m_suit));
}

std::ostream& operator<<(std::ostream& out, const Card& card) {
    out << card.rank_to_string() << " of " << card.suit_to_string() << ".\n";
    return out;
}
