cmake_minimum_required(VERSION 3.1)
project(Blackjack)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src/include)

add_library(Card src/Card.cpp)
add_library(Deck src/Deck.cpp)
add_executable(main src/main.cpp)
target_link_libraries(main Card Deck)