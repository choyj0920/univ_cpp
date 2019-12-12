#include "Çì´õ.h"

VendingMachine::~VendingMachine()
{
	for (int i = 0; i < count; i++) {
		if(items[i] != NULL)
			delete items[i];
		items[i] = NULL;
	}
	delete[] items;
	items = NULL;
}

VendingMachine::VendingMachine() :VendingMachine("NaN", 5)
{
}

void VendingMachine::additem(Item* item)
{
	if (num <= count)
		return;
	items[count++] = item;

}

void VendingMachine::operator=(const VendingMachine& copy)
{
	for (int i = 0; i < count; i++) {
		if (items[i] != NULL)
			delete items[i];
		items[i] = NULL;
	}

	if (num != copy.num) {
		delete[]items;
		num = copy.num;
		items = new Item * [copy.num];
	}
	number = copy.number;
	count = copy.count;

	for (int i = 0; i < count; i++) {
		if (typeid(*copy.items[i]).name() == typeid(Coffee).name()) {
			items[i] = new Coffee(*(Coffee*)copy.items[i]);
		}
		else if (typeid(*copy.items[i]).name() == typeid(CannedDrinks).name()) {
			items[i] = new CannedDrinks(*(CannedDrinks*)copy.items[i]);
		}
	}

	return;
}
