#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <Windows.h> //윈도우api
#include<conio.h>
#include <fstream>  //파일 입출력
#include <iomanip>
using namespace std;

int **makeMap(int&row, int&col) {
	cout << "맵의 가로와 세로 크기 입력 : ";
	cin >> row >> col;
	int **map = new int*[row];
	for (int i = 0; i < row; i++) {
		map[i] = new int[col];
		for (int j = 0; j < col; j++) {
			map[i][j] = 0;
		}
	}
	return map;
}
void hideBoom(int **(&map),const int&row,const int&col,const int boomcount) {
	for (int i = 0; i < boomcount; i++) {
		int x = rand() % row;
		int y = rand() % col;
		if (map[x][y] != 0) {
			i--;
			continue;
		}
		else
			map[x][y] = 1;
	}
}
void showMap(int **(&map), const int &row, const int &col) {
	string items[] = { "□","♣","■","" }; //0이면 안열림 1이면 폭탄 2이면 열림

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 0 | map[i][j] == 1) {
				cout << items[0];
			}
			else
				cout << items[map[i][j]];
		}
		cout << endl;
	}
	
}
void deleteMap(int **(&map), const int &row, const int &col) {
	for (int i = 0; i < row; i++) {
		delete[] map[i];
	}
	delete[] map;
}
void playGame(int **(&map), const int &row, const int &col,const int &boom) {
	while (true) {
		system("cls");
		showMap(map, row, col);
		cout << "열고자 하는 위치를 선택하세요 : (0부터)";
		int x, y;
		cin >> x >> y;
		if (map[x][y] == 1) {
			cout << "폭탄을 선택했네요, 게임을 종료합니다.";
			return;
		}
		else
			map[x][y] = 2;

		system("pause");
	}

}

void lab01() {
	int row, col;

	int** map = makeMap(row, col);
	hideBoom(map, row, col, 10);
	playGame(map, row, col, 10);
	deleteMap(map, row, col);

	return;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void setCursorView(bool visible)
{
	CONSOLE_CURSOR_INFO cursor = { 1, visible };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
void setColor(short color, short bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_output_handle, bgcolor << 4 | color);
}

void lab02() {
	setCursorView(0);
	int x = 10, y = 10;
	while (true) {
		system("cls");
		gotoxy(x, y);
		setColor(rand() % 15, 0);
		cout << "o";
		switch (_getch())
		{
		case 224: {
			switch (_getch())
			{
			case 72: y -= 1; break;
			case 80: y += 1; break;
			case 75: x -= 2; break;
			case 77: x += 2; break;
			}
			break;
		}
		case 13:
			return;
		}
	}
}

int main() {
	srand((unsigned)time(0));
	cout << "201810754 조윤직"<<endl;
	lab02();
}