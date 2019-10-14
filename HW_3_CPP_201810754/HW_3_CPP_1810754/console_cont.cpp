#include "pch.h"
#include "console_cont.h"
//커서를 보이게, 안보이게 해주는 함수
void setCursorView(bool visible)
{
	CONSOLE_CURSOR_INFO cursor = { 1, visible };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);//콘솔 핸들
}
//지금 커서의 위치를 x,y로 이동해주는 함수
void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); //커서 위치 변경
}
//앞으로 콘솔에서 출력할 텍스트의 색,배경색을 바꿔줌
void setColor(int color, int bgcolor)
{
	color &= 0xf; //비트 연산 f 남기고 다 0으로 
	bgcolor &= 0xf; //비트 연산
	static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 핸들 가져오기
	SetConsoleTextAttribute(std_output_handle, bgcolor << 4 | color); //윈도우핸들, bg를 왼쪽4비트 쉬프트+ color 하여 한 int변수 안에 배경,글자색정보 담기
}

int get_num() {	//정수만을 받기 위한 함수 정수가 아닌 값을 받으면 다시 입력 받게
	int num;

	cin >> num;
	if (cin.fail()) {
		cout << "다시 입력하세요. : ";
		cin.clear();
		cin.ignore(256, '\n');
		return get_num();
	}
	return num;
}