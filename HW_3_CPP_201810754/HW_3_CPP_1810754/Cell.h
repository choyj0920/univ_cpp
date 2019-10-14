#pragma once
class Cell
{
	bool isboom, ishide, ischeck; //
	int nearboom_count; //이셀 주변 폭탄 갯수 담을 함수
	static int show_count;
public:
	Cell();
	~Cell();
	//맵의 가로세로 변수를 참조변수로 받아와, 사용자에게 가로,세로 크기를 입력 받고 해당하는 크기로 맵생성(동적 할당)
	static Cell **makeMap(int&row, int&col); 
	//매개로 Map과 row,col, boomcount를 참조 변수로 받아와 폭탄갯수를 사용자에게 입력 받아 중복없이 map에 폭탄을 무작위로 설치
	static void hideBoom(Cell **(&map), const int&row, const int&col, int& boomcount);
	//map과 row,col을 참조변수로 받아와 사용자에게 보여줄 맵 상태를 출력
	static void showMap(Cell **(&map), const int &row, const int &col);
	//map,row,col을 참조 변수로 받아와 동적할당한 맵을 할당의 역순으로 할당해제하는 함수
	static void deleteMap(Cell **(&map), const int &row, const int &col);
	//playGame 게임의 실행함수, 맵 생성부터 게임종료까지 
	static void playGame();
	//셀을 이동하여  셀을 열거나 체크할수 있게 하는 함수, 참조변수로 map,row,col을 받으며 
	//지금사용자가 있는 셀위치 x,y도 참조 변수로 받음 셀을 열때 그셀이 폭탄이면 false리턴, 아니면 true 리턴
	static bool select_cell(Cell **(&map), const int&row, const int &col,int& x, int& y);
	//cell을 열어주는 함수, cell을 열때 그 셀의 주변의 폭탄수가 0이라면 자동으로 주변셀을 열어주는 함수
	static void cell_hideoff(Cell **(&map), const int&row, const int &col,int x, int y);
	//셀의 정보를 (x,y)위치에 출력하는 함수
	void printcell(int x, int y) const;
	//게임의 도움말을 출력하는 함수
	static void print_HELP(const int& row, const int& col,const int& boomcount);
};
