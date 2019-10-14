#pragma once
class Cell
{
	bool isboom, ishide, ischeck; //
	int nearboom_count; //�̼� �ֺ� ��ź ���� ���� �Լ�
	static int show_count;
public:
	Cell();
	~Cell();
	//���� ���μ��� ������ ���������� �޾ƿ�, ����ڿ��� ����,���� ũ�⸦ �Է� �ް� �ش��ϴ� ũ��� �ʻ���(���� �Ҵ�)
	static Cell **makeMap(int&row, int&col); 
	//�Ű��� Map�� row,col, boomcount�� ���� ������ �޾ƿ� ��ź������ ����ڿ��� �Է� �޾� �ߺ����� map�� ��ź�� �������� ��ġ
	static void hideBoom(Cell **(&map), const int&row, const int&col, int& boomcount);
	//map�� row,col�� ���������� �޾ƿ� ����ڿ��� ������ �� ���¸� ���
	static void showMap(Cell **(&map), const int &row, const int &col);
	//map,row,col�� ���� ������ �޾ƿ� �����Ҵ��� ���� �Ҵ��� �������� �Ҵ������ϴ� �Լ�
	static void deleteMap(Cell **(&map), const int &row, const int &col);
	//playGame ������ �����Լ�, �� �������� ����������� 
	static void playGame();
	//���� �̵��Ͽ�  ���� ���ų� üũ�Ҽ� �ְ� �ϴ� �Լ�, ���������� map,row,col�� ������ 
	//���ݻ���ڰ� �ִ� ����ġ x,y�� ���� ������ ���� ���� ���� �׼��� ��ź�̸� false����, �ƴϸ� true ����
	static bool select_cell(Cell **(&map), const int&row, const int &col,int& x, int& y);
	//cell�� �����ִ� �Լ�, cell�� ���� �� ���� �ֺ��� ��ź���� 0�̶�� �ڵ����� �ֺ����� �����ִ� �Լ�
	static void cell_hideoff(Cell **(&map), const int&row, const int &col,int x, int y);
	//���� ������ (x,y)��ġ�� ����ϴ� �Լ�
	void printcell(int x, int y) const;
	//������ ������ ����ϴ� �Լ�
	static void print_HELP(const int& row, const int& col,const int& boomcount);
};
