#include <array>
#include <vector>
#include "player.hpp"
#pragma once

bool empty_case(std::array<std::array<char, 3>, 3>& board , int i, int j);
std::vector <int> empty_board(const std::array<std::array<char, 3>, 3> board);  
void move_player(std::array<std::array<char, 3>, 3> & board ,  Player const& player);
void move_IA(std::array<std::array<char, 3>, 3>  & board , Player const& player);
bool move_IA_best(std::array<std::array<char, 3>, 3>  & board , Player const& player);
void move(std::array<std::array<char, 3>, 3> & tableau , Player const& player1, Player const& player2, int const& choice);
