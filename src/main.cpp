#include <iostream>
#include "Player.hpp"
#include "draw_game.hpp"
#include "move.hpp"
#include "game.hpp"
#include <time.h>


int main()
{
    srand(time(0));
    int choice = mode_choice();
    Player player1 = create_player();
    Player player2 = create_player2(choice);
    player2.symbol = player2_symbol(player1);
   
    
    std::array<std::array<char, 3>, 3> board {{
        {'.','.','.'},
        {'.','.','.'},
        {'.','.','.'},
    }};

      std::array<std::array<char, 3>, 3> board_number {{
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
    }};

std::cout<<"aide : "<<std::endl;
draw_game_board(board_number);

game(board, player1, player2, choice);

    return 0;
}

