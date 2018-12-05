/*Auteurs: Mohammed Hussen (#7658545)
		   Sydroy Rakotonomenjanahary (#300041897)
*/
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "Player.h"
#include "Card.h"
#include "Board.h"

using namespace std;

class Game {
	vector<Player> players; //LISTE DES JOUEURS
	const Card* crtCard; 
	const Card* prevCard;
	Board *board;
	int nPlayer; //nombre de joueur
	static int nTour;//nombre de tour
	
	void affiche();

public:
	//constructeur
	Game(int , Board*);
 
 	//destructeur de la classe Game
	~Game() {delete board;}
	
	
	void addPlayer(const Player&);
	Player& getPlayer (Side side);
	const Card* getPreviousCard() const;
	const Card* getCurrentCard() const ;
	void setCurrentCard(const Card*);
	Card* getCard(const Letter&, const Number&);
	void setCard(const Letter&, const Number& , Card*);
	int getNbTour() const;
	

	friend ostream& operator<<(ostream& os, Game& game)	{
		game.affiche();
		return os;
	}
};
#endif
