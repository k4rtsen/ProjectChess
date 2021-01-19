#include "Game.h"
#include <iostream>
//#include <SFML/Graphics.hpp>
//using namespace sf;

int getLogical(int& x) {
	return (x - CELL_SIZE) / CELL_SIZE;
}

std::vector<int> getMoveCellsIndex(int &x, int &y) {
	for (int i = CELL_SIZE; i < FIELD_SIZE + CELL_SIZE; i += CELL_SIZE)
		for (int j = CELL_SIZE; j < FIELD_SIZE + CELL_SIZE; j += CELL_SIZE) {
			if (i < x && x < i + CELL_SIZE && j < y && y < j + CELL_SIZE) {
				return { (i - CELL_SIZE) / CELL_SIZE, (j - CELL_SIZE) / CELL_SIZE };
			}
			else continue;
		}
	return std::vector<int>();
}

Game::Game() {
	font.loadFromFile("font/8277.ttf");
	grid.loadFromFile("images/setka8x8.png");
	rook_white.loadFromFile("images/rook_white.png");
	rook_black.loadFromFile("images/rook_black.png");
	Init();
}

void Game::Init() {
	if (!player.empty() || !enemy.empty()) {
		player.clear();
		enemy.clear();
	}
	
	logic.Init();//for new game

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
	for (int i = 0; i < logic.getPlCheckers(); i++) {
		int px = this->player[i].getPosition().x;
		int py = this->player[i].getPosition().y;
		if (px < x && x < px + CELL_SIZE && py < y && y < py + CELL_SIZE) {
			this->pre_x = getLogical(px);
			this->pre_y = getLogical(py);
			this->sel_index = i;
			return true;
		}
		else continue;
	}
	return false;
}

void Game::motion(int x, int y) {
	std::vector<int> temp = getMoveCellsIndex(x, y);
	for (auto& freePlace : logic.getFreePlases(this->pre_x, this->pre_y)) {
		if (temp.empty()) {
			break;
		}
		else if (freePlace == temp) {
			int new_x = temp[0];
			int new_y = temp[1];
			logic.shift(this->pre_x, this->pre_y, new_x, new_y);
			checkEnemy(new_x, new_y);
			player[sel_index].move((new_x - this->pre_x) * CELL_SIZE, (new_y - this->pre_y) * CELL_SIZE);
			break;
		}
		else continue;
	}
}

void Game::checkEnemy(int &x, int &y) {
	for (int i = 0; i < logic.getEnCheckers(); i++) {
		int ex = this->enemy[i].getPosition().x;
		int ey = this->enemy[i].getPosition().y;
		if (ex < x && x < ex + CELL_SIZE && ey < y && y < ey + CELL_SIZE) {
			enemy.erase(enemy.begin() + i);
			break;
		}
		else continue;
	}
}

bool Game::endGame() {
	if (logic.getPlCheckers() == 1 && logic.getEnCheckers() == 1) {
		sf::Text text("Endgame", font, 32);
		this->finish = text;
		this->finish.setFillColor(sf::Color::White);
		this->finish.setPosition(200.f, 200.f);
		return true;
	}
	else if (logic.getPlCheckers() == 0) {
		sf::Text text("You lose", font, 32);
		this->finish = text;
		this->finish.setFillColor(sf::Color::White);
		this->finish.setPosition(200.f, 200.f);
		return true;
	}
	else if (logic.getPlCheckers() == 0) {
		sf::Text text("You win", font, 32);
		this->finish = text;
		this->finish.setFillColor(sf::Color::White);
		this->finish.setPosition(200.f, 200.f);
		return true;
	}
	else return false;
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::Transform t;
	states.transform *= t;
	//if (!endGame()) {
		target.draw(this->board, states);
		for (auto& var : this->enemy)
			target.draw(var, states);
		for (auto& var : this->player)
			target.draw(var, states);
	/*}
	else {
		target.draw(this->finish, states);
	}*/
};