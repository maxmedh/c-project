#include "ExpertBoard.h"

int ExpertBoard::numDisplayCards;
int ExpertBoard::cardIndex;

bool ExpertBoard::turnFaceUp(const Letter & letter, const Number & number)
{
	//Vérifie si la carte est déjà face dévoilée
	if (isFaceUp(letter, number)) {
		return false;
	}

	else {
		displayChars[cardIndex][0] = lettersChar[letter];
		displayChars[cardIndex][1] = numbersChar[number];

		displayCards[cardIndex] = cards[letter][number];

		cardIndex++;
		numDisplayCards++;

		faceStatus[letter][number] = true;
		return true;
	}
}

bool ExpertBoard::turnFaceDown(const Letter & letter, const Number & number)
{
	//Vérifie si la carte est déjà cachée
	if (!isFaceUp(letter, number)) {
		return false;
	}

	else {
		cardIndex--;
		numDisplayCards--;

		faceStatus[letter][number] = false;
		return true;
	}
}

void ExpertBoard::reset()
{
	//Configure toutes les cartes comme étant face cachée
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			faceStatus[i][j] = false;

	cardIndex = 0;
	numDisplayCards = 0;
}

void ExpertBoard::updateScreen()
{
	system("cls");
	ExpertBoard::print();
}

void ExpertBoard::print()
{
	int displayPosition = -4;
	for (int i = 0; i < numDisplayCards; i++) {
		displayPosition = i * 4;

		for (int j = 0; j < 3; j++) {
			Card &currentCard = *displayCards[i];
			display[j].replace(displayPosition, 3, currentCard(j));
		}

		display[3][displayPosition] = displayChars[i][0];
		display[3][displayPosition + 1] = displayChars[i][1];
	}

	for (int i = 0; i < 4; i++)
		cout << display[i].substr(0, displayPosition + 4) << endl;
}

