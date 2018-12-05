/*Auteurs: Mohammed Hussen (#7658545)
		   Sydroy Rakotonomenjanahary (#300041897)
*/
#ifndef DECKREWARD_H
#define DECKREWARD_H
#include "Deck.h"

class RewardDeck : public Deck<Reward> {

private:
	RewardDeck();

public:
	static RewardDeck& make_RewardDeck();
};
#endif
