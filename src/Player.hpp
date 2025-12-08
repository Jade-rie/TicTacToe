#include <iostream>
#include <string>
#include <array>
#pragma once

struct Player{
    std::string name;
    char symbol;
};



Player create_player();
void draw_game_board( std::array<std::array<char, 3>, 3> board);
Player mode_choice(int & choice);
bool empty_case(std::array<std::array<char, 3>, 3> board , int i, int j);
void move_player(std::array<std::array<char, 3>, 3> & tableau , Player player);
void move_IA();
void move(std::array<std::array<char, 3>, 3> & tableau , Player player, int choice);
bool win(std::array<std::array<char, 3>, 3>  board);


