#include <iostream>
#include "Player.h"

Player::Player(string name) : name(name), nRubis(0) {}

void Player::addReward(const Reward & reward){
	this->nRubis += reward.getNumRubies();
}

bool Player::isActive() const { return active; }

int Player::getNRubis() { return nRubis; }
Side Player::getSide() const { return side; }
void Player::setSide(Side side) { this->side = side; }
void Player::setActive(bool active) { this->active = active; }
	
string Player::getName() const { return this->name; }

void Player::setDisplayMode(bool endOfGame){
	this->endOfGame = endOfGame;
}

ostream& operator<<(ostream& os, Player& player)	{
		player.print();
		return os;
	}
	
void Player::print(){
	if (this->endOfGame == true) { 
		cout << this->getName() << ": ";
		cout << this->getNRubis() << " rubies" << endl;
	}
	else {
		cout << this->getName() << ": "; 
		cout << this->getSide() < "(";
		if (this->isActive())
			cout << "active" << ")" << endl;
		else
			cout << "inactive" << ")" << endl;

	}
}

