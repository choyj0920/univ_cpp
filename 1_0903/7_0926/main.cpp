#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

//lab01
void lab01();
int checkinfo(const string (&user)[3][2], const string &user_id, const string &pass);  //출력 0 ; 아이디 없음, 출력 1 : 비밀번호 불일치, 출력 2 : 정보 일치

//lab02
int ** reamMap(const string file_name,int &row,int &col);
void lab02();
void deleteMap(int ** map, int &row);

int main() {
	cout << "201810754 조윤직\n";
	lab02();

	system("pause");
}

void lab01() {
	const int ROW = 3;
	const int COL = 2;
	string user[ROW][COL] = {
	{"greenjoa","1234"},{"Greenjoa", "1111"},{"GREENJOA","2222"}
	};
	string user_id, pass;
	cout << "아이디 : ";
	cin >> user_id;
	cout << "비밀번호 : ";
	cin >> pass;
	int n = checkinfo(user, user_id, pass);
	if (n == 2)
		cout << "로그인 완료.\n";
	else if (n == 1)
		cout << "비밀번호 불일치..로그인 실패\n";
	else
		cout << "아이디 없음..로그인 실패..\n";
}

int checkinfo(const string(&user)[3][2], const string & user_id, const string & pass)
{
	/*for (int i = 0; i < sizeof(user)/sizeof(user[0]) ; i++) {
		if (user_id.compare(user[i][0]) == 0)
			if (user[i][1].compare(pass) == 0)
				return 2;
			else
				return 1;
				
	}*/
	for (auto &us : user) {  //foreach
		if (user_id.compare(us[0])==0)
			if (pass.compare(us[1])==0)
				return 2;
			else
				return 1;
	}

	return 0;
}



void lab02() {
	int row, col;
	int **map = reamMap("testmap.txt", row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			if (map[i][j] == 0)
				cout << "○";
			else
				cout << "●";
		cout << endl;
	}
	deleteMap(map, row);
}


int ** reamMap(const string file_name, int &row, int &col) {
	ifstream fin(file_name);
	int **Map = NULL;
	if (!fin.is_open()) {
		cout << "파일 위치 확인해 주세요.\n";
		return nullptr;
	}
	else {
		fin >> row >> col;
		Map = new int*[row];
		for (int i = 0; i < row; i++) {
			Map[i] = new int[col];
			for (int j = 0; j < col; j++) 
				fin >> Map[i][j];
		}
		return Map;
	}

}
void deleteMap(int ** map, int &row) {
	if (map != NULL) { //map에 할당 되어 있을 때에만.
		for (int i = 0; i < row; i++)
			delete[] map[i];  //층별로 방 지우기
		delete[] map; //층 지우기
	}
	
	return;
}
