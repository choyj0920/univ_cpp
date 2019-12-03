#include <iostream>
#include <vector>
#include "Student.h"
#include "TArrayDataBak.h"
#include <deque>
#include <list>
#include <map>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

template<typename T>class stdGreater {
public:
	bool operator()(const T& t1, const T& t2) {
		return t1.name < t2.name;
	}
};

ostream& operator<<(ostream& out, Student& copy) {
	out << "이름 : " << copy.name << ", 성적 : " << copy.score;
	return out;
}
//studen* 출력 함수
ostream& operator<<(ostream& out, const  Student* copy) {
	out << "이름 : " << copy->name << ", 성적 : " << copy->score;
	return out;
}

template<typename T3>
ostream& operator<<(ostream& out, const TArrayData<T3>& copy) {
	copy.showData();
	return out;
}

template<typename T, typename T2>
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

template<typename T4>
void printArr(const vector<T4>& v) {

	//vector를 const로 받아와서 -- const_iterator로 안하면 오류 발생 
	typename vector<T4>::const_iterator itt;
	for (itt = v.begin(); itt != v.end(); itt++) {
		cout << *itt << endl;
	}
}

//배열 동적할당 다 삭제해주는 함수
template<typename T1>
void deleteVectorele(vector<T1>& v) {
	//v가 비워질 때까지 실행
	while (!v.empty())
	{
		//동적할당 제거, vector 원소-팝
		delete v.back();
		v.pop_back();
	}
}


bool KorGreater(const Student& t1, const Student& t2) {
	return t1.score > t2.score;
}
int main()
{
	/*
		//실습 1
		TArrayDataBak<Student> std(10);

		std.addElement(Student("greenjoa1", 50));
		std.addElement(Student("greenjoa2", 20));
		std.addElement(Student("greenjoa3", 30));
		std.showData();
		cout << "백업\n";
		std.backup();

		cout << "원소 추가\n";
		std.addElement(Student("greeen", 10));
		std.showData();
		cout << "====복구====\n";

		std.restore();
		std.showData();
		*/

		
		//실습1 - 값 찾아서 지우기
		vector<int > intarr;
		vector<int > intarr2;
		intarr.push_back(10);
		intarr.push_back(20);
		intarr.push_back(30);
		intarr.push_back(40);
		intarr.push_back(50);
		intarr.push_back(60);
		//printArr(intarr);

		vector<int>::iterator it;
		it = intarr.begin();
		for (it; it != intarr.end(); it++) {
			if (*it == 50) {
				cout << "제거\n";
				intarr.erase(it);
				break;
				}
		}
		//printArr(intarr);


		intarr2.push_back(40);
		intarr2.push_back(90);
		intarr2.push_back(100);
		intarr2.push_back(120);
		intarr2.push_back(150);
		//실습 2 swap 
		/*
		printArr(intarr2);
		cout << "intarr 주소 : " << &intarr << endl;
		cout << "intarr2 주소 : " << &intarr2 << endl;
		intarr.swap(intarr2);
		cout << "intarr 주소 : " << &intarr << endl;
		cout << "intarr2 주소 : " << &intarr2 << endl;
		printArr(intarr);
		printArr(intarr2);
		*/

		//벡터와 동일하지만 앞에서부터도 들어 갈수 있는 deque
		/*
		deque<int> de;
		de.push_front(20);
		de.push_front(30);
		de.push_front(40);
		de.push_front(50);
		de.push_back(20);
		de.push_back(20);
		deque<int>::iterator it2;
		it2 = de.begin();
		for (; it2 < de.end(); it2++) {
			cout << *it2 << "\t";
		}
		cout << "\n";
		for (int i = 0; i < de.size(); i++) {
			cout << de[i] << "\t";
		}
		*/

		//List 
		/*
		list <int> arr3;
		arr3.push_back(80);
		arr3.push_back(40);
		arr3.push_back(10);
		arr3.push_back(70);
		arr3.push_back(30);
		//sort실행
		for (int i:arr3) {
			cout << i << "\t";
		}
		cout << "\n";
		arr3.sort();
		for (int i : arr3) {
			cout << i << "\t";
		}
		cout << "\n";
		greater<int> g;

		arr3.sort(g);
		for (int i : arr3) {
			cout << i << "\t";
		}
		*/
		//사용자 정의 클래스  sort 
		/*
		list<Student> stdarr;
		stdarr.push_back(Student("greanjoa1", 20));
		stdarr.push_back( Student("greanjoa2", 40));
		stdarr.push_back( Student("greanjoa3", 50));
		stdarr.push_back( Student("greanjoa4", 70));
		stdarr.push_back( Student("greanjoa5", 10));
		for (Student s : stdarr) {
			cout << s << "\n";
		}
		stdarr.sort();

		cout << "점수 정렬\n";
		for (Student s : stdarr) {//클래스의 오퍼레이터 오름차
			cout << s << "\n";
		}
		cout << "점수 정렬\n";
		stdarr.sort(greater<Student>());//클래스 의 오퍼레이터 내림차
		for (Student s : stdarr) {
			cout << s << "\n";
		}

		cout << "이름 정렬\n";
		stdarr.sort(stdGreater<Student>());//외부클래스함수
		for (Student s : stdarr) {
			cout << s << "\n";
		}
		cout << "점수 정렬\n";
		stdarr.sort(KorGreater);//외부-정의함수
		for (Student s : stdarr) {
			cout << s << "\n";
		}
		*/

		//map
		map<string, Student> stdd;
		stdd["홍길동"] = Student("홍길동", 20);
		stdd["김길동"] = Student("김길동", 20);
		stdd["진길동"] = Student("진길동", 40);
		stdd["강길동"] = Student("강길동", 30);
		stdd["이길동"] = Student("이길동", 50);
		cout << stdd["강길동"] << endl;

		// Stack
		stack<int> sta;
		sta.push(2);
		sta.push(5);
		sta.push(2);
		sta.push(1);
		while (!sta.empty()) {
			cout << sta.top() << endl;
			sta.pop();
		}
		//priority_queue

		std::priority_queue<int> intpq;
		
		intpq.push(4);
		intpq.push(1);
		intpq.push(2);
		intpq.push(4);
		intpq.push(2);
		intpq.push(8);

}
