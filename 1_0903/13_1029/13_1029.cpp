// 13_1029.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
using namespace std;
#include "CLinkedList.h"
#include "Queue.h"
#include "CStack.h"
int main()
{
	cout << "7조"<<endl;
	/*CLinkedList cl;
	cl.insertsort(70);
	cl.insertsort(20);
	cl.insertsort(20);
	cl.insertsort(80);
	cl.insertsort(20);
	cl.insertsort(30);
	cl.showList();
	cl.delete_key1(20);
	cl.delete_key1(20);
	cl.delete_key1(70);
	cl.showList();
	cl.insert3(100);
	cl.insert1(1000);
	cl.showList();

	CNode* node = cl.findNode(20); 
	if (node != cl.gettail()) {
		cout << "데이터를 찾았습니다 : "<<node->getkey() << endl;
	}
	else { cout << "해당 데이터 존재하지 않음" << endl; }*/

	Queue qu;
	CStack st;
	bool suc;
	int n;
	n=st.pop(suc);
	if (suc) cout << n<<endl;
	n = qu.pop(suc);
	if (suc) cout << n << endl;
	st.showlist();
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	n = st.pop(suc);
	if (suc) cout << n << endl;
	n = st.pop(suc);
	if (suc) cout << n << endl;
	n = st.pop(suc);
	if (suc) cout << n << endl;
	n = st.pop(suc);
	if (suc) cout << n << endl;
	n = st.pop(suc);
	if (suc) cout << n << endl;
	st.showlist();

	qu.showlist();
	qu.push(10);
	qu.push(20);
	qu.push(30);
	qu.push(40);
	n = qu.pop(suc);
	if (suc) cout << n << endl;
	n = qu.pop(suc);
	if (suc) cout << n << endl;
	n = qu.pop(suc);
	if (suc) cout << n << endl;
	n = qu.pop(suc);
	if (suc) cout << n << endl;
	n = qu.pop(suc);
	if (suc) cout << n << endl;
	qu.showlist();
	
}

