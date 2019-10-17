#include <iostream>
#include <string>
#include "ArrayData.h"
using namespace std;

void showArray(ArrayData arr) { //여기서도 복사 생성자
	arr.showData();
}
double getArraySum(const ArrayData& arr) {
	double total = 0;
	for (int i = 0; i < arr.getUsed(); i++) {
		total += arr.data[i];
	}
	return total;
}

int main()
{
	//cout << "201810754 조윤직\n";
	//ArrayData arr1(3);
	//arr1.addElement(1.1);
	//arr1.addElement(3.1);

	//ArrayData arr2 = arr1.getObject();
	//ArrayData arr3 = ArrayData(10);

	/*ArrayData arr[] = { 
		ArrayData(10),ArrayData(20),ArrayData(30) 
	};*/
	ArrayData arr(10);
	ArrayData arr2 = ArrayData::getCopyInstance(arr);
	system("pause");


}
