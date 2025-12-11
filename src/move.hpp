#include <iostream>
#include <string>
#include <array>
#include "Player.hpp"
#pragma once

void move_player(std::array<std::array<char, 3>, 3> & tableau , Player player);
void move_IA();
void move(std::array<std::array<char, 3>, 3> & tableau , Player player, int choice);
bool empty_case(std::array<std::array<char, 3>, 3> board , int i, int j);