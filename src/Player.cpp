#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include "Player.hpp"


Player create_player(){
    std::string nom_player{""};
    char symbole_player{};
    std::cout<<"Quel est ton nom de joueur ?"<<std::endl;
    std::cin>>nom_player;
    std::cout << "Choisis ton symbole (O ou X) : ";
    std::cin >> symbole_player;
    while (symbole_player != 'O' && symbole_player != 'X'){
        std::cout<<"Ce n'est pas un symbole possible, choisis X ou O"<<std::endl;
        std::cin >> symbole_player;
    }

    return Player{nom_player, symbole_player};
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

char player2_symbol(Player player1){
    Player player2;
     if (player1.symbol=='O')
    {
        player2.symbol='X';
    }
    else if (player1.symbol=='X'){
        player2.symbol='O';
    }
    return player2.symbol;
}



