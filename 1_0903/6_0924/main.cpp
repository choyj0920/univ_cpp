#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void lab01(){
	const int SIZE = 10;
	int arr[SIZE] = { 1,5,6,2,9,3,4,8,10,7 };
	int *parr[SIZE];
	for (int i = 0; i < SIZE; i++) {
		parr[i] = &arr[i];
	}
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if ((*parr[i]) > (*parr[j])) {
				int *temp = parr[j];
				parr[j] = parr[i];
				parr[i] = temp;
			}
		}
	}
	cout << "원본 데이터 : ";
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << "정렬 데이터 : ";
	for (int i = 0; i < SIZE; i++)
		cout << *parr[i] << " ";
	cout << endl;

	cout << "원본 데이터 : ";
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << " ";
	cout << endl;

}
void swap(int &a,int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void lab02(){
	int a = 10;
	int b = 20;
	cout << a << ", " << b << endl;
	cout << "포인터swap함수 실행\n";
	swap(&a, &b);
	cout << a << ", " << b << endl;
	cout << "참조 swap함수 실행\n";
	swap(a, b);
	cout << a << ", " << b << endl;
}

void printArr(int  num[], int size) {
	for (int i = 0; i < size; i++) {
		cout << num[i] << endl;
	}
}
void printArr(int  (&num)[5]) {
	for (int i = 0; i < 5; i++) {
		cout << num[i] << endl;
	}
}
void printArr(int * num, int size) {
	for (int i = 0; i < size; i++) {
		cout << num[i] << endl;
	}
}

void lab03(){
	int num[5] =  {1, 2, 3, 4, 5};
	printArr(num);
}

int main() {
	cout << "201810754 조윤직\n";
	lab02();


	system("pause");
	return 0;
}