#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void lab01() {
	srand((unsigned)time(NULL));
	string items[4] = { "��"," @"," ��"," ��" };
	int map[10][10] = { 0, };
	
	for (int i = 0; i < 3; i++) {
		int a, b;
		a = rand() % 10;
		b = rand() % 10;
		if (map[a][b] != 0) {
			i--;
			continue;
		}
		map[a][b] = i+1;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout<<items[map[i][j]];
		}
		cout << endl;
	}
}
void lab02() {
	int std[3][2][4] ={ 
		{ {12,35,24,55}, {55,33,11,23} }, 
		{ {100,60, 60,32} ,{12,45,55,33} }, 
		{ {12,90,55,33}, {12,90,100,45} }
	};
	int sum[4] = { 0, };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 4; k++)
				sum[i] += std[i][j][k];
		sum[i] /= 2 * 4;
		sum[3] += sum[i];
		cout << "�б� " << i << "�� ��� ���� = " << sum[i] << endl;
	}
	sum[3] /= 3;
	cout << "��ü �л����� ��� ���� = " << sum[3] << endl;


}
void lab03() {
	const int ROW =6;
	const int COL= 4;
	int seats[ROW][COL] = { 0, };
	int rScount = 0;
	while (true) {
		cout << "\t";
		for (int i = 0; i < COL; i++) {
			cout << i+1 << '\t';
		}
		cout << endl;
		for (int i = 0; i < ROW; i++) {
			cout << (char)('A' + i) << '\t';
			for (int j = 0; j < COL; j++) {
				cout << (seats[i][j] ? "��" : "O" )<< '\t';
			}
			cout << endl;
		}
		if (rScount > 24) {
			cout << "���¼� ���� �Ϸ�" << endl;
			break;
		}
		cout << "������ �¼��� �Է��ϼ��� : (�� ==> A 1/ ����� 0 0) : ";
		char x ,y;
		cin >> y >> x;
		//���� �ڵ�
		if (x == '0' && y == '0') {
			cout << "����..\n";
			break;
		}
		//�Է� ���� üũ
		if (y < 'A' || y > 'F' || x<'1' || x>'4') {
			cout << "�߸� �Է��ϼ̽��ϴ�. ����� �� ���� �Է��� �ּ���.\n ";
			system("pause");
			system("cls");
			continue;
		}
		//���� �Ҽ� �������
		if (seats[y - 'A'][x - '1'] ==0) {
			seats[y - 'A'][x - '1'] = 1;
			rScount++;
			cout << "���� �Ϸ�\n";
		}
		// ���� �Ұ��� ��
		else
			cout << "�̹� ������ �� �ڸ� �Դϴ�. ���� �Ұ�\n";

		

		system("pause");
		system("cls");
	}
}

int main() {
	cout << "201810754 ������\n";
	lab03();
}