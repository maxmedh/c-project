#include <iostream>
#include <vector>
#include "Deck.h"
#include "CardDeck.h"
#include "Card.h"

CardDeck::CardDeck() {

	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 5; b++) {
			deck.push_back(Card(Card::FaceAnimal(a), Card::FaceBackground(b)));
		}
	}
	crtCard = &deck.front();
}

CardDeck & CardDeck::make_CardDeck()
{
	CardDeck* newDeck = new CardDeck();
	return *newDeck;
}

