#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void lab01() {
	srand((unsigned)time(NULL));
	string items[4] = { "□"," @"," ♧"," ♤" };
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
		cout << "학급 " << i << "의 평균 성적 = " << sum[i] << endl;
	}
	sum[3] /= 3;
	cout << "전체 학생들의 평균 성적 = " << sum[3] << endl;


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
				cout << (seats[i][j] ? "●" : "O" )<< '\t';
			}
			cout << endl;
		}
		if (rScount > 24) {
			cout << "전좌석 예약 완료" << endl;
			break;
		}
		cout << "예약할 좌석을 입력하세요 : (예 ==> A 1/ 종료시 0 0) : ";
		char x ,y;
		cin >> y >> x;
		//종료 코드
		if (x == '0' && y == '0') {
			cout << "종료..\n";
			break;
		}
		//입력 범위 체크
		if (y < 'A' || y > 'F' || x<'1' || x>'4') {
			cout << "잘못 입력하셨습니다. 제대로 된 값을 입력해 주세요.\n ";
			system("pause");
			system("cls");
			continue;
		}
		//예약 할수 있을경우
		if (seats[y - 'A'][x - '1'] ==0) {
			seats[y - 'A'][x - '1'] = 1;
			rScount++;
			cout << "예약 완료\n";
		}
		// 예약 불가일 때
		else
			cout << "이미 예약이 된 자리 입니다. 예약 불가\n";

		

		system("pause");
		system("cls");
	}
}

int main() {
	cout << "201810754 조윤직\n";
	lab03();
}