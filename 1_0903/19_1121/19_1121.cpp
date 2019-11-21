#include <iostream>
#include <map>
#include  <algorithm>
#include "Point.h"
#include "Stack.h"
using namespace std;
template<typename T>
void printArr(T data,const int& size) {
	cout << "템플릿함수\n";
	for (int i = 0; i < size; i++) {
		cout << data[i] << endl;
	}
}
template<>
void printArr(char* data, const int& size) {
	cout << "전문화함수\n";

	cout << data;
}

void printArr(char* data, const int& size) { //일반함수가 항상 우선
	cout << "일반함수\n";

	cout << data;
}
template<typename T>
void sortAsc(T* data, const int& size) {
	for (int i = 0; i < size;  i++) {
		for (int j = i + 1; j < size; j++) {
			if (data[i] > data[j]) {
				T temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
		}
	}
	cout << "정렬 완료\n";
}
template<typename T>
void sortDesc(T* data, const int& size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (data[i] < data[j]) {
				T temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
		}
	}
	cout << "정렬 완료\n";
}
ostream& operator<<(ostream& out, Point& pt) {
	out << pt.getX() << ", " << pt.getY();
	return out;
}
int main()
{
	cout << "7조 박진영 양석준 송재원 조윤직\n";

	//map<int, string> map;
	//map.insert(pair<int, string>(20, "adff"));
	//
	//int arr1[5] = {20,51,2,100,5};
	//char arr2[5] = "abc";
	//printArr(arr1, 5);
	//sort(&arr1[0], &arr1[4]);
	//printArr(arr1, 5);
	//sortAsc(arr1, 5);
	//printArr(arr1, 5);
	//
	//printArr(arr2, 5);
	/*
	Point pt[5] = { Point(10,50),Point(60,74) ,Point(100,69) ,Point(90,50),Point(120,40) };

	printArr(pt, 5);
	sortAsc(pt, 5);
	printArr(pt, 5);
	sortDesc(pt, 5);
	printArr(pt, 5);
	*/

	Stack<int,20> stack;
	stack.push(21);
	stack.push(22);
	stack.push(23);
	stack.push(24);
	stack.push(224);
	stack.push(224);
	stack.push(224);
	stack.push(224);
	stack.push(124);
	stack.push(124);
	stack.push(124);
	stack.push(124);

	int data;
	while (stack.pop(data)) {
		cout << data << endl;
	}

	Stack<> stack2;
	stack2.push("greenjoa1");
	stack2.push("greenjoa2");
	stack2.push("greenjoa3");
	stack2.push("greenjoa4");

	string data2;
	while (stack2.pop(data2)) {
		cout << data2 << endl;
	}
	Stack<Point> stack3;
	stack3.push(Point(20,40));
	stack3.push(Point(400,20));
	stack3.push(Point(15,34));
	stack3.push(Point(90,66));
	stack3.push(Point(85,124));
	

	Point data3;
	while (stack3.pop(data3)) {
		cout << data3 << endl;
	}
}

