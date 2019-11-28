
#include "Student.h"
#include "ArrayData.h"
#include "TArrayDataBak.h"
#include <vector>
using namespace std;

ostream& operator<<(ostream& out, Student& copy) {
	out << "이름 : " << copy.name << ", 성적 : " << copy.score;
	return out;
}
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
		//동적할당 제거, vector 원소팝
		delete v.back();
		v.pop_back();
	}
}


int main()
{

	/*TArrayDataBak<Student> std(10);

	std.addElement(Student("greenjoa1", 50));
	std.addElement(Student("greenjoa2", 20));
	std.addElement(Student("greenjoa3", 30));
	std.backup();
	std.showData();
	cout << "백업\n";
	cout << "원소 추가\n";
	std.addElement(Student("greeen", 10));
	std.showData();
	std.restore();
	std.showData();*/

	//vector<int > intarr;
	//intarr.push_back(10);
	//intarr.push_back(10);
	//intarr.push_back(10);
	//intarr.push_back(10);
	//intarr.push_back(10);
	//intarr.push_back(10);
	//printArr(intarr);
	//vector<double> doublearr;
	//doublearr.push_back(10.1);
	//doublearr.push_back(10.1);
	//doublearr.push_back(10.1);
	//doublearr.push_back(10.1);
	//printArr(doublearr);

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
