#include <iostream>
#include "Rules.h"

int Rules::currentSide;
int Rules::numActivePlayers;

bool Rules::isValid(const Game & game)
{
	const Card* previousCardPtr = game.getPreviousCard();

	//Vérifie si la carte courante est la première carte tournée
	if (previousCardPtr == nullptr)
		return true;

	const Card& previousCard = *previousCardPtr;
	const Card& currentCard = *game.getCurrentCard();

	char animalPrevious = previousCard(1)[1];
	char backgroundPrevious = previousCard(1)[0];

	char animalCurrent = currentCard(1)[1];
	char backgroundCurrent = currentCard(1)[0];

	if (animalPrevious == animalCurrent || backgroundPrevious == backgroundCurrent)
		return true;
	else {
		numActivePlayers--;
		return false;
	}
		
}

bool Rules::gameOver(const Game &game)
{
	if (game.getNbTour() >= 7){
		return true;
	}
	else{
		return false;
	}
}

bool Rules::roundOver(const Game & game)
{
	if (numActivePlayers == 1) {
		numActivePlayers = numPlayers;
		currentSide = 0;
		return true;
	}
	else
		return false;
}

const Player& Rules::getNextPlayer(Game & game)
{
	return game.getPlayer(Side((currentSide++) % numPlayers));
}

