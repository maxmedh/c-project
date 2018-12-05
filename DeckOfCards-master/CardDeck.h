/*Auteurs: Mohammed Hussen (#7658545)
		   Sydroy Rakotonomenjanahary (#300041897)
*/
#ifndef DECKCARTE_H
#define DECKCARTE_H
#include <vector>
#include "Card.h"
#include "Deck.h"

class CardDeck : public Deck<Card> {

private:
	CardDeck();

public:
	static CardDeck&  make_CardDeck();
};
#endif
