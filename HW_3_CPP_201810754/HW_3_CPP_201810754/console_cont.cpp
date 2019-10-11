#include "pch.h"
#include "console_cont.h"
using namespace std;

void setCursorView(bool visible)
{
	CONSOLE_CURSOR_INFO cursor = { 1, visible };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); //커서 위치 변경
}
void setColor(int color, int bgcolor)
{
	color &= 0xf; //비트 연산 4비트만 남기고 다 0으로 
	bgcolor &= 0xf; //비트 연산
	static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 핸들 가져오기
	SetConsoleTextAttribute(std_output_handle, bgcolor << 4 | color); //윈도우핸들, bg를 왼쪽4비트 쉬프트+ color 하여 한 int변수 안에 배경,글자색정보 담기
}