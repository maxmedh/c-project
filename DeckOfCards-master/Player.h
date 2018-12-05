/*Auteurs: Mohammed Hussen (#7658545)
		   Sydroy Rakotonomenjanahary (#300041897)
*/
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Reward.h"

using namespace std;


typedef enum { Top, Bottom, Left, Right } Side;

class Player {
private:
	bool endOfGame;
	bool active;
	Side side;
	const string name;
	int nRubis;

public:
	Player(){}
	Player(string name) ;

	friend ostream& operator<<(ostream& os, Player& player)	;
	string getName()const ;
	bool isActive() const ;
	int getNRubis() ;
	Side getSide() const ;
	void setSide(Side ) ;
	void setActive(bool) ;
	void addReward(const Reward&);
	void setDisplayMode(bool);
	
private:
	void print();
};
#endif
