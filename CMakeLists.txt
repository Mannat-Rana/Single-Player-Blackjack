cmake_minimum_required(VERSION 3.1)
project(PlayBlackjack)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src/include)

add_library(Card src/Card.cpp)
add_library(Deck src/Deck.cpp)
add_library(Player src/Player.cpp)
add_library(Blackjack src/Blackjack.cpp)
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} Card Deck Player Blackjack)