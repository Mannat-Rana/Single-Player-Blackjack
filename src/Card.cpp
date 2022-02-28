#include "../include/Card.hpp"

std::ostream& operator<<(std::ostream& out, const Card& card) {
    out << card.m_value << " of " << card.m_suit;
    return out;
} 

Card::Card(const std::string& suit, const std::string& value, bool print) 
: m_suit{suit}, m_value{value} {
    if (print) {
        std::cout << *this << std::endl;
    }
}

std::string Card::get_suit() const {
    return this->m_suit;
}

std::string Card::get_value() const {
    return this->m_value;
}