#include "pch.h"
#include "Cell.h"

Cell::Cell()
{
	//생성 될때 변수 초기화
	isboom = false;
	ishide = true;
	nearboom_count = 0;
}


Cell::~Cell()
{
}

Cell ** Cell::makeMap(int & row, int & col)
{
	cout << "맵의 가로와 세로 크기 입력 : ";
	Cell** map = new Cell*[row];
	for (int i = 0; i < row; i++)
		map[i] = new Cell[col];
	
	return map;
}

void Cell::hideBoom(Cell **(&map), const int & row, const int & col, const int boomcount)
{
	for (int i = 0; i < boomcount; i++) {
		int x = rand() % row;
		int y = rand() % col;
		if (map[x][y].isboom = true) {
			i--;
			continue;
		}
		else {
			map[x][y].isboom = true;
			if (x > 0) map[x - 1][y].nearboom_count++;
			if (x < row - 1) map[x + 1][y].nearboom_count++;
			if (y > 0) map[x][y - 1].nearboom_count++;
			if (y < col - 1) map[x][y + 1].nearboom_count++;
		}
	}
}

void Cell::playGame()
{
	Cell** map;
	int row, col, boomcount;
	map = makeMap(row, col);
	
	deleteMap(map, row, col);
}

void Cell::printcell(int x, int y)
{
	if (ishide) {
		setColor(8, 7);
		gotoxy(x - 1, y - 1); cout << "┌─┐";
		gotoxy(x - 1, y);	    cout << "│  │";
		gotoxy(x - 1, y + 1); cout << "└─┘";
	}
	else {
		gotoxy(x - 1, y - 1); cout << "┌─┐";
		gotoxy(x - 1, y - 1);
	}
	
}


void Cell::showMap(const Cell **(&map), const int & row, const int & col)
{
	

}
void Cell::deleteMap(Cell **(&map), const int & row, const int & col)
{
	for (int i = 0; i < row; i++) {
		delete[] map[i];
	}
	delete[] map;
}

