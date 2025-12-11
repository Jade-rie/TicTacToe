#include "Player.hpp"
#include "draw_game.hpp"
#include "move.hpp"
#include "game.hpp"
#include <time.h>


int main()
{
    srand(time(0));
    int choice;
    std::cout<<"choisis ton mode 1 ou 2 ?"<<std::endl;
    std::cin>>choice;
    Player player1 = create_player();
    Player player2 = mode_choice(choice);
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

