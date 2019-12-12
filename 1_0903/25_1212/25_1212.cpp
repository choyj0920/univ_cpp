#include "헤더.h"
#include<algorithm>
ostream& operator<<(ostream& out,const VendingMachine& vending) {
	for (int i = 0; i < vending.count; i++) {
		vending.items[i]->printItem();
		cout << "\n";
	}
	return out;
}
ostream& operator<<(ostream& out, const vector<VendingMachine*>& vending) {
	vector<VendingMachine*>::const_iterator it = vending.begin();
	for (; it != vending.end(); it++) {
		cout << **it << endl;
		cout << "=============================\n";
	}
	return out;

}
bool lessmachine(const VendingMachine* a, const VendingMachine* b) {
	return *a < *b;
}
int main()
{
	//1번
	cout << "201810754 조윤직\n";
	//2번
	Item* item1 = new Coffee("맥스웰", 500, 400, 400, 800, false);
	Item* item2 = new CannedDrinks("사이다", 1000, "롯데");
	//item1->printItem();
	//item2->printItem();
	delete item1;
	delete item2;

	VendingMachine vending("s100", 3);
	vending.additem(new Coffee("맥스웰", 500, 400, 400, 800, false));
	vending.additem(new CannedDrinks("사이다", 1000, "롯데"));

	VendingMachine copyVending;
	copyVending = vending;
	
	VendingManager vmanager;
	vmanager.addMachine(new VendingMachine("s200", 4));
	vmanager.addMachine(new VendingMachine("s100", 5));
	vmanager.addMachine(new VendingMachine("s300", 6));

	vmanager[0]->additem(new Coffee("맥스웰", 500, 400, 400, 800, false));
	vmanager[0]->additem(new Coffee("맥심", 500, 400, 400, 800, false));

	vmanager[1]->additem(new CannedDrinks("사이다", 1000, "롯데"));
	vmanager[1]->additem(new CannedDrinks("펩시", 1000, "롯데"));
	vmanager[1]->additem(new Coffee("맥스웰2", 500, 400, 400, 800, false));
	vmanager[1]->additem(new Coffee("맥심2", 500, 400, 400, 800, false));

	vmanager[2]->additem(new CannedDrinks("사이다", 1000, "롯데"));
	vmanager[2]->additem(new CannedDrinks("펩시", 1000, "롯데"));
	vmanager[2]->additem(new Coffee("맥스웰2", 500, 400, 400, 800, false));

	vector<VendingMachine*> arr = vmanager.getMachine();
	cout << arr << endl;
	sort(arr.begin(), arr.end(), lessmachine);
	cout << arr << endl;
}
