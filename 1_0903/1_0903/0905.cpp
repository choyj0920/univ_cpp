#include "test.h"
int main() {
	cout << "201810754	������" << endl;
	//A::showName();
	//B::showName();
	int start_num, final_num;
	cout << "�������� ����� ���ϴ� ������ �Է��ϼ���(���� ��) : ";
	cin >> start_num >> final_num;
	if (start_num > final_num) {
		cout << "�� ��° �Է� ���ڰ� �� ũ�Ƿ� ���۰� ���� �ٲ㼭 ��� �ұ��(y/n)?";
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