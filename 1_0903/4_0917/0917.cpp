#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void lab01() {
	const int SIZE = 5;
	int sum = 0;
	int sung[SIZE];
	for (int i = 0; i < SIZE; i++) {
		cout << "�л��� ������ �Է��Ͻÿ� :";
		cin >> sung[i];
		sum += sung[i];
	}
	cout << "���� ��� = " << sum / SIZE<<endl;
}

void lab02() {
	srand((unsigned)time(NULL));
	int num[10];
	cout << "========================" << endl;
	cout << "�ε���\t��\n";
	cout << "========================" << endl;
	for (int i = 0; i < 10; i++) {
		num[i] = rand() % 100;
		cout << i << " \t" << num[i] << endl;
	}
}
void lab03() {
	int sung[5] = { 4,12,5,20,12 };
	
	for (int i = 0; i < 5; i++) {
		cout << "��ȣ " << i << " : ";
		for (int j = 0; j < sung[i]/2; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

void lab04() {
	const int SIZE = 5;
	int min=100 ,max = 0;
	int sung[SIZE];
	for (int i = 0; i < SIZE; i++) {
		cout << "�л��� ������ �Է��Ͻÿ� :";
		cin >> sung[i];
		if (min > sung[i])
			min = sung[i];
		if (max < sung[i])
			max = sung[i];
	}
	cout << "�ִ� ���� " << max << " �ּ� ���� " << min << " �Դϴ�." << endl;
}

void lab05() {
	srand((unsigned)time(NULL));
	int num[6] = { 0, };
	for (int i = 0; i < 10000; i++) {
		int dice = rand() % 6;
		num[dice]++;
	}
	for (int i = 0; i < 6; i++) {
		cout << i + 1 << "�� ���� Ƚ�� " << num[i] << endl;
	}
}

int main() {
	cout << "201810754 ������\n";
	lab05();
	/*cout << "num :" << num << endl;
	cout << "sizeof(num) :" << sizeof(num) << endl;
	cout << "*num :" << *num << endl;
	cout << "sizeof(num[0]) :" << sizeof(num[0]) << endl;
	cout << "&num[0] :" << &num[0] << endl;
	cout << "num[0] :" << num[0] << endl;
	cout << "num[1] :" << num[1] << endl;
	cout << "&num[1] :" << &num[1] << endl;*/

	/*
	cout << "sizeof(int) :" << sizeof(int) << endl;
	cout << "sizeof(double) :" << sizeof(double) << endl;
	cout << "sizeof(char) :" << sizeof(char) << endl;
	cout << "sizeof(float) :" << sizeof(float) << endl;
	cout << "sizeof(char*) :" << sizeof(char*) << endl;
	cout << "sizeof(double*) :" << sizeof(double*) << endl;
	*/

}
