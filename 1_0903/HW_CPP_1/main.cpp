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
	cout << "���̵� : ";
	cin >> user_id;
	cout << "��й�ȣ : ";
	cin >> pass;

	for (int i = 0; i < 3; i++) {
		if (user_id.compare(id[i]) == 0) {
			if (password[i].compare(pass) == 0) {
				cout << "�α��� ����!\n";
				break;
			}
		}
	}
}

int main() {
	cout << "201810754 ������\n";
	lab01();
}

