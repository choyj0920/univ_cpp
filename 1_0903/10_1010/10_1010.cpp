#include "pch.h"
#include "Rectangle.h"
#include "Player.h"

void test01() {
	MyPoint pt1;
	MyPoint pt2(10);
	MyPoint pt3(10, 20);
	MyPoint* pp = new MyPoint;
	MyPoint* pp2 = new MyPoint();
	pt1.show();
	pt2.show();
	pt3.show();
	pp->show();
	pp2->show();
}
void test02() {
	Rectangle rt1(100, 100, 200, 200);
	rt1.show();
}
void test03() {
	Rectangle * pret = new Rectangle(100, 100, 200, 200);
}
void lab01() {
	Dice dice1, dice2;
	Player play1("홍길동"), play2("김길동");
	play1.roll(dice1, dice2);
	play2.roll(dice1, dice2);
	if (play1.getTotal() > play2.getTotal())
		cout << play1.getName() << "이가 승리!" << play1.getTotal() << ", " << play2.getTotal();
	else if(play1.getTotal() < play2.getTotal())
		cout << play2.getName() << "이가 승리!" << play1.getTotal() << ", " << play2.getTotal();
	else
		cout << "무승부 !" << play1.getTotal() << ", " << play2.getTotal();
	cout << endl;
	
}
void test04() {
	Dice dice1, dice2;
	//Player * player[2];
	Player** player = new Player*[2];
	player[0] = new Player("홍길동");
	player[1] = new Player("김길동");

	delete player[0];
	delete player[1];
	delete[] player;
}
int main()
{
	srand((unsigned)time(0));
	cout << "201810754 조윤직\n";

	test04();
}

