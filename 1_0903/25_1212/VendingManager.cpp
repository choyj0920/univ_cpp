#include "Çì´õ.h"

void VendingManager::addMachine(VendingMachine* mach)
{
	machines.push_back(mach);
}

VendingMachine* VendingManager::operator[](const int& i)
{
	vector<VendingMachine*>::iterator it = machines.begin();
	it=it + i;
	return *it;
}

vector<VendingMachine*>& VendingManager::getMachine()
{
	return machines;
}
