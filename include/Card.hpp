#pragma once

#include <string>
#include <iostream>

class Card {

friend std::ostream& operator<<(std::ostream& out, const Card& card); 

private:
    std::string m_suit;
    std::string m_value;

public:
    Card(const std::string& suit, const std::string& value, bool print=false);
    std::string get_suit() const;
    std::string get_value() const;

};