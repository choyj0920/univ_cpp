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
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); //Ŀ�� ��ġ ����
}
void setColor(int color, int bgcolor)
{
	color &= 0xf; //��Ʈ ���� 4��Ʈ�� ����� �� 0���� 
	bgcolor &= 0xf; //��Ʈ ����
	static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� �ڵ� ��������
	SetConsoleTextAttribute(std_output_handle, bgcolor << 4 | color); //�������ڵ�, bg�� ����4��Ʈ ����Ʈ+ color �Ͽ� �� int���� �ȿ� ���,���ڻ����� ���
}