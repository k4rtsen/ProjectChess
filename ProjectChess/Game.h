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
	sf::Text finish;
	sf::Texture grid;
	sf::Sprite board;
	sf::Texture rook_white;
	sf::Texture rook_black;
	std::vector<sf::Sprite> player;
	std::vector<sf::Sprite> enemy;
	int pre_x, pre_y, sel_index;
	void setCheckers();
	void checkEnemy(int &x, int &y);

public:
	Game();
	void Init(); // create new game
	bool selectedCheckers(int x, int y);
	void motion(int x, int y);
	bool endGame();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawFinish(sf::RenderTarget& target, sf::RenderStates states) const;
};
