#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include "move.hpp"
#include "draw_game.hpp"



void draw_game_board( std::array<std::array<char, 3>, 3> const& board){
    for (int i = 0; i < 3; i++)
    {
        std::cout<<" | ";
        for (int j = 0; j<3; j++)
        {
            std::cout<<board[i][j]<<" | ";
        }
        std::cout<<std::endl;
        
    }
}