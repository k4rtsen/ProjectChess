#pragma once
#include <vector>
class Logic
{
private:
	const static int SIZE = 8;
	int players_checkers, enemys_checkers;
	bool checkWin = true;
	bool checkLose = true;
	void decEnCheckers();
	void decPlCheckers();
	
public:
	Logic();
	void Init();
	int getPlCheckers();
	int getEnCheckers();
	std::vector<std::vector<int>> field;
	std::vector<std::vector<int>> getFreePlases(int x, int y);
	void shift(int x, int y, int move_x, int move_y);
};