#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Logic.h"

const int CELLS = 8; 
const int FIELD_SIZE = 400;
const int CELL_SIZE = FIELD_SIZE / CELLS;

class Game : public sf::Drawable, public sf::Transformable
{
protected:
	Logic logic;
	sf::Font font;
	sf::Texture grid;
	sf::Sprite board;
	sf::Texture rook_white;
	sf::Texture rook_black;
	std::vector<sf::Sprite> player;
	std::vector<sf::Sprite> enemy;
	int pre_x, pre_y;
public:
	Game();
	void Init(); // create new game
	void setCheckers();
	bool selectedCheckers(int x, int y);
	void motion(int x, int y);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

