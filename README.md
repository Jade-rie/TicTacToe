Organisation de mon code :
J'ai réparti mon code en 4 fichiers en plus du main :
  - player dans lequel il y a la structure d'un player, la fonction mode_choice pour choisir son mode de jeu au début, la fonction create_player, la fonction create_player2 qui associe un second joueur ou l'ia en fonction du choix et enfin la fonction player2_symbol qui empêche le 2e player d'avoir un symbole identique au premier.
  - draw_game avec la fonction pour dessiner le tableau.
  - move qui contient la fonction empty_case qui renvoie true si la case est vide, empty_board pour créer un tableau avec toutes les cases vides, move_player, move_IA qui joue aléatoirement, move_IA_best (IA améliorée développée après) et move qui sera appelée dans le main pour dire quel move jouer.
  - game avec la fonction win qui renvoie true si la partie est gagnée et la fonction equal qui renvoie true si c'est match nul, enfin game qui arrête move quand c'est gagné ou match nul.

Amélioration :
J'ai amélioré mon IA de façon à ce que si elle a deux symboles alignés, elle ajoute le troisième, sinon si deux symboles du joueur adverse sont alignés, elle le bloque, et sinon elle joue aléatoirement.
La fonction pour bloquer l'autre ou aligner ses symboles est la même. Elle prend en argument deux players pour être appelée avec le même player ou non. Le principe de ma fonction est de compter le nombre de symboles du joueur présent sur une même ligne/colonne/diagonale et lorsque ce chiffre est égal à 2 et que l'autre case est vide, on joue sur cette case vide.

Problèmes : 
J'ai souhaité rendre empty_case utilisable avec n'importe quel symbole en prenant en argumant les deux players pour utiliser player1.symbol et player2.symbol. Sauf qu'en appelant ma fonction move_IA_best (..., player1, player1), empty_case ne vérifiait plus les symboles adversaires. Alors j'ai mis empty_case à true quand la case est un point.
