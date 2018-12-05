#ifndef EXPERTBOARD_H
#define EXPERTBOARD_H
#include "Board.h"
#include <vector>


class ExpertBoard : public Board {
	Card *displayCards[25];
	char lettersChar[5] = { 'A', 'B', 'C', 'D', 'E' };
	char numbersChar[5] = { '1', '2', '3', '4', '5' };
	char displayChars[25][2];
	string display[4];

	static int numDisplayCards;
	static int cardIndex;

public:
	ExpertBoard() {
		for (int i = 0; i < 4; i++) {
			string s(100, ' ');
			display[i] = s;
		}

		numDisplayCards = 0;
		cardIndex = 0;
	}
	virtual bool turnFaceUp(const Letter &letter, const Number &number);
	virtual bool turnFaceDown(const Letter &letter, const Number &number);
	virtual void reset();
	virtual void updateScreen();
private:
	virtual void print();
};
#endif
