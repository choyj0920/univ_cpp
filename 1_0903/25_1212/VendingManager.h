#pragma once
class VendingManager
{
private:
	vector<VendingMachine*> machines;
public:
	
	void addMachine(VendingMachine* mach);
	
	VendingMachine* operator[](const int& i);

	vector<VendingMachine*>& getMachine();
};

