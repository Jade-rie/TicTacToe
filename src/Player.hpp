//#include <iostream>
#include <string>
//#include <array>
#pragma once

struct Player{
    std::string name;
    char symbol;
};



Player create_player();
Player mode_choice(int const& choice);
char player2_symbol(Player const& player1);


