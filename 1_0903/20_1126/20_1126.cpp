#include <iostream>
#include "Student.h"
#include "ArrayData.h"
using namespace std;

ostream& operator<<(ostream& out,Student& copy) {
	out << "이름 : " << copy.name << ", 성적 : " << copy.score;
	return out;
}
template<typename T3>
ostream& operator<<(ostream& out, const TArrayData<T3>& copy) {
	copy.showData();
	return out;
}

template<typename T,typename T2>
bool Search(T* arr, int sizearr, T2 find, int& index) {
	for (int i = 0; i < sizearr; i++) {
		if (arr[i] == find) {
			index = i;
			
			return true;
		}
	}
	return false;
	cout << "값  찾지 못함\n";
}


int main() {
	cout << "7조 박진영 양석준 송재원 조윤직\n";
	/*
	int arr[5] = { 5,4,3,2,1 };
	int index;
	
	if (Search(arr, 5, 3,index)) {
		cout << arr[index] << endl;
	}
	string id[3] = { "greenjoa1","greenjoa2","greenjoa3" };

	if (Search(id, 3, "greenjoa2", index)) {
		cout << id[index]<<" "<<index << endl;
	}

	Student std[3] = { Student("greenjoa1",70),Student("greenjoa2",50),Student("greenjoa3",80) };
	if (Search(std, 3, "greenjoa3", index)) {
		cout << std[index] << " " << index << endl;
	}
	
	if (Search(std, 3, Student("greenjoa3",80), index)) {
		cout << std[index] << " " << index << endl;
	}
	*/

	TArrayData<Student> std;
	std.addElement(Student("greejoa1", 10));
	std.addElement(Student("greejoa2", 20));
	std.addElement(Student("greejoa4", 40));
	std.addElement(Student("greejoa5", 50));
	cout << std << endl;
	cout << "=======복사 생성자 =============\n";
	TArrayData<Student> stdcopy = std;
	cout << stdcopy<<endl;
	cout << "=======이동 생성자 =============\n";
	TArrayData<Student> std2 = move(stdcopy);
	cout << std2 << endl;

	cout << "=======복사 연산자 =============\n";
	TArrayData<Student> stdcopy2;
	stdcopy2 = std2;
	cout << stdcopy2 << endl;

	cout << "=======이동 연산자 =============\n";
	std2 = move(std);
	cout << std2;
	

	

}
