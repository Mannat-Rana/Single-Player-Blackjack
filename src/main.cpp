#include "../include/Blackjack.hpp"

int main() {
    Blackjack test {};
    for (i = 0; i < 100; i++) {
        test.deal_card(test.get_player());
    }
}