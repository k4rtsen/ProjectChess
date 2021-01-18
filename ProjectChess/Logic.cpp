#include "Logic.h"

Logic::Logic() {
	this->players_checkers = 9;
	this->enemys_checkers = 9;
	this->field = {
		{2, 2, 2, 0, 0, 0, 0, 0},
		{2, 2, 2, 0, 0, 0, 0, 0},
		{2, 2, 2, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 1, 1},
		{0, 0, 0, 0, 0, 1, 1, 1},
		{0, 0, 0, 0, 0, 1, 1, 1}
	};
}

void Logic::Init() {
	this->players_checkers = 9;
	this->enemys_checkers = 9;
	this->field = {
		{2, 2, 2, 0, 0, 0, 0, 0},
		{2, 2, 2, 0, 0, 0, 0, 0},
		{2, 2, 2, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 1, 1},
		{0, 0, 0, 0, 0, 1, 1, 1},
		{0, 0, 0, 0, 0, 1, 1, 1}
	};
}

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

std::vector<std::vector<int>> Logic::getFreePlases(int x, int y) {
	std::vector<std::vector<int>> temp;
	if (x == 0) {
		if (y == 0) {
			for (int i = x; i <= x + 1; i++)
				for (int j = y; j <= y + 1; j++)
					if (this->field[i][j] == 0 || this->field[i][j] == 2)
						temp.push_back({ i, j });
		}
		else if (y == 7) {
			for (int i = x; i <= x + 1; i++)
				for (int j = y - 1; j <= y; j++)
					if (this->field[i][j] == 0 || this->field[i][j] == 2)
						temp.push_back({ i, j });
		}
		else {
			for (int i = x; i <= x + 1; i++)
				for (int j = y - 1; j <= y + 1; j++)
					if (this->field[i][j] == 0 || this->field[i][j] == 2)
						temp.push_back({ i, j });
		}
	}
	else if (x == 7) {
		if (y == 0) {
			for (int i = x - 1; i <= x; i++)
				for (int j = y; j <= y + 1; j++)
					if (this->field[i][j] == 0 || this->field[i][j] == 2)
						temp.push_back({ i, j });
		}
		else if (y == 7) {
			for (int i = x - 1; i <= x; i++)
				for (int j = y - 1; j <= y; j++)
					if (this->field[i][j] == 0 || this->field[i][j] == 2)
						temp.push_back({ i, j });
		}
		else {
			for (int i = x - 1; i <= x; i++)
				for (int j = y - 1; j <= y + 1; j++)
					if (this->field[i][j] == 0 || this->field[i][j] == 2)
						temp.push_back({ i, j });
		}
	}
	else if (y == 0) {
		for (int i = x - 1; i <= x + 1; i++)
			for (int j = y; j <= y + 1; j++)
				if (this->field[i][j] == 0 || this->field[i][j] == 2)
					temp.push_back({ i, j });
	}
	else if (y == 7) {
		for (int i = x - 1; i <= x + 1; i++)
			for (int j = y - 1; j <= y; j++)
				if (this->field[i][j] == 0 || this->field[i][j] == 2)
					temp.push_back({ i, j });
	}
	else {
		for (int i = x - 1; i <= x + 1; i++)
			for (int j = y - 1; j <= y + 1; j++)
				if (this->field[i][j] == 0 || this->field[i][j] == 2)
					temp.push_back({ i, j });
	}
	return temp;
}

void Logic::shift(int x, int y, int move_x, int move_y) {
	if (field[x][y] == 1 && field[move_x][move_y] == 0) {
		field[x][y] = 0;
		field[move_x][move_y] = 1;
	}
	else if (field[x][y] == 1 && field[move_x][move_y] == 2) {
		field[x][y] = 0;
		field[move_x][move_y] = 1;
		decEnCheckers();
	}
};