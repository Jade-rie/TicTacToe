#include <iostream>
#include <string>
#include <array>
#include "Player.hpp"
#pragma once


bool win(std::array<std::array<char, 3>, 3>  board, Player player);
bool equal(std::array<std::array<char, 3>, 3>  board);
void game(std::array<std::array<char, 3>, 3>  board, Player player1, Player player2, int choice);