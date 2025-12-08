#include <iostream>
#include <string>
#include <vector>

struct Player{
    std::string name;
    char symbol;
};

Player create_player(){
    std::string nom_joueur{""};
    char symbole_joueur{};
    std::cout<<"Quel est ton nom de joueur ?"<<std::endl;
    std::cin>>nom_joueur;
    do {
    std::cout << "Choisis ton symbole (O ou X) : ";
    std::cin >> symbole_joueur;
    } while (symbole_joueur != 'O' && symbole_joueur != 'X');

    return Player{nom_joueur, symbole_joueur};
}




int main()

{

    create_player();

return 0;
}