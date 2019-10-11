#include "pch.h"

void lab01() {
	Lamp lamp;  //일반 객체
	lamp.powerOnOff();
	lamp.changeLight();
	lamp.changeLight();
	lamp.changeLight();
	lamp.powerOnOff();
	Lamp* plamp = &lamp;//포인터 변수
	plamp->powerOnOff();
	plamp->changeLight();
	plamp->powerOnOff();
	plamp->changeLight();
	Lamp & rlamp = lamp;//참조 변수
	rlamp.powerOnOff();
	rlamp.powerOnOff();
	Lamp* pplamp = new Lamp;// 포인터 변수 ,동적 할당
	pplamp->changeLight();
	//동적할당을 했으면 꼭 할당 해제 
	delete pplamp;
}
void lab02() {
	//자바와달리 클래스 객체 배열 선언했을 때 빈방이 아닌 객체가 하나씩 다 생성됨 +기본 생성자로 ..
	Lamp lampArr[3];
	lampArr[0].powerOnOff();
	lampArr[2].powerOnOff();

	Lamp* lampArr2 = new Lamp[3];
	lampArr2[0].powerOnOff();
	lampArr2[1].powerOnOff();

	//동적할당을 했으면 꼭 할당 해제 
	delete[] lampArr2;
}
void lab03() {
	Lamp lamp1, lamp2;
	User user;
	user.init("greenjoa", 0);
	user.turnOnOff(lamp1);
	user.turnOnOff(lamp2);
	user.changeLight(lamp1);
}
void lab04() {
	User us1, us2;
	us1.init("홍길동", 2);
	us2.init("김길동", 3);
	Lamp lamp;
	us1.turnOnOff(lamp);
	lamp.setlamp(us2);
	lamp.setlamp(us1);

}
int main() {
	cout << "201810754 조윤직\n";
	lab04();


	system("pause");
	return 0;
}