#include "Game.h"
#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
	RenderWindow window(VideoMode(500, 500), "miniChess"/*, Style::None*/);
	//window.setFramerateLimit(60);

	// Set Icon
	Image icon;
	if (!icon.loadFromFile("images/icon.png"))
		return 0;
	window.setIcon(32, 32, icon.getPixelsPtr());

	// Instruction
	Font font;
	if (!font.loadFromFile("font/8277.ttf")) 
		return 0;
	Text text("F1 - New Game / Esc - Exit / LMB - Move checkers", font, 22);
	text.setFillColor(sf::Color::White);
	text.setPosition(5.f, 5.f);

	Sprite player;
	//player.setTexture(rook_white);
	player.setPosition(50, 50);
	
	Sprite enemy;
	//enemy.setTexture(rook_black);
	enemy.setPosition(400, 50);
	
	while (window.isOpen()) {
		Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;

            case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape) {
					window.close();
				}
				else if (event.key.code == Keyboard::F1) {

				}
                break;

            default:
                break;
            }
        }

		window.clear(Color::Blue);
		window.draw(text);
		window.display();
	}
	return 0;
}