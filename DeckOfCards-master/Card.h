/*Auteurs: Mohammed Hussen (#7658545)
		   Sydroy Rakotonomenjanahary (#300041897)
*/
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card{

	public:
		string card[3];
		
		enum FaceAnimal{Crabe, Pingouin, Octopus, Turtle, Walrus};
		enum FaceBackground{Green, Mauve, Blue, Yellow, Red};
		
		char cardConvertor(Card::FaceAnimal a);
		char cardConvertor(Card::FaceBackground b);
		
		const string& operator()(int row) const{
			return this->card[row];
		}
	
	private:
		Card::FaceAnimal animal;
		Card::FaceBackground background;
		Card(Card::FaceAnimal animal,Card::FaceBackground);
		
	friend class CardDeck;
};

#endif
