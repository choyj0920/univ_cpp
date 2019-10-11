#pragma once
using namespace std;
class lamp;
class User
{
private:
	string name;
	int want_illum;
public:
	User();
	void turnOnOff(Lamp& lamp);
	void init(const string& name, const int);
	void changeLight(Lamp& lamp);
	int iwantill() const;

	~User();
};

