#include "../include/Card.hpp"
#include "../include/Deck.hpp"

int main() {
    Deck test_deck {};
    test_deck.shuffle();
    std::cout << test_deck << std::endl;
    std::cout << test_deck.get_top_card() << std::endl;
    std::cout << test_deck << std::endl;
}