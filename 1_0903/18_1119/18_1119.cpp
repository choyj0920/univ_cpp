#include <iostream>
#include "ArrayDataBak.h"
using namespace std;

ostream& operator<<(ostream& out, ArrayDataBak& data) {
	data.showData();
	return out;
}
int main()
{
	cout << "7조 박진영 양석준 송재원 조윤직\n";
	/*
	ArrayData arr;
	arr.addElement(10.1);
	arr.addElement(10.3);
	arr.addElement(10.4);
	arr.addElement(11.4);

	for (int i = 0; i < arr.getUsed(); i++) {
		cout << arr[i] << endl;
	}
	*/


	ArrayDataBak arr(5);
	arr.addElement(10.2);
	arr.addElement(4.2);
	arr.addElement(12.2);
	arr.addElement(11.2);

	cout << arr;
	arr.backup();
	arr.emptyArray();
	arr.showData();
	arr.restore();
	arr.showData();

	cout << "========백업 확인======\n";
	ArrayDataBak arr2(10);
	arr2.addElement(10);
	arr2.addElement(10);
	arr2.addElement(10);
	arr2.showData();
	arr2.emptyArray();
	arr2.restore();
	arr2.showData();

	cout << "========이동 생성자======\n";
	ArrayDataBak arr3 = ArrayDataBak::getCopyInstance(arr2);

	cout << "========대입 연산자======\n";
	ArrayDataBak arr4;
	arr4 = arr2;
	cout << arr4;

	cout << "========이동 대입 연산자======\n";
	arr4 = ArrayDataBak::getCopyInstance(arr);
	cout << arr4;
	cout << "프로그램 종료\n";
	


}
