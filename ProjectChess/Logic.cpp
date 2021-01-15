#include "Logic.h"

void Logic::decPlCheckers() {
	this->players_checkers--;
}

int Logic::getPlCheckers() {
	return this->players_checkers;
}

void Logic::decEnCheckers() {
	this->enemys_checkers--;
}

int Logic::getEnCheckers() {
	return this->enemys_checkers;
}

bool Logic::checkWin()
{
	return false;
};