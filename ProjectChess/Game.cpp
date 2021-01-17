#include "Game.h"
#include <iostream>
//#include <SFML/Graphics.hpp>
//using namespace sf;

int getLogicalX(int &x, int& y, std::vector<sf::Sprite> &sprite) {
	for (auto& var : sprite) {
		int px = var.getPosition().x;
		int py = var.getPosition().y;
		if (px < x && x < px + CELL_SIZE && py < y && y < py + CELL_SIZE) {
			int result = (px - CELL_SIZE) / CELL_SIZE;
			return result;
		}
	}
}

int getLogicalY(int& x, int& y, std::vector<sf::Sprite>& sprite) {
	for (auto& var : sprite) {
		int px = var.getPosition().x;
		int py = var.getPosition().y;
		if (px < x && x < px + CELL_SIZE && py < y && y < py + CELL_SIZE) {
			int result = (py - CELL_SIZE) / CELL_SIZE;
			return result;
		}
	}
}

std::vector<int> getMoveCell(int &x, int &y) {
	for (int i = CELL_SIZE; i < FIELD_SIZE; i += 50)
		for (int j = CELL_SIZE; j < FIELD_SIZE; j += 50) {
			if (i < x && x < i + CELL_SIZE && j < y && y < j + CELL_SIZE) {
				return {(i-CELL_SIZE)/CELL_SIZE, (j - CELL_SIZE) / CELL_SIZE };
			}
		}
}

Game::Game() {
	font.loadFromFile("font/8277.ttf");
	grid.loadFromFile("images/setka8x8.png");
	rook_white.loadFromFile("images/rook_white.png");
	rook_black.loadFromFile("images/rook_black.png");
	Init();
}

void Game::Init() {
	//clearing-------
	if (!player.empty() && !enemy.empty()) {
		player.clear();
		enemy.clear();
	}
	this->pre_x = -1;
	this->pre_y = -1;
	//----------------
	this->board.setTexture(grid);
	this->board.setPosition(CELL_SIZE, CELL_SIZE);

	for (int i = 0; i < logic.getEnCheckers(); i++) {
		sf::Sprite temp;
		temp.setTexture(rook_black);
		this->enemy.push_back(temp);
	}
	for (int i = 0; i < logic.getPlCheckers(); i++) {
		sf::Sprite temp;
		temp.setTexture(rook_white);
		this->player.push_back(temp);
	}
	setCheckers();
}

void Game::setCheckers() {
	int iteratEn = logic.getEnCheckers();
	int iteratPl = logic.getPlCheckers();
	for (int i = 0; i < logic.field.size(); i++) {
		for (int j = 0; j < logic.field[i].size(); j++) {
			if (logic.field[i][j] == 2) {
				this->enemy[--iteratEn].setPosition(i * CELL_SIZE + CELL_SIZE, j * CELL_SIZE + CELL_SIZE);
			}
			else if (logic.field[i][j] == 1) {
				this->player[--iteratPl].setPosition(i * CELL_SIZE + CELL_SIZE, j * CELL_SIZE + CELL_SIZE);
			}
		}
	}
}

bool Game::selectedCheckers(int x, int y) {
	for (auto& sprite : player) {
		int px = sprite.getPosition().x;
		int py = sprite.getPosition().y;
		if (px < this->pre_x && this->pre_x < px + CELL_SIZE && py < this->pre_y && this->pre_y < py + CELL_SIZE) {
			this->pre_x = getLogicalX(x, y, player);
			this->pre_y = getLogicalY(x, y, player);
			return true;
		}
		else continue;
	}
	return false;
}

void Game::motion(int x, int y) {
	if (this->pre_x != -1 && this->pre_y != -1) {
		for (auto& freePlace : logic.getFreePlases(this->pre_x, this->pre_y)) {
			if (freePlace == getMoveCell(x, y)) {

			}
		}
	}
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::Transform t;
	states.transform *= t;
	target.draw(this->board, states);
	for (auto &var : this->enemy)
		target.draw(var, states);
	for (auto& var : this->player)
		target.draw(var, states);
};