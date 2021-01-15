#pragma once
class Logic
{
private:
	const static int SIZE = 8;
	int players_checkers = 9, enemys_checkers = 9;
	int field[SIZE][SIZE] = {
		{2, 2, 2, 0, 0, 0, 0, 0},
		{2, 2, 2, 0, 0, 0, 0, 0},
		{2, 2, 2, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 1, 1},
		{0, 0, 0, 0, 0, 1, 1, 1},
		{0, 0, 0, 0, 0, 1, 1, 1}
	};
	bool checkWin = true;
	bool checkLose = true;

public:
	//int getField();
	void decPlCheckers();
	int getPlCheckers();
	void decEnCheckers();
	int getEnCheckers();
	bool checkWin();
};

