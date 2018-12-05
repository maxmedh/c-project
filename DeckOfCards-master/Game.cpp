#include <iostream>
#include <vector>
#include "Game.h"
#include "Player.h"
#include <iostream>
#include "Game.h"

int Game::nTour;

Game::Game(int nplayer, Board *currentBoard){
		this->nPlayer = nPlayer;
		board = currentBoard;
		crtCard = prevCard = nullptr;
		nTour = 0;	
}
	
Player & Game::getPlayer(Side side){
	return players[side];
}

const Card * Game::getPreviousCard() const{
	return prevCard;
}

const Card * Game::getCurrentCard() const{
	return crtCard;
}

void Game::setCurrentCard(const Card * card){
	if (card == nullptr){
		crtCard = nullptr;
	}
	prevCard = crtCard;
	crtCard = card;
}

Card * Game::getCard(const Letter & letter, const Number & number){
	return board->getCard(letter, number);
}

void Game::setCard(const Letter & letter, const Number & number, Card * card){
	board->setCard(letter, number, card);
}


void Game::affiche(){
	cout << *board;
	for (int i = 0; i < nPlayer; i++) {
		cout << players[i];
	}
}

//ajoute un joueur
void Game::addPlayer(const Player& player) { 
		players.push_back(player);  
}

//retourne le nombre de tour
int Game::getNbTour() const{ 
	return nTour++; 
}
