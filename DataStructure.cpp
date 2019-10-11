#include <iostream>
#include "arrayList.h"
using namespace std;
void output();
int main()
{
	arrayList<int> list(2);
	int a = 1, b = 2,c=3;
	list.insert(0, a);
	list.insert(1, b);
	cout << list.get(1) << endl;
	cout << list.empty() << endl;
	cout << list.getSize() << endl;
	cout << list.indexof(2) << endl;
	list.insert(2,c);
	list.erase(0);
	cout << list.get(0) << "    " << list.get(1) << endl;
	return 0;
}