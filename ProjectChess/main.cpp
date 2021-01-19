#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main() {
	RenderWindow window(VideoMode(500, 500), "miniChess"/*, Style::None*/);

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
	
	Game game;

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
					game.Init();
				}
				break;
			case Event::MouseButtonPressed:
				if (event.mouseButton.button == Mouse::Left) {
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
					int x = event.mouseButton.x;
					int y = event.mouseButton.y;
					if (game.selectedCheckers(x, y)) {
						Event event1;
						while (window.waitEvent(event1))
							if (event1.type == Event::MouseButtonPressed)
								if (event1.mouseButton.button == Mouse::Left) {
									int x1 = event1.mouseButton.x;
									int y1 = event1.mouseButton.y;
									std::cout << "mouse x1: " << x1 << std::endl;
									std::cout << "mouse y1: " << y1 << std::endl;
									game.motion(x1, y1);
									// enemy turn
									break;
								}
					}
				}
				break;
			default:
				break;
			}
		}

		window.clear(Color(5, 5, 50));
		window.draw(text);
		window.draw(game);
		window.display();
	}
	return 0;
}