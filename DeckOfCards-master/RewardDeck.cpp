#include <iostream>
#include "RewardDeck.h"
#include "Reward.h"

RewardDeck::RewardDeck() {
	for (int i=1; i<3; i++){
		deck.push_back(Reward(1));
	}
	for(int i=1; i<2; i++){
		deck.push_back(Reward(2));
	}
	deck.push_back(Reward(3));
	deck.push_back(Reward(4));
	crtCard = &deck.front();
}

RewardDeck& RewardDeck::make_RewardDeck() {
	RewardDeck *newRDeck = new RewardDeck();
	return *newRDeck;
}
