#include <iostream>
#include <string>
#include <array>
#include <random>
#include <time.h>
#include "Player.hpp"
#include "game.hpp"
#include "move.hpp"



bool win(std::array<std::array<char, 3>, 3> const& board, Player const& player)
 {
    // Vérifie les lignes et colonnes
    for (int j = 0; j < 3; j++) {
        if ((board[0][j] == player.symbol && board[1][j] == player.symbol && board[2][j] == player.symbol) ||  // colonne j
            (board[j][0] == player.symbol && board[j][1] == player.symbol && board[j][2] == player.symbol)) {   // ligne j
            std::cout << "C'est gagné pour " << player.name << std::endl;
            return true;
        }
    }

    // Vérifie les diagonales
    if ((board[0][0] == player.symbol && board[1][1] == player.symbol && board[2][2] == player.symbol) ||  // diagonale principale
        (board[0][2] == player.symbol && board[1][1] == player.symbol && board[2][0] == player.symbol)) {  // diagonale secondaire
        std::cout << "C'est gagné pour " << player.name << std::endl;
        return true;
    }

    return false;
}


bool equal(std::array<std::array<char, 3>, 3> const& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '.') {
                return false; 
            }
        }
    }
    std::cout << "Match nul !!" << std::endl;
    return true; 
}

void game(std::array<std::array<char, 3>, 3>  board, Player player1, Player player2, int const& choice){
    do {
    move(board, player1, player2, choice);
    if (win(board, player1) || equal(board)) {
        break;
    }
    move(board, player2, player1, choice);
   if (win(board, player2) || equal(board)) {
        break;
   }

    }while (true);
    
    
}   
