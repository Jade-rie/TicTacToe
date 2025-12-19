#pragma once


bool win(std::array<std::array<char, 3>, 3> const&  board, Player const& player);
bool equal(std::array<std::array<char, 3>, 3>  const& board);
void game(std::array<std::array<char, 3>, 3>  board, Player player1, Player player2, int const& choice);