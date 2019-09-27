#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

namespace A {
	void showName() {

		cout << "A::showname 실행 !!\n";
		cout << "홍길동" << endl;
	}
}
namespace B {
	void showName() {
		cout << "B::showname 실행 !!\n";
		cout << "고길동" << endl;
	}
}