#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include "move.hpp"
#include "draw_game.hpp"



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

void move_player(std::array<std::array<char, 3>, 3>  & board , Player player){

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

void move_IA(std::array<std::array<char, 3>, 3>  & board , Player player){
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
    

void move (std::array<std::array<char, 3>, 3>  & board , Player player, int choice){

    if (player.name=="IA" && choice==2){
        move_IA(board, player);

    }
    else {
        move_player(board, player);
        
    }
}