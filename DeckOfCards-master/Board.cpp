//#include "Board.h"
#include "Board.h"

//Constructeur par défaut
Board::Board()
{
	//Initialiser la Board comme étant vide
	for (int i = 0; i < 20; i++) {
		string s(20, ' ');
		display[i] = s;
	}

	//Ajouter les lettres de la première colonne
	display[1][0] = 'A'; display[5][0] = 'B'; display[9][0] = 'C'; display[13][0] = 'D'; display[17][0] = 'E';

	//Ajouter les chiffres de la dernière rangée
	display[19] = {"  1   2   3   4   5\n"};
}

const bool Board::isFaceUp(const Letter & letter, const Number & number)
{
	//Vérifie si la combinaison Lettre et Nombre est valide
	try
	{
		getCardRange(letter, number);
		return faceStatus[letter][number];
	}
	catch (const std::out_of_range &error)
	{
		error.what();
		return true;
	}
}

bool Board::turnFaceUp(const Letter & letter, const Number & number)
{	
	//Vérifie si la carte est déjà face dévoilée
	if (isFaceUp(letter, number)) {
		return false;
	}

	//Modifie le tableau de string selon la carte
	else {
		int indexLetter = lettersIndex[letter] - 1;
		int indexNumber = numbersIndex[number] - 1;

		Card &currentCard = *cards[letter][number];
			
		for (int i = 0; i < 3; i++) {
			display[indexLetter].replace(indexNumber, 3, currentCard(i));

			indexLetter++;
		}
		faceStatus[letter][number] = true;
		return true;
	}
}

bool Board::turnFaceDown(const Letter & letter, const Number & number)
{
	//Vérifie si la carte est déjà cachée
	if (!isFaceUp(letter, number)) {
		return false;
	}

	//Modifie le tableau de string selon la carte
	else {
		int indexLetter = lettersIndex[letter] - 1;
		int indexNumber = numbersIndex[number] - 1;
		for (int i = 0; i < 3; i++) {
			display[indexLetter].replace(indexNumber, 3, "zzz");

			indexLetter++;
		}
		faceStatus[letter][number] = false;
		return true;
	}
}

Card * Board::getCard(const Letter & letter, const Number & number)
{
	try
	{
		getCardRange(letter, number);
		return cards[letter][number];
	}
	catch (const std::out_of_range &error)
	{
		throw(error);
	}
}

void Board::setCard(const Letter & letter, const Number & number, Card * card)
{
	try
	{
		getCardRange(letter, number);
		cards[letter][number] = card;
	}
	catch (const std::out_of_range &error)
	{
		throw(error);
	}
}

void Board::reset()
{
	//Configure toutes les cartes comme étant face cachée
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			faceStatus[i][j] = false;

	//Ajouter tous les z pour les cartes face cachée
	for (int i = 0; i < 20; i += 4) {
		for (int j = 0; j < 3; j++) {
			for (int k = 1; k < 20; k += 4) {
				string s("zzz");
				display[i + j].replace(k, 3, s);
			}
		}
	}

	//C3 ne contient aucune carte
	display[lettersIndex[C] - 1].replace(numbersIndex[three] - 1, 3, "   ");
	display[lettersIndex[C]].replace(numbersIndex[three] - 1, 3, "   ");
	display[lettersIndex[C] + 1].replace(numbersIndex[three] - 1, 3, "   ");
}

//Méthodes privées
void Board::getCardRange(const Letter & letter, const Number & number)
{
	if (letter == C && number == three) {
		out_of_range error(" ");
		cout << "THIS SPACE IS UNUSABLE" << endl;
		throw(error);
	}
	if (letter < 0 || letter > 4 || number < 0 || number > 4) {
		out_of_range error(" ");
		cout << "INVALID CARD" << endl;
		throw(error);
	}
}

void Board::updateScreen()
{
	system("cls");
	print();
}

void Board::print()
{
	for (int j = 0; j < 20; j++) {
		cout << display[j] << endl;
	}
}


