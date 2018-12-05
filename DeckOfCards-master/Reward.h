/*Auteurs: Mohammed Hussen (#7658545)
		   Sydroy Rakotonomenjanahary (#300041897)
*/
#ifndef REWARD_H
#define REWARD_H

class Reward {
private:
	int rubi;
	Reward();
	Reward(int);

public:
	int getNumRubies()const { return this->rubi; }
	
	friend class RewardDeck;
};

#endif
	
