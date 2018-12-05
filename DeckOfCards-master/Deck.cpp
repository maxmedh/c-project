#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Deck.h"

template class Deck<Card>;
template class Deck<Reward>;

template <class C>
void Deck<C>::shuffle(){
	srand(std::time(0));
	random_shuffle(deck.begin(), deck.end());
	crtCard = &deck.front();
}


template <class C>
C* Deck<C>::getNext(){
	C* next;

	if (crtCard == &deck.back()) {
		next = crtCard;
		crtCard = nullptr;
	}else {
		next = crtCard++;
	}
	return next;
}

template<class C>
bool Deck<C>::isEmpty() const{
	return (crtCard == nullptr);
}


