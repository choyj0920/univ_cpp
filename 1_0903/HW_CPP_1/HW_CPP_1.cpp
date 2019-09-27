#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <Windows.h>
using namespace std;

void _HW01();
void _HW02();
void _HW03();
int get_num();



int main()
{
	int menu = 0;
	while (menu != 4) {

		menu = 0;
		while (menu > 4 || menu < 1) {
			system("cls");
			cout << "======== 201810754 조윤직 ==========" << endl;
			cout << "1) 과제1   2) 과제2   3) 과제3   4) 종료" << endl;
			cout << "메뉴를 선택하세요 : ";
			menu = get_num();
		
		}

		switch (menu)
		{
		case 1:
			_HW01();
			break;
		case 2:
			_HW02();
			break;
		case 3:
			_HW03();
			break;
		case 4:
			break;

		}

	}
}

//정수만을 받기 위한 함수 정수가 아닌 값을 받으면 다시 입력 받게
int get_num() {
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

void _HW01() {
	int money = 500;
	int buy_v;
	cout << "====== 과제 1 ========" << endl;
	do {
		cout << "구매 금액을 입력하세요[0~500] : ";
		buy_v = get_num();
	} while (buy_v > 500 || buy_v < 0);
	money -= buy_v;
	cout << money << "의 거스름돈은 다음과 같다.\n";
	int cou_100, cou_50, cou_10, cou_1;
	cou_100 = money / 100;
	cou_50 = (money % 100) / 50;
	cou_10 = (money % 50) / 10;
	cou_1 = money % 10;
	cout << "100원 짜리 동전 : " << cou_100 << "개\n";
	cout << "  50원 짜리 동전 : " << cou_50 << "개\n";
	cout << "  10원 짜리 동전 : " << cou_10 << "개\n";
	cout << "    1원 짜리 동전 : " << cou_1 << "개\n";
	system("pause");
}

void _HW02() {
	
	int money, choco = 0, coupon = 0;
	cout << "====== 과제 2 ========" << endl;
	do {
		cout << "* 돈을 넣어 주세요 : ";
		money = get_num();
	} while (money < 0);
	cout << "================== \n";
	choco += money;
	coupon += choco;
	do {
		int temp = coupon / 7;
		choco += temp;
		coupon = coupon % 7;
		coupon += temp;

	} while (coupon >= 7);
	
	cout << "* 초콜릿 " << choco << "개, 쿠폰 " << coupon << "개\n\n";
	system("pause");


}


void _HW03() {
	cout << "====== 과제 3 ========" << endl;
	int count = 0;
	int T, O, G, D;
	cout << "TOO + TOO + TOO + TOO = GOOD\n";
	cout << "식: (T * 100 + O * 11) * 4 = G * 1000 + O * 110 + D\n";
	for (T = 0; T < 10; T++) {
		for (O = 0; O < 10; O++) {
			if (T == O)
				continue;
			for (G = 0; G < 10; G++) {
				if (T == G || G == O)
					continue;
				for (D = 0; D < 10; D += 2) {
					if (D == T || D == O || T == G)
						continue;
					else if (T * 100 * 4 == (G * 1000 + O * 66 + D)) {
						count++;
						cout <<"경우 "<<count<< " : T = " << T << ", O = " << O << ", G = " << G << ", D = " << D << endl;
					}
				}
			}
		}
	}
	system("pause");

}

