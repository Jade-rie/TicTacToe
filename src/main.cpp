#include "Player.hpp"

int main()
{
    
    int choice;
    std::cout<<"choisis ton mode 1 ou 2 ?"<<std::endl;
    std::cin>>choice;
    Player player1 = create_player();
    Player player2 = mode_choice(choice);
    if (player1.symbol=='O')
    {
        player2.symbol='X';
    }
    else if (player1.symbol=='X'){
        player2.symbol='O';
    }
    
    std::array<std::array<char, 3>, 3> board {{
        { '1', '2', '3' },
        { '4', '5', '6' },
        { '7', '8', '9' }
    }};
    //Player joueur {"jade", 'X'};

    draw_game_board(board);
    //Coup(board, joueur);
while (!win(board))
{
     move(board, player1, choice);
     Player inter = player1;
     player1 = player2;
     player2 = inter;   
}
    std::cout<<"Bravo "<<player2.name<<std::endl;
    return 0;
}

