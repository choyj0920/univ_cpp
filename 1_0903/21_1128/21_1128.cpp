#include "Student.h"
#include "ArrayData.h"
#include "TArrayDataBak.h"
#include <vector>
using namespace std;


ostream& operator<<(ostream& out, Student& copy) {
	out << "이름 : " << copy.name << ", 성적 : " << copy.score;
	return out;
}
//studen* 출력 함수
ostream& operator<<(ostream& out,const  Student* copy) {
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
	
	/*
	//실습2 -vector 출력 템플릿함수-iterator 사용
	vector<int > intarr;
	intarr.push_back(10);
	intarr.push_back(20);
	intarr.push_back(30);
	intarr.push_back(40);
	intarr.push_back(50);
	intarr.push_back(60);
	printArr(intarr);
	vector<double> doublearr;
	doublearr.push_back(10.1);
	doublearr.push_back(10.2);
	doublearr.push_back(10.3);
	doublearr.push_back(10.4);
	printArr(doublearr);
	*/


	//실습 3 -stdarr 동적할당 해제, 원소 삭제함수
	vector<Student*> stdarr;
	stdarr.push_back(new Student("greanjoa1", 20));
	stdarr.push_back(new Student("greanjoa2", 20));
	stdarr.push_back(new Student("greanjoa3", 20));
	stdarr.push_back(new Student("greanjoa4", 20));
	stdarr.push_back(new Student("greanjoa5", 20));
	printArr(stdarr);
	//
	deleteVectorele(stdarr);
	
	printArr(stdarr);

}
