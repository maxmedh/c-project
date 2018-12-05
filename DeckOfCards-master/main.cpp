/*Auteurs: Mohammed Hussen (#7658545)
		   Sydroy Rakotonomenjanahary (#300041897)
*/
#include <iostream>
#include "Player.h"
#include "CardDeck.h"
#include "RewardDeck.h"
#include "Game.h"
#include "Board.h"
#include "ExpertBoard.h"
#include "Rules.h"

#include <algorithm>
#include <ctime>

using namespace std;

int main(){	
	cout<<"************************ \n*Bienvenue dans MEMOARR* \n************************\n";
	
	int gameVersion;
	int nPlayer;
	Game *game;
	Rules *rules;
	Board *board;
		
	//version du jeu
	cout<<"Veuillez choisir la version du jeu...\nPour la version Basique taper 1, taper 2 pour la version Experte: ";
	cin>>gameVersion;
	while(gameVersion!=1 && gameVersion!=2){
    cout << "Veuillez taper un des chiffre indiquer: ";
    cin >> gameVersion;
    
	}if(gameVersion == 1){
		board = new Board();
	}else if(gameVersion == 2){
		board = new ExpertBoard();
	}
	
	//nombre de joueur
	while (nPlayer < 2 || nPlayer > 4) {
		cout << "Veuillez entrer le nombre de joueur (4 maximum): ";
		cin >> nPlayer;

		if (!cin) {
			cout << "Svp entrez un nombre " << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		else if
		 (nPlayer < 2 || nPlayer > 4)
				cout << "Le nombre que vous avez tapez est invalide" << endl;
		}
	rules = new Rules(nPlayer);
	game = new Game(nPlayer, board);

	CardDeck &cardDeck = CardDeck::make_CardDeck();
	RewardDeck &rewardDeck = RewardDeck::make_RewardDeck();
	 
	//Creation des joueurs
	for (int i = 0 ; i<nPlayer ; i++) {
		string name;
		cout << "Entrez le nom du joueur " << (i + 1) << ": ";
		cin >> name;
		Player *player = new Player(name);
		player->setSide(Side(i));
		game->addPlayer(*player);
	}
	
	//lance le jeu
	cout << *game;
	system("PAUSE");
	
	//Melange les decks de cartes et de rubis
	cardDeck.shuffle();
	rewardDeck.shuffle();

	//affiche le tableau de carte
	for (int i=1; i<=5; i++) {
		for (int j=1; j<=5; j++) {
			if (i == 3 && j == 3){} // l'espace vide au milieu (3e ligne, 3e colonne) 
			else{
				game->setCard(Letter(i-1), Number(j-1), cardDeck.getNext());
			}
		}
	}

	while (!rules->gameOver(*game)) {
		board->reset();
		game->setCurrentCard(nullptr);

		//initialise les joueurs comme etant active
		for (int i=0; i<nPlayer ; i++) {
			Player& player = game->getPlayer(Side(i));
			player.setActive(true);
		}

		//Revele 3 cartes aux joueurs en fonction de leur position
		for (int i = 0; i < nPlayer; i++) {
			int x = 0, y = 0;
			
			if (i == 0 || i == 1) {
				if (i == 1)
					x = 4;

				y = 1;
				board->turnFaceUp(Letter(x), Number(y++));
				board->turnFaceUp(Letter(x), Number(y++));
				board->turnFaceUp(Letter(x), Number(y++));
	
				board->updateScreen();
				cout << game->getPlayer(Side(i)).getName() <<"! ";
				
				system("PAUSE");
				y = 1;
				board->turnFaceDown(Letter(x), Number(y++));
				board->turnFaceDown(Letter(x), Number(y++));
				board->turnFaceDown(Letter(x), Number(y++));
			}
			else {
				if (i == 3)
					y = 4;
				x = 1;
				board->turnFaceUp(Letter(x++), Number(y));
				board->turnFaceUp(Letter(x++), Number(y));
				board->turnFaceUp(Letter(x++), Number(y));
				board->updateScreen();
				cout << game->getPlayer(Side(i)).getName() << "! ";

				system("PAUSE");

				x = 1;
				board->turnFaceDown(Letter(x++), Number(y));
				board->turnFaceDown(Letter(x++), Number(y));
				board->turnFaceDown(Letter(x++), Number(y));
			}
		}

		system("cls");
		cout << *game;

		while (!rules->roundOver(*game)) {
			const Player& currentPlayer = rules->getNextPlayer(*game);
			if (currentPlayer.isActive()) {
				cout << currentPlayer.getName() << "'s turn !" << endl;

				bool flag = false;
				char currentLetterIndex;
				char currentNumberIndex;

				Letter currentLetter;
				Number currentNumber;

				Card* currentCard;

				while (!flag) {
					cout << "Entrer la position de la carte a retourner: ";
					cin >> currentLetterIndex;
					cin >> currentNumberIndex;

					currentLetter = Letter((int) currentLetterIndex - 65);
					currentNumber = Number((int) currentNumberIndex - 49);
					flag = board->turnFaceUp(currentLetter, currentNumber);
				}
				
				currentCard = board->getCard(currentLetter, currentNumber);
				game->setCurrentCard(currentCard);

				if (!rules->isValid(*game)) {
					cout << currentPlayer.getName() << " a choisi la mauvaise carte, il est hors du jeu" << endl;
					game->getPlayer(currentPlayer.getSide()).setActive(false);
				}
				cout << *game;
			}
		}
		
		static int ignoreCounter = 0;
		for (int i = 0; i < nPlayer; i++) {
			Player& player = game->getPlayer(Side(i));
			if (player.isActive()) {
				player.addReward(*rewardDeck.getNext());
				cout << "Le vainqueur est: " << player.getName() << endl;

				system("PAUSE");
			}
				
		}
	}

	system("cls");
	Player *winner = &(game->getPlayer(Side(0)));

	for (int i = 0; i < nPlayer; i++) {
		Player& player = game->getPlayer(Side(i));

		if (player.getNRubis() > winner->getNRubis())
			winner = &player;
		player.setDisplayMode(true);
		cout << player;
	}

	//
	cout << "Le jeu est termine, le vainqueur est: " << endl;
	cout << *winner;
}

