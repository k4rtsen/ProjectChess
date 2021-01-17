#pragma once
#include <vector>
class Logic
{
private:
	const static int SIZE = 8;
	int players_checkers, enemys_checkers;
	
	bool checkWin = true;
	bool checkLose = true;

public:
	Logic();
	~Logic();
	std::vector<std::vector<int>> field;
	void decPlCheckers();
	int getPlCheckers();
	void decEnCheckers();
	int getEnCheckers();
	std::vector<std::vector<int>> getFreePlases(int x, int y);
};

