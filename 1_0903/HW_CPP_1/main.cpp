#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

string id[] = { "greenjoa","Greenjoa","GREENJOA" };
string password[] = { "1234","1111","2222" };
void lab01() {
	string user_id, pass;
	cout << "아이디 : ";
	cin >> user_id;
	cout << "비밀번호 : ";
	cin >> pass;

	for (int i = 0; i < 3; i++) {
		if (user_id.compare(id[i]) == 0) {
			if (password[i].compare(pass) == 0) {
				cout << "로그인 성공!\n";
				break;
			}
		}
	}
}

int main() {
	cout << "201810754 조윤직\n";
	lab01();
}

