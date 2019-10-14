#include "pch.h"
#include "Cell.h"

Cell::Cell()
{
	//생성 될때 변수 초기화
	ischeck = isboom = false;
	ishide = true;
	nearboom_count = 0;
}
//셀클래스의  정적 멤버 변수 show_count선언 
int Cell::show_count = 0;

//cell의 소멸자
Cell::~Cell()
{
}
	
Cell ** Cell::makeMap(int & row, int & col)
{
	cout << "맵의 가로와 세로 크기 입력 : ";
	col = get_num();
	row = get_num();
	Cell** map = new Cell*[row]; //
	for (int i = 0; i < row; i++)
		map[i] = new Cell[col]; //맵의 칸마다 cell객채생성

	return map;
}

void Cell::hideBoom(Cell **(&map), const int & row, const int & col, int& boomcount)
{
	cout << "맵안에 폭탄 갯수 입력 : ";
	boomcount = get_num();
	//입력한 폭탄이 맵의 칸수보다 작아야함!
	while (boomcount >= (row*col)) { //그럴때까지 재입력
		cout << "폭탄 갯수가 맵의 칸수보다 많거나 같습니다 . 다시 입력해 주세요";
		boomcount = get_num();

	}
	//폭탄 숨기기
	for (int i = 0; i < boomcount; i++) {
		int x = rand() % row;//랜덤한 row
		int y = rand() % col; //랜덤한 col
		if (map[x][y].isboom == true) {
			i--; //폭탄일 경우 다시 뽑기
			continue;
		}
		else {
			map[x][y].isboom = true;
			//주변 cell에 nearboom_count더해주기
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
	int x = 0, y = 0; //사용자가 위치한 셀
	map = makeMap(row, col); //맵 할당
	hideBoom(map, row, col, boomcount);//폭탄 숨기기
	setCursorView(false); //이제 커서 안보이게
	while (show_count + boomcount < row*col) { //폭탄을 제외한 셀을 다 열 때까지 반복 
		system("cls"); 
		print_HELP(row, col, boomcount); //도움말 출력
		gotoxy(0, 0); cout << "-----------지뢰 찾기-----------";
		showMap(map, row, col); //맵보여주기
		if (!select_cell(map, row, col, x, y)) { //select_cell함수 실행 -리턴false(폭탄을 열음)
			gotoxy(0, 0); cout << "--------GAME OVER!---------" << endl; //게임오버 표시
			Sleep(2000); //2초 있다가
			system("cls");
			cout << "게임에서 지셨네요..." << endl;//게임패배 문구 출력
			return; //playgame 종료
		}
	}
	//while문 나왔는데 종료 x? -> 지뢰찾기 성공
	gotoxy(0, 0); cout << "--------지뢰 찾기 성공!!---------" << endl;
	print_HELP(row, col, boomcount); //열은 셀 횟수 다시 보여주기
	Sleep(2000); //2초쉬고
	system("cls");
	cout << "게임에서 승리하셨습니다.\n"; //게임승리 문구 출력
	deleteMap(map, row, col);
}

bool Cell::select_cell(Cell **(&map), const int & row, const int & col, int& x, int& y)
{
	//지금 커서가있는 셀 색칠
	setColor(6, 0); 
	map[y][x].printcell(x * 2, 2 + y);
	setColor(7, 0);
	int old_x= x,old_y= y; //원래 셀 저장해두고
	while (true) {
		int key = 0;

		if (_kbhit()) {//키 입력시에만 실행
			key = _getch();
			if (key == ARROWKEY || key == 0) {//방향키이면
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
				map[old_y][old_x].printcell(old_x*2, 2+ old_y);//이전셀 원래 색으로 색칠
				old_x = x, old_y = y;
				setColor(6, 0);
				map[y][x].printcell(x*2,2 +  y); //커서가 이동한 셀 색칠
				setColor(7, 0);

			}
			else if (key == ENTER) {//엔터 입력시
				if (map[y][x].isboom)//폭탄이면 false 리턴
					return false;
				else {
					cell_hideoff(map, row, col, y, x);//폭탄아니면 true리턴
					return true;
				}
			}
			else if (key == 'G'||key =='g') {//체크버튼 G or g입력
				if(map[y][x].ishide)			//숨겨져있는 셀이라면
					map[y][x].ischeck = !map[y][x].ischeck;// 체크되있다고바꾸기
				return true; //
			}
		}
	}
}

void Cell::cell_hideoff(Cell **(&map), const int & row, const int & col, int x, int y)
{
	if (map[x][y].ishide) {
		if (map[x][y].nearboom_count == 0) {  //이 셀의 주변 폭탄 갯수가 0이라면 
			show_count++; //열리니까 show_count 1더하기
			map[x][y].ishide = false; //이 셀 보이게
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
		show_count++;//열리니까 show_count 1더하기
		map[x][y].ishide = false;//이 셀 보이게
		
	}
	else {
		
		return;
	}
}

void Cell::printcell(int x, int y) const
{
	string aa[] = {"□","1","2","3","4","5","6","7","8" };//셀에 출력할 문자열
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

void Cell::print_HELP(const int& row, const int& col, const int& boomcount)
{
	int posx = col * 2+4;
	int posy = 2;
	gotoxy(posx, posy++); cout << "======도움말======";
	gotoxy(posx, posy++); cout << "숫자 : 그 셀을 둘러싼 폭탄의 갯수";
	gotoxy(posx, posy++); cout << "□ : 주위에 폭탄 없음. ";
	gotoxy(posx, posy++); cout << "연한 초록으로 현재 셀 표기";
	gotoxy(posx, posy++); cout << "셀을 이동 : 방향키 ";
	gotoxy(posx, posy++); cout << "셀 열기 : 'ENTER' ";
	gotoxy(posx, posy++); cout << "셀 ★로 체크해 두기 : 'G'"; 
	gotoxy(posx, posy++); printf("셀 설정 %d X %d ", row, col);
	gotoxy(posx, posy++); cout << "폭탄 수 : " << boomcount;
	gotoxy(posx, posy++); cout << "지금 까지 연 셀 : "<<show_count;

}

void Cell::showMap(Cell **(&map), const int & row, const int & col)
{
	//맵 보여주기
	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			map[y][x].printcell(x*2,2+ y);
		}
	}
}

void Cell::deleteMap(Cell **(&map), const int & row, const int & col)
{
	//동적할당 해제 
	for (int i = 0; i < row; i++) {
		delete[] map[i];
	}
	delete[] map;
}

