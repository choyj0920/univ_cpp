#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

namespace A {
	void showName() {

		cout << "A::showname ���� !!\n";
		cout << "ȫ�浿" << endl;
	}
}
namespace B {
	void showName() {
		cout << "B::showname ���� !!\n";
		cout << "��浿" << endl;
	}
}