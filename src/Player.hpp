//#include <iostream>
#include <string>
//#include <array>
#pragma once

struct Player{
    std::string name;
    char symbol;
};


int mode_choice();
Player create_player();
Player create_player2(int const& choice);
char player2_symbol(Player const& player1);


