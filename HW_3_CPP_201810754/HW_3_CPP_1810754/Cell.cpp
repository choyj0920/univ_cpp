#include "pch.h"
#include "Cell.h"

Cell::Cell()
{
	//생성 될때 변수 초기화
	ischeck = isboom = false;
	ishide = true;
	nearboom_count = 0;

}


Cell::~Cell()
{
}

Cell ** Cell::makeMap(int & row, int & col)
{
	cout << "맵의 가로와 세로 크기 입력 : ";
	cin >> col >> row;
	Cell** map = new Cell*[row];
	for (int i = 0; i < row; i++)
		map[i] = new Cell[col];

	return map;
}

void Cell::hideBoom(Cell **(&map), const int & row, const int & col, int& boomcount)
{
	cout << "맵안에 폭탄 갯수 입력 : ";
	cin >> boomcount;
	while (boomcount > (row*col)) {
		cout << "폭탄 갯수가 맵의 칸수보다 많습니다 . 다시 입력해 주세요";
		cin >> boomcount;
	}
	for (int i = 0; i < boomcount; i++) {
		int x = rand() % row;
		int y = rand() % col;
		if (map[x][y].isboom == true) {
			i--;
			continue;
		}
		else {
			map[x][y].isboom = true;
			if (x > 0) {
				map[x - 1][y].nearboom_count++;
				if (y > 0) map[x - 1][y - 1].nearboom_count++;
				if (y < col - 1) map[x - 1][y + 1].nearboom_count++;
			}
			if (y > 0) map[x][y - 1].nearboom_count++;
			if (y < col - 1) map[x][y + 1].nearboom_count++;
			if (x < row - 1) {
				map[x + 1][y].nearboom_count++;
				if (y > 0) map[x +1][y - 1].nearboom_count++;
				if (y < col - 1) map[x + 1][y + 1].nearboom_count++;
			}
		}
	}
}

void Cell::playGame()
{
	Cell** map;
	int row, col, boomcount;
	show_count = 0;
	int x = 0, y = 0;
	map = makeMap(row, col);
	hideBoom(map, row, col, boomcount);
	while (show_count + boomcount < row*col) {
		system("cls");
		gotoxy(0, 0); cout << "-----------지뢰 찾기-----------";
		showMap(map, row, col);
		if (select_cell(map, row, col, x, y))
			break;
	}
	
	deleteMap(map, row, col);
}

bool Cell::select_cell(Cell **(&map), const int & row, const int & col, int& x, int& y)
{

	int old_x= x,old_y= y;
	while (true) {
		int key = 0;

		if (_kbhit()) {
			key = _getch();
			if (key == ARROWKEY || key == 0) {
				key = _getch();
				switch (key)
				{
				case UP:
					y--;
					break;
				case DOWN:
					y++;
					break;
				case LEFT:
					x--;
					break;
				case RIGHT:
					x++;
					break;
				}
				if (y < 0)
					y = row-1;
				if (y >= row)
					y = 0;
				if (x < 0)
					x = col - 1;
				if (x >= col)
					x = 0;
				setColor(7,0);
				map[old_y][old_x].printcell(old_x*2, 2+ old_y);
				old_x = x, old_y = y;
				setColor(6, 0);
				map[y][x].printcell(x*2,2 +  y);
				setColor(7, 0);

			}
			else if (key == ENTER) {
				if (map[y][x].isboom)
					return false;
				else {
					cell_hideoff(map, row, col, y, x);
					return true;
				}
			}
			else if (key == 'G'||key =='g') {
				if(map[y][x].ishide)			
					map[y][x].ischeck = !map[y][x].ischeck;
				return true;
			}
		}
	}
}

void Cell::cell_hideoff(Cell **(&map), const int & row, const int & col, int x, int y)
{
	if (map[x][y].ishide) {
		if (map[x][y].nearboom_count == 0) {  //이 셀의 주변 폭탄 갯수가 0이라면
			map[x][y].ishide = false;
			if (x > 0) {//맨 위쪽 셀이 아니라면
				cell_hideoff(map, row, col, x - 1, y); //바로 위에칸
				if (y > 0) cell_hideoff(map, row, col, x - 1, y - 1); //위 왼쪽칸
				if (y < col - 1) cell_hideoff(map, row, col, x - 1, y + 1); //위 오른쪽칸
			}
			if (y > 0) cell_hideoff(map, row, col, x, y - 1);  //왼쪽칸
			if (y < col - 1) cell_hideoff(map, row, col, x, y + 1); //오른쪽칸
			if (x < row - 1) {
				cell_hideoff(map, row, col, x + 1, y);; //아래칸
				if (y > 0) cell_hideoff(map, row, col, x + 1, y - 1);
				if (y < col - 1) cell_hideoff(map, row, col, x + 1, y +1);
			}
			return;
		}
		map[x][y].ishide = false;
		
	}
	else {
		
		return;
	}
		
}

void Cell::printcell(int x, int y) const
{
	string aa[] = {"□","1","2","3","4" };
	gotoxy(x, y);
	if (ishide) {
		if (ischeck)
			cout << "★";
		else
			cout << "■";
	}
	else {
		cout << aa[nearboom_count];
	}

}


void Cell::showMap(Cell **(&map), const int & row, const int & col)
{
	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			map[y][x].printcell(x*2,2+ y);
		}
	}
}

void Cell::deleteMap(Cell **(&map), const int & row, const int & col)
{
	for (int i = 0; i < row; i++) {
		delete[] map[i];
	}
	delete[] map;
}

