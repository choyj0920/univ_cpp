#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
void lab01(){
	cout << "첫 번째 실습\n	";
	stringstream ss;
	int sum = 0;
	string name;
	string str;
	cout << "Enter your data(name kor eng math) : ";
	getline(cin, str);
	ss.str(str);
	ss >> name;
	for (int i = 0; i < 3; i++) {
		int temp;
		ss >> temp;
		sum += temp;
	}
	cout << name << " : " << sum;
}
void lab02() {
	int menu = 0, ameri_count = 0, cafel_count = 0;
	const int ameri_value = 100;
	const int cafel_value = 100;
	while (menu != 4) {
		menu = 0;
		cout << "1) 아메리카노(100원)\t2)카페라뗴(200원)\t3)결제\t4)종료\n" << "선택하세요 : ";
		if (!(cin >> menu)) {
			cout << "제대로 입력하세요" << endl;
			break;
		}
		
		switch (menu)
		{
		case 1:
			cout << "아메리카노를 주문하셨습니다.\n";
			ameri_count++;
			break;
		case 2:
			cout << "카페 라뗴를 주문 하셨습니다.\n";
			cafel_count++;
			break;
		case 3:
			int sum_value = 0;
			cout << "===========================\n";
			cout << "\t결제 금액\n";
			cout << "===========================\n";
			cout << "아메리카노	" << ameri_count << "잔 " << (sum_value += ameri_count * ameri_value,sum_value) << "원\n";
			cout << "카페라떼	" << cafel_count << "잔 " << (sum_value += cafel_count * cafel_value, cafel_value * cafel_count) << "원\n";
			cout << "===========================\n";

			cout << "총 " << sum_value << "원\n";
			cout << "===========================\n";
			cout << endl << "결제가 완료 되었습니다.\n";
			cafel_count =ameri_count = 0;
			break;
		}
		
		
	}
}
int main()
{
	cout << "201810754 조윤직\n";
	lab02();
}
