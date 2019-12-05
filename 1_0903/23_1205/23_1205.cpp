#include <iostream>
using namespace std;
#include <stack>
#include <sstream>
int main() {

	stack<int> num_stack;
	string formula = "";
	getline(cin, formula);
	stringstream cstr(formula);
	string ss;
	while (cstr >> ss) {	
		if (atoi(ss.c_str()) || !ss.compare("0")) {
			int n = atoi(ss.c_str());
			num_stack.push(n);
		}
		else {
			int b = num_stack.top(); num_stack.pop();
			int a = num_stack.top(); num_stack.pop();
			if (!ss.compare("+"))
				num_stack.push(a + b);
			else if(!ss.compare("-"))
				num_stack.push(a - b);
			else if (!ss.compare("*"))
				num_stack.push(a * b);
			else if (!ss.compare("/"))
				num_stack.push(a / b);
			cout << a << " " << ss << " " << b
				<< " = " << num_stack.top() << "\n";
		}
	}
	cout <<formula<<" = "<<num_stack.top() << endl;
}