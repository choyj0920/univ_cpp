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

const int SEAT_COUNT = 36;  //한 영화당 전체 좌석수 상수 설정
int ticketnum[3][SEAT_COUNT] = { 0, };  //예약된 자리 예매번호로 표현, 0일경우 예약x
int moviebookcount[3] = { 0,0,0 };	//영화별 예약된 좌석 갯수
int ticket_count[3] = { 1,1,1 }; //예약된 횟수(좌석수x)
string movienames[3] = { "엑시트     ", "힘내라 미스터리", " 나쁜 녀석들  " };  //영화 이름 출력을 위한 스트링배열
string seat_print[] = { "□", "■" };  //좌석 출력 할때 (예약되지않은좌석 ,예약 된 좌석)

int choice;  //지금 고른 영화 

int main()
{
	int menu = 0;
	//매진 출력을 위해 2번 영화는 예약번호 201로 좌석 36개가 예약되었다고 가정
	for (int i = 0; i < SEAT_COUNT; i++) {	
		moviebookcount[1]++;
		ticketnum[1][i] = 1;
	}
	ticket_count[1] = 2;

	while (menu != 4) {
		menu = 0;	
		while (menu > 4 || menu < 1) {
			system("cls");
			cout << "======== 201810754 조윤직 ==========" << endl;
			cout << "1) 영화 예매   2) 예매취소   3) 예매확인   4) 종료" << endl;
			cout << "메뉴를 선택하세요 : ";
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

void book_movie() {
	cout << "========영화 예매========\n";
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << ")   " <<setw(16)<<movienames[i] << "\t";
		if (moviebookcount[i] < SEAT_COUNT)
			cout << moviebookcount[i] << " / " << SEAT_COUNT << endl;
		else
			cout << "매진\n";
	}
	do { //예매 할 영화 선택
		cout << "예매할 영화를 선택 하세요 : ";
		choice = get_num() - 1;
	} while (choice < 0 || choice >2);  //3개중에 선택할 때 까지 
	if (moviebookcount[choice] == SEAT_COUNT) {
		cout << "죄송합니다 . 그 영화는 매진 입니다. \n";
		return ;
	}
	cout << "예매할 좌석 개수를 입력하세요(1~36) : ";
	int seat_count = get_num();
	int booknum = moviebookcount[choice] +1 ;
	for (int i = 0; i < seat_count;) {
		print_seat();

		cout <<i+1<<"번째 " <<"좌석을 정하세요 (예  A 3, 0 0 입력시 종료) : ";
		char x, y;
		cin >> y >> x;
		//종료 코드
		if (x == '0' && y == '0') {
			cout << "종료..\n";
			seat_count = i ;
			break;
		}
		//입력 범위 체크
		if (y < 'A' || y > 'F' || x<'1' || x>'6') {
			cout << "잘못 입력하셨습니다. 제대로 된 값을 입력해 주세요.\n ";
			continue;
		}
		//예약 할수 있을경우
		if (ticketnum[choice][(y - 'A') * 6 + (x - '1')] == 0) {
			ticketnum[choice][(y - 'A') * 6 + (x - '1')] = ticket_count[choice];
			moviebookcount[choice]++;
			i++;
			cout << "예약 완료\n";
		}
	}
	cout << "예약한 좌석 " << seat_count << " 개" << endl;
	for (int i = 0; i < SEAT_COUNT; i++) 
		if (ticketnum[choice][i] == ticket_count[choice])
			cout << (char)((i / 6) + 'A') << " " << (char)(i % 6 + '1')<<"  ";
	if (seat_count == 0) {
		cout << "에약한 좌석 없음. 예약 되지않습니다.\n";
	}
	else {
		cout << "예약 번호는 " << (choice + 1) * 100 + ticket_count[choice] << "입니다. \n";
		ticket_count[choice]++;

	}
	
	
}

void print_seat() {
	system("cls");
	cout << "선택한 영화 : " << movienames[choice] << endl << "=========좌석 =========\n";
	//좌석 맨 윗줄  기호 출력
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
	cout << "예약 번호를 입력 하세요. : ";
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
		cout<<"예약이 되어있지 않은 번호입니다.  다시 확인하여 주십시오.\n ";
		return;
	}
	cout << "예약한 좌석 " << seat_count << " 개 취소 되었습니다." << endl;
	moviebookcount[choice] -= seat_count;
}

void check_movie() {
	int bnum;
	cout << "예약 번호를 입력 하세요. : ";
	bnum = get_num();
	choice = bnum / 100 - 1;
	bnum %= 100;
	int seat_count = 0;
	print_seat();
	cout << "예약된 좌석 : ";
	for (int i = 0; i < SEAT_COUNT; i++)
		if (ticketnum[choice][i] == bnum) {
			cout << (char)((i / 6) + 'A') << " " << (char)(i % 6 + '1') << "  ";
			seat_count++;

		}
	if (!seat_count)
		cout << "예약된 번호가 아닙니다. \n";
}