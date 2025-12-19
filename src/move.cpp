
#include <random>
#include <iostream>
#include "move.hpp"
#include "draw_game.hpp"




bool empty_case(std::array<std::array<char, 3>, 3>& board , int i, int j){
    bool empty;
    if(board[i][j] == '.'){
        empty=true;
    }
    else{
        empty =false;
    }
return empty;

}

std::vector <int> empty_tab( std::array<std::array<char, 3>, 3> board){
    std::vector <int> empty{};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(empty_case(board,i,j)){
                empty.push_back(i*3+j+1);
            };
    }
}
    return empty;
    }




void move_player(std::array<std::array<char, 3>, 3>  & board , Player const& player){  

    int case_choice{};
        std::cout<<player.name<<" tape le numéro de la case désirée"<<std::endl;
        std::cin>>case_choice;
        case_choice--;
        
    while (true) 
    {
        if(std::cin.fail() ){
        std::cout<<player.name<<", ce n'est pas un nombre, choisis un numéro de case.  "<<std::endl;
        std::cin.clear();
        std::cin.ignore(255, '\n');
        }
        else if (case_choice<0 || case_choice>8)
        {
            std::cout<<player.name<<", ce nombre n'est pas entre 1 et 9, choisis-en un autre. "<<std::endl;
        }
        else if (!empty_case(board, floor(case_choice/3), (case_choice)%3))
        {
            std::cout<<player.name<<", la case est occupée, choisis-en une autre. "<<std::endl;
        }
        else
        {
            break;
        }
        std::cin>>case_choice;
        case_choice--;
    }
    
    board[floor(case_choice/3)][(case_choice)%3]= player.symbol;

    draw_game_board(board);
}

void move_IA(std::array<std::array<char, 3>, 3>  & board , Player const& player){
    std::vector<int> tab = empty_tab(board);
    int n = rand()%tab.size();
    int pos = tab[n];
    int i = (pos-1)/3;
    int j= (pos-1)%3;
    board[i][j]=player.symbol;
    std::cout<<"l'IA a joué sur la case "<<pos<<std::endl;
    draw_game_board(board);
}

bool same_symbol(std::array<std::array<char, 3>, 3> const& board, Player const& player)
 {
    // Vérifie les lignes et colonnes
    for (int j = 0; j < 3; j++) {
        if ((board[0][j] == player.symbol && board[1][j] == player.symbol || board[2][j] == player.symbol && board[1][j] == player.symbol || board[2][j] == player.symbol && board[0][j]) ||  // colonne j
            (board[j][0] == player.symbol && board[j][1] == player.symbol || board[j][2] == player.symbol && board[j][1] == player.symbol || board[j][2] == player.symbol && board[j][0])) {   // ligne j
            return true;
        }
    }

    // Vérifie les diagonales
    if ((board[0][0] == player.symbol && board[1][1] == player.symbol || board[2][2] == player.symbol && board[1][1] == player.symbol || board[2][2] == player.symbol && board[0][0] == player.symbol ) ||  // diagonale principale
        (board[0][2] == player.symbol && board[1][1] == player.symbol || board[2][0] == player.symbol && board[1][1] == player.symbol || board[2][0] == player.symbol && board[0][2] == player.symbol )) {  // diagonale secondaire
        //std::cout << "C'est gagné pour " << player.name << std::endl;
        return true;
    }

    return false;
}

bool move_IA_best(std::array<std::array<char, 3>, 3>& board,Player const& player1, Player const& player2)
{
    // --- Vérifie toutes les lignes ---
    for (int x = 0; x < 3; x++) {
        int count_symbol = 0;
        int count_empty = 0;
        int empty_y = -1;

        for (int y = 0; y < 3; y++) {
            if (board[x][y] == player1.symbol)
                count_symbol++;
            else if (empty_case(board, x, y)) {   
                count_empty++;
                empty_y = y;
            }
        }

        if (count_symbol == 2 && count_empty == 1) {
            board[x][empty_y] = player2.symbol;
            std::cout << "L'IA a joué sur la case " << (x * 3 + empty_y + 1) << std::endl;
            draw_game_board(board);
            return true;
        }
    }

    // --- Vérifie toutes les colonnes ---
    for (int y = 0; y < 3; y++) {
        int count_symbol = 0;
        int count_empty = 0;
        int empty_x = -1;

        for (int x = 0; x < 3; x++) {
            if (board[x][y] == player1.symbol)
                count_symbol++;
            else if (empty_case(board, x, y)) {
                count_empty++;
                empty_x = x;
            }
        }

        if (count_symbol == 2 && count_empty == 1) {
            board[empty_x][y] = player2.symbol;
            std::cout << "L'IA a joué sur la case " << (empty_x * 3 + y + 1) << std::endl;
            draw_game_board(board);
            return true;
        }
    }

    // --- Diagonale principale ---
    {
        int count_symbol = 0;
        int count_empty = 0;
        int empty_i = -1;
        for (int i = 0; i < 3; i++) {
            if (board[i][i] == player1.symbol)
                count_symbol++;
            else if (empty_case(board, i, i)) {
                count_empty++;
                empty_i = i;
            }
        }

        if (count_symbol == 2 && count_empty == 1) {
            board[empty_i][empty_i] = player2.symbol;
            std::cout << "L'IA a joué sur la case " << (empty_i * 3 + empty_i + 1) << std::endl;
            draw_game_board(board);
            return true;
        }
    }

    // --- Diagonale secondaire ---
    {
        int count_symbol = 0;
        int count_empty = 0;
        int empty_i = -1;
        for (int i = 0; i < 3; i++) {
            if (board[i][2 - i] == player1.symbol)
                count_symbol++;
            else if (empty_case(board, i, 2 - i)) {
                count_empty++;
                empty_i = i;
            }
        }

        if (count_symbol == 2 && count_empty == 1) {
            board[empty_i][2 - empty_i] = player2.symbol;
            std::cout << "L'IA a joué sur la case " << (empty_i * 3 + (2 - empty_i) + 1) << std::endl;
            draw_game_board(board);
            return true;
        }
    }

   
    return false;
}



void move (std::array<std::array<char, 3>, 3>  & board , Player const& player1, Player const& player2, int const& choice){

    if (player1.name=="IA" && choice==2){
        if(!move_IA_best(board, player1, player1)){
            if(!move_IA_best(board, player2, player1)){
                move_IA(board, player1);
            }
        }
    }
    else {
        move_player(board, player1);
        
    }

   

}