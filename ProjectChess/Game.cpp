#include "Game.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Game::Game() {
	font.loadFromFile("font/8277.ttf");
	grid.loadFromFile("images/setka8x8.png");
	rook_white.loadFromFile("images/rook_white.png");
	rook_black.loadFromFile("images/rook_black.png");
};

void Init() {

};