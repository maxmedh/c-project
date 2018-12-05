/*Auteurs: Mohammed Hussen (#7658545)
		   Sydroy Rakotonomenjanahary (#300041897)
*/	
#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include "Reward.h"
#include <vector>

using namespace std;

template <class C>
class Deck {
	protected:
		std::vector<C> deck;
		C* crtCard;
		
	public:
		virtual void shuffle();
		virtual C* getNext();
		virtual bool isEmpty() const;
		
};
#endif 


