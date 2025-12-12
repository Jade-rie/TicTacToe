//#include <iostream>
//#include <string>
//#include <vector>
#include <random>
//#include <time.h>
#include "move.hpp"
#include "draw_game.hpp"
#include "game.hpp"



bool empty_case(std::array<std::array<char, 3>, 3> board , int i, int j){
    bool empty;
    if(board[i][j]!='X' && board[i][j] !='O'){
        empty=true;
    }
    else{
        empty =false;
    }
return empty;

}



void move_player(std::array<std::array<char, 3>, 3>  & board , Player const& player){

    int case_choice{};
        std::cout<<player.name<<" tape le numéro de la case désirée"<<std::endl;
        std::cin>>case_choice;
        case_choice--;
        
    while (!empty_case(board, (case_choice)/3, case_choice%3))
    {
        std::cout<<player.name<<" Case indisponible. Choisis-en une autre.  "<<std::endl;
        std::cin>>case_choice;
        case_choice--;
    }
    
    board[floor(case_choice/3)][(case_choice)%3]= player.symbol;

    draw_game_board(board);
}

void move_IA(std::array<std::array<char, 3>, 3>  & board , Player const& player){
    int i{};
    int j{};
    do
    {
        i = rand()%3;
        j = rand()%3;
    } while (!empty_case(board,i,j));
    board[i][j]=player.symbol;
    std::cout<<"l'IA a joué sur la case "<<(i*3+j+1)<<std::endl;
    draw_game_board(board);
}

bool same_symbol(std::array<std::array<char, 3>, 3> const& board, Player const& player)
 {
    // Vérifie les lignes et colonnes
    for (int j = 0; j < 3; j++) {
        if ((board[0][j] == player.symbol && board[1][j] == player.symbol || board[2][j] == player.symbol && board[1][j] == player.symbol) ||  // colonne j
            (board[j][0] == player.symbol || board[j][1] == player.symbol || board[j][2] == player.symbol)) {   // ligne j
            //std::cout << "C'est gagné pour " << player.name << std::endl;
            return true;
        }
    }

    // Vérifie les diagonales
    if ((board[0][0] == player.symbol || board[1][1] == player.symbol || board[2][2] == player.symbol) ||  // diagonale principale
        (board[0][2] == player.symbol || board[1][1] == player.symbol || board[2][0] == player.symbol)) {  // diagonale secondaire
        //std::cout << "C'est gagné pour " << player.name << std::endl;
        return true;
    }

    return false;
}

bool move_IA_best(std::array<std::array<char, 3>, 3>& board,
                  Player const& player1,  // symbole à analyser (IA ou adversaire)
                  Player const& player2)  // celui qui joue (l’IA)
{
    // --- Vérifie toutes les lignes ---
    for (int x = 0; x < 3; x++) {
        int count_symbol = 0;
        int count_empty = 0;
        int empty_y = -1;

        for (int y = 0; y < 3; y++) {
            if (board[x][y] == player1.symbol)
                count_symbol++;
            else if (board[x][y] == '.') {
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
            else if (board[x][y] == '.') {
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
            else if (board[i][i] == '.') {
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
            else if (board[i][2 - i] == '.') {
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

    // Aucun coup gagnant ni bloquant trouvé
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