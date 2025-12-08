#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include "Player.hpp"


Player create_player(){
    std::string nom_player{""};
    char symbole_player{};
    std::cout<<"Quel est ton nom de player ?"<<std::endl;
    std::cin>>nom_player;
    do {
    std::cout << "Choisis ton symbole (O ou X) : ";
    std::cin >> symbole_player;
    } while (symbole_player != 'O' && symbole_player != 'X');

    return Player{nom_player, symbole_player};
}

void draw_game_board( std::array<std::array<char, 3>, 3> board){
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

Player mode_choice(int & choice){

    Player player2;
    if(choice==1){
        player2 = create_player();
    }
    else if(choice==2){
        player2 = Player {"IA", };
    }
    else{
        std::cout<<"choix invalide"<<std::endl;
    }

    return player2;
}

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
    std::cout<<player.name<<" Tape le numéro de la case désirée"<<std::endl;
    std::cin>>case_choice;
    switch (case_choice)
    {
    case 1:
    if(empty_case(board, 0, 0)==true){
        board[0][0] = player.symbol;
        break; 
    }
     case 2:
        board[0][1] = player.symbol;
        break;
     case 3:
        board[0][2] = player.symbol;
        break;
     case 4:
        board[1][0] = player.symbol;
        break;
     case 5:
        board[1][1] = player.symbol;
        break;
     case 6:
        board[1][2] = player.symbol;
        break;
     case 7:
        board[2][0] = player.symbol;
        break;
     case 8:
        board[2][1] = player.symbol;
        break;
     case 9:
        board[2][2] = player.symbol;
        break;
    
    default:
        break;
    }

    draw_game_board(board);
}

void move_IA(std::array<std::array<char, 3>, 3>  & board , Player player){
    int i = rand()%3;
    int j = rand()%3;
    //while( board[i][j]!='X' || board[i][j] !='O' ){
        board[i][j]=player.symbol;
        draw_game_board(board);
   // }
    }

void move (std::array<std::array<char, 3>, 3>  & board , Player player, int choice){

    if (player.name=="IA" && choice==2){
        move_IA(board, player);

    }
    else {
        move_player(board, player);
        
    }
}
bool win(std::array<std::array<char, 3>, 3>  board){
    bool win = false;
     for (int j = 0; j < 3; j++){
        if(board[0][j] == board[1][j] && board[0][j] == board[2][j] ||  //colonnes
             board[j][0] == board[j][1] && board[j][0] == board[j][2] || //lignes
            board[0][0] == board[1][1] && board[0][0] == board[2][2] || //diagonale 1
            board[0][2] == board[1][1] && board[0][2] == board[2][0]    //diagonale 2
        ){
            std::cout<<"C'est gagné !!"<<std::endl;
            return true;
        }
       
        }

    return false;

}



