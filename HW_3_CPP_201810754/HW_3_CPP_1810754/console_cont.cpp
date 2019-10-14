#include "pch.h"
#include "console_cont.h"
//Ŀ���� ���̰�, �Ⱥ��̰� ���ִ� �Լ�
void setCursorView(bool visible)
{
	CONSOLE_CURSOR_INFO cursor = { 1, visible };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);//�ܼ� �ڵ�
}
//���� Ŀ���� ��ġ�� x,y�� �̵����ִ� �Լ�
void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); //Ŀ�� ��ġ ����
}
//������ �ֿܼ��� ����� �ؽ�Ʈ�� ��,������ �ٲ���
void setColor(int color, int bgcolor)
{
	color &= 0xf; //��Ʈ ���� f ����� �� 0���� 
	bgcolor &= 0xf; //��Ʈ ����
	static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� �ڵ� ��������
	SetConsoleTextAttribute(std_output_handle, bgcolor << 4 | color); //�������ڵ�, bg�� ����4��Ʈ ����Ʈ+ color �Ͽ� �� int���� �ȿ� ���,���ڻ����� ���
}

int get_num() {	//�������� �ޱ� ���� �Լ� ������ �ƴ� ���� ������ �ٽ� �Է� �ް�
	int num;

	cin >> num;
	if (cin.fail()) {
		cout << "�ٽ� �Է��ϼ���. : ";
		cin.clear();
		cin.ignore(256, '\n');
		return get_num();
	}
	return num;
}