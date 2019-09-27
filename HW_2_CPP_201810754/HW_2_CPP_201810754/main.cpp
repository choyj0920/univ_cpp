#include <iostream>
#include <Windows.h>
#include<iomanip>
#include <string>
using namespace std;

int get_num();

void book_movie();
void cancel_movie();
void check_movie();
void print_seat();

const int SEAT_COUNT = 36;  //�� ��ȭ�� ��ü �¼��� ��� ����
int ticketnum[3][SEAT_COUNT] = { 0, };  //����� �ڸ� ���Ź�ȣ�� ǥ��, 0�ϰ�� ����x
int moviebookcount[3] = { 0,0,0 };	//��ȭ�� ����� �¼� ����
int ticket_count[3] = { 1,1,1 }; //����� Ƚ��(�¼���x)
string movienames[3] = { "����Ʈ     ", "������ �̽��͸�", " ���� �༮��  " };  //��ȭ �̸� ����� ���� ��Ʈ���迭
string seat_print[] = { "��", "��" };  //�¼� ��� �Ҷ� (������������¼� ,���� �� �¼�)

int choice;  //���� �� ��ȭ 

int main()
{
	int menu = 0;
	//���� ����� ���� 2�� ��ȭ�� �����ȣ 201�� �¼� 36���� ����Ǿ��ٰ� ����
	for (int i = 0; i < SEAT_COUNT; i++) {	
		moviebookcount[1]++;
		ticketnum[1][i] = 1;
	}
	ticket_count[1] = 2;

	while (menu != 4) {
		menu = 0;	
		while (menu > 4 || menu < 1) {
			system("cls");
			cout << "======== 201810754 ������ ==========" << endl;
			cout << "1) ��ȭ ����   2) �������   3) ����Ȯ��   4) ����" << endl;
			cout << "�޴��� �����ϼ��� : ";
			menu = get_num();

		}

		switch (menu)
		{
		case 1:
			book_movie();
			break;
		case 2:
			cancel_movie();
			break;
		case 3:
			check_movie();
			break;
		case 4:
			break;

		}
		
		system("pause");
	}
}

//�������� �ޱ� ���� �Լ� ������ �ƴ� ���� ������ �ٽ� �Է� �ް�
int get_num() {
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

void book_movie() {
	cout << "========��ȭ ����========\n";
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << ")   " <<setw(16)<<movienames[i] << "\t";
		if (moviebookcount[i] < SEAT_COUNT)
			cout << moviebookcount[i] << " / " << SEAT_COUNT << endl;
		else
			cout << "����\n";
	}
	do { //���� �� ��ȭ ����
		cout << "������ ��ȭ�� ���� �ϼ��� : ";
		choice = get_num() - 1;
	} while (choice < 0 || choice >2);  //3���߿� ������ �� ���� 
	if (moviebookcount[choice] == SEAT_COUNT) {
		cout << "�˼��մϴ� . �� ��ȭ�� ���� �Դϴ�. \n";
		return ;
	}
	cout << "������ �¼� ������ �Է��ϼ���(1~36) : ";
	int seat_count = get_num();
	int booknum = moviebookcount[choice] +1 ;
	for (int i = 0; i < seat_count;) {
		print_seat();

		cout <<i+1<<"��° " <<"�¼��� ���ϼ��� (��  A 3, 0 0 �Է½� ����) : ";
		char x, y;
		cin >> y >> x;
		//���� �ڵ�
		if (x == '0' && y == '0') {
			cout << "����..\n";
			seat_count = i ;
			break;
		}
		//�Է� ���� üũ
		if (y < 'A' || y > 'F' || x<'1' || x>'6') {
			cout << "�߸� �Է��ϼ̽��ϴ�. ����� �� ���� �Է��� �ּ���.\n ";
			continue;
		}
		//���� �Ҽ� �������
		if (ticketnum[choice][(y - 'A') * 6 + (x - '1')] == 0) {
			ticketnum[choice][(y - 'A') * 6 + (x - '1')] = ticket_count[choice];
			moviebookcount[choice]++;
			i++;
			cout << "���� �Ϸ�\n";
		}
	}
	cout << "������ �¼� " << seat_count << " ��" << endl;
	for (int i = 0; i < SEAT_COUNT; i++) 
		if (ticketnum[choice][i] == ticket_count[choice])
			cout << (char)((i / 6) + 'A') << " " << (char)(i % 6 + '1')<<"  ";
	if (seat_count == 0) {
		cout << "������ �¼� ����. ���� �����ʽ��ϴ�.\n";
	}
	else {
		cout << "���� ��ȣ�� " << (choice + 1) * 100 + ticket_count[choice] << "�Դϴ�. \n";
		ticket_count[choice]++;

	}
	
	
}

void print_seat() {
	system("cls");
	cout << "������ ��ȭ : " << movienames[choice] << endl << "=========�¼� =========\n";
	//�¼� �� ����  ��ȣ ���
	cout << "\t";
	for (int i = 0; i < 6; i++)		cout << i + 1 << '\t';
	char s = 'A';
	for (int i = 0; i < SEAT_COUNT; i++) {
		if (i % 6 == 0) {
			cout << "\n";
			cout << s++;
		}
		cout << '\t';
		if (ticketnum[choice][i])
			cout << seat_print[1];
		else
			cout << seat_print[0];
	}
	cout << "\n";
}

void cancel_movie() {
	int bnum;
	cout << "���� ��ȣ�� �Է� �ϼ���. : ";
	bnum = get_num();
	choice = bnum / 100  - 1 ;
	bnum %= 100;
	int seat_count = 0;
	for (int i = 0; i < SEAT_COUNT; i++)
		if (ticketnum[choice][i] == bnum) {
			cout << (char)((i / 6) + 'A') << " " << (char)(i % 6 + '1') << "  ";
			seat_count++;
			ticketnum[choice][i] = 0;
		}
	if (seat_count == 0) {
		cout<<"������ �Ǿ����� ���� ��ȣ�Դϴ�.  �ٽ� Ȯ���Ͽ� �ֽʽÿ�.\n ";
		return;
	}
	cout << "������ �¼� " << seat_count << " �� ��� �Ǿ����ϴ�." << endl;
	moviebookcount[choice] -= seat_count;
}

void check_movie() {
	int bnum;
	cout << "���� ��ȣ�� �Է� �ϼ���. : ";
	bnum = get_num();
	choice = bnum / 100 - 1;
	bnum %= 100;
	int seat_count = 0;
	print_seat();
	cout << "����� �¼� : ";
	for (int i = 0; i < SEAT_COUNT; i++)
		if (ticketnum[choice][i] == bnum) {
			cout << (char)((i / 6) + 'A') << " " << (char)(i % 6 + '1') << "  ";
			seat_count++;

		}
	if (!seat_count)
		cout << "����� ��ȣ�� �ƴմϴ�. \n";
}