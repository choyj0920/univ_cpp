#include "test.h"
int main() {
	cout << "201810754	조윤직" << endl;
	//A::showName();
	//B::showName();
	int start_num, final_num;
	cout << "구구단의 출력을 원하는 범위를 입력하세요(시작 끝) : ";
	cin >> start_num >> final_num;
	if (start_num > final_num) {
		cout << "두 번째 입력 숫자가 더 크므로 시작과 끝을 바꿔서 출력 할까요(y/n)?";
		char ans;
		cin >> ans;
		if (ans == 'y') {
			int temp = start_num;
			start_num = final_num;
			final_num = temp;
		}
		else return 0;
		
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = start_num; j <= final_num; j++) {
			cout << j <<" * "<<i<<" = " << setw(3)<<i * j<<"\t";
		}
		cout << endl;
	}

	return 0;

}