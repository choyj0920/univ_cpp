#include "Lamp.h"
class User;
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
		cout << "¹à±â : " << illuminate << endl;
	}
	else {
		cout << "Àü¿øÀÌ ²¨Á® ÀÖÀ½" << endl;
	}
}

void Lamp::setlamp(User use)
{
	if (isOn) {
		while (illuminate != use.iwantill()) {
			changeLight();
		}
	}
}


Lamp::~Lamp()
{
}
