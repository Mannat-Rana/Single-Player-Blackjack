#include "../include/Blackjack.hpp"
#include <string>

Blackjack::Blackjack() {
    this->m_dealer.set_name("Dealer");
    std::cout << std::endl << "Welcome to the game of Blackjack, please enter your name to play: ";
    std::string input_player_name{};
    std::cin >> input_player_name;
    this->m_player.set_name(input_player_name);
    this->m_deck.shuffle();
    std::cout << "Hello " << this->m_player.get_name() << ", may the cards be with you!" << std::endl;
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
    if (!this->m_deck.get_cards().size()) {
        std::cout << "No cards remain, resetting deck...\n";
        this->reset_deck();
    }    
    player.add_card(this->m_deck.get_top_card());
}

void Blackjack::start_round() {
    if (this->m_deck.get_cards().size() <= 10) {
        std::cout << "We're low on cards, let's reshuffle!\n";
        this->reset_deck();
    }
    this->m_player.clear_hand();
    this->m_dealer.clear_hand();
    this->m_player.set_hand_value(0);
    this->m_dealer.set_hand_value(0);
    for (int i = 0; i < 2; i++) {
        deal_card(this->m_dealer);
        deal_card(this->m_player);
    }
    print_hand(this->m_dealer);
    print_hand(this->m_player);
}

void Blackjack::print_hand(const Player& player) const {
    std::cout << std::endl << player.get_name() << "'s current hand:" << std::endl;
    for (auto&& card : player.get_hand()) {
        std::cout << card;
    }
    std::cout << std::endl;
}

unsigned int Blackjack::get_card_value(const Card& card) const {
    unsigned int card_value {};
    switch (card.get_rank()) {
        case Card::Rank::Jack:
        case Card::Rank::Queen:
        case Card::Rank::King:
            card_value = 10;
            break;
        case Card::Rank::Ace:
            card_value = 1;
            break;
        default:
            card_value = static_cast<unsigned int>(card.get_rank());
            break;
    }
    return card_value;
}

unsigned int Blackjack::solve_hand_value(const std::vector<Card>& hand) {
    unsigned int hand_val {};
    bool has_ace {false};
    for (auto&& card : hand) {
        hand_val += get_card_value(card);
        if (card.get_rank() == Card::Rank::Ace) {
            has_ace = true;
        }
    }
    if (hand_val <= 11) {
        if (has_ace) {
            hand_val += 10;
        }
    }
    return hand_val;
}

void Blackjack::play_player_round() {
    bool player_done{false};
    unsigned int player_hand_val {solve_hand_value(this->m_player.get_hand())};
    while (!player_done) {
        if (player_hand_val == 21) {
            std::cout << "Congrats, you got blackjack!" << std::endl;
            player_done = true;
        }
        else {
            if(player_hand_val < 21) {
                std::cout << "Press 1 for hit, or anything else if you are happy with your hand: ";
                int input {};
                std::cin >> input;
                switch (input) {
                    case 1:
                        deal_card(this->m_player);
                        print_hand(this->m_player);
                        break;
                    default:
                        player_done = true;
                        break;
                }
                player_hand_val = solve_hand_value(this->m_player.get_hand());

            }
            else {
                std::cout << "Sorry, you busted!" << std::endl;
                player_done = true;
            }
        }
        
    }
    this->m_player.set_hand_value(player_hand_val);
    
}

void Blackjack::play_dealer_round() {
    bool dealer_done{false};
    unsigned int dealer_hand_val {solve_hand_value(this->m_dealer.get_hand())};
    unsigned int player_hand_val {this->m_player.get_hand_value()};
    while (!dealer_done) {
        if (player_hand_val > 21) {
            dealer_done = true;
        }
        else if (dealer_hand_val == 21) {
            std::cout << "Oooh, looks like the dealer got blackjack!" << std::endl;
            dealer_done = true;
        }
        else {
            if (dealer_hand_val < 21) {
                if (dealer_hand_val < player_hand_val) {
                    deal_card(this->m_dealer);
                    print_hand(this->m_dealer);
                }
                else {
                    dealer_done = true;
                }
                dealer_hand_val = solve_hand_value(this->m_dealer.get_hand());

            }
            else {
                std::cout << "Yay! The dealer busted!" << std::endl;
                dealer_done = true;
            }
        }
        
    }
    this->m_dealer.set_hand_value(dealer_hand_val);
}

void Blackjack::evaluate_round_winner() {
    int player_hand_val {this->m_player.get_hand_value()};
    int dealer_hand_val {this->m_dealer.get_hand_value()};
    std::cout << "Your final hand value: " << player_hand_val << std::endl;
    std::cout << "Dealer's final hand value: " << dealer_hand_val << std::endl;
    bool player_bust {player_hand_val > 21};
    bool dealer_bust {dealer_hand_val > 21};
    if (player_bust) {
        std::cout << "Since you busted, dealer wins!\n";
        this->m_dealer.add_win(); 
    }
    else if (dealer_bust) {
        std::cout << "Since the dealer busted, you win!\n";
        this->m_player.add_win();
    }
    else if (this->m_player.get_hand_value() > this->m_dealer.get_hand_value()) {
        std::cout << "Your hand has a higher value, you win!\n";
        this->m_player.add_win();
    }
    else if (this->m_player.get_hand_value() == this->m_dealer.get_hand_value()) {
        std::cout << "Same hand value, looks like it's a tie!\n";
    }
    else {
        std::cout << "Dealer's hand has higher value, so dealer wins!\n";
        this->m_dealer.add_win();
    }
    std::cout << "Dealer's total wins: " << this->m_dealer.get_rounds_won() << std::endl;
    std::cout << "Your total wins: " << this->m_player.get_rounds_won() << std::endl;
}

void Blackjack::wait(int seconds) const {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void Blackjack::start_game() {
    char play_again {'1'};
    while (play_again == '1') {
        this->start_round();
        this->play_player_round();
        this->play_dealer_round();
        this->evaluate_round_winner();
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Press 1 to play again, anything else to quit: ";
        std::cin >> play_again;
    }
    std::cout << "Thanks for playing " << this->m_player.get_name() << std::endl;
    
}