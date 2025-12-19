#include <iostream>
#include "Player.hpp"


int mode_choice(){
    int choice;
    std::cout<<"Bienvenue dans le jeu du TicTacToe"<<std::endl;
    std::cout<<"Veuillez choisir un mode de jeu :"<<std::endl;
    std::cout<<"1. Deux joueurs"<<std::endl;
    std::cout<<"2. Un joueur contre l'IA"<<std::endl;          
    std::cout<<std::endl;
    std::cin>>choice;
    while (choice!=1 && choice!=2) 
    {
        std::cout<<"choix invalide, réessaye ! :"<<std::endl;
        std::cin.clear();
        std::cin.ignore(255, '\n');
        std::cin>>choice;

    }
    return choice;          
    
}

Player create_player(){
    std::string nom_player{""};
    char symbole_player{};
    std::cout<<"Quel est ton nom de joueur ?"<<std::endl;
    std::cin>>nom_player;
    std::cout << "Choisis ton symbole (O ou X) : ";
    std::cin >> symbole_player;
    while (symbole_player != 'O' && symbole_player != 'X'){
        std::cout<<"ce n'est pas un symbole possible, choisis X ou O"<<std::endl;
        std::cin.clear();
        std::cin.ignore(255, '\n');
        std::cin >> symbole_player;
    }

    return Player{nom_player, symbole_player};
}


Player create_player2(int const& choice){

    Player player2;
    if(choice==1){
        player2 = create_player();
    }
    else if(choice==2){
        player2 = Player {"IA", };
    }

    return player2;
}

char player2_symbol(Player const& player1){
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



