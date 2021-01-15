#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Logic.h"

const int SIZE = 8; 
const int FIELD_SIZE = 480;
const int CELL_SIZE = FIELD_SIZE / SIZE;

class Game : public sf::Drawable, public sf::Transformable
{
protected:
	sf::Font font;
	sf::Texture grid;
	sf::Texture rook_white;
	sf::Texture rook_black;
	std::vector<sf::Sprite> player;
	sf::Sprite enemy;
public:
	Game();
	void Init();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

