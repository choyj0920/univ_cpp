#include "pch.h"

Lamp::Lamp()
{
	isOn = false;
	illuminate = 1;
}

void Lamp::powerOnOff()
{
	isOn = !isOn;
	show();

}

void Lamp::changeLight()
{
	if (isOn) {
		illuminate = illuminate % 3 + 1;
	}
	show();
}

void Lamp::show()
{
	if (isOn) {
		cout << "��� : " << illuminate << endl;
	}
	else {
		cout << "������ ���� ����" << endl;
	}
}

void Lamp::setlamp(const User& use)
{
	if (isOn) {
		int  want_Value = use.iwantill();
		while (illuminate != want_Value) {
			changeLight();
		}
		cout << "�������� �Ϸ� \n";
	}
}


Lamp::~Lamp()
{
}
