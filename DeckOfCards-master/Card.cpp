#include <iostream>
#include "Card.h"

//Card(FaceAnimal, FaceBackground), cree une carte contenant une des enum de FaceAnimal et FaceBackground
Card::Card(FaceAnimal a, FaceBackground b) : animal(a), background(b) {
	char C1,C2;
	C1 = cardConvertor(a);
	C2 = cardConvertor(b);
	for (int i=0; i< 3; i++) {
		string C(3,C2);
			card[i] = C;
		}
		card[1][1] = C1;
}

//Convertit la valeur dans les enum en char 
char Card::cardConvertor(Card::FaceAnimal a){
	char C;
	switch(a){
		case Card::Crabe: C = 'C'; break;
		case Card::Walrus: C = 'W'; break;
		case Card::Octopus: C = 'O'; break;
		case Card::Pingouin: C = 'P'; break;
		case Card::Turtle: C = 'T'; break;
	}
	return C;}
char Card::cardConvertor(Card::FaceBackground b){
	char C;
	switch(b){
		case Card::Red: C = 'r'; break;
		case Card::Yellow: C = 'y'; break;
		case Card::Mauve: C = 'm'; break;
		case Card::Blue: C = 'b'; break;
		case Card::Green: C = 'g'; break;
	}
	return C;
}




