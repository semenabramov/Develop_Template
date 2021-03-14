#include <iostream>
#include <polinoms.h>
#include <List.h>


using namespace std;

int main() {
	



	monom a(1, 2,3,4);
	monom b(5, 2,3,5);
	bool f = (a < b);

	a.print();
	//a = a * b;

	b.print();
	cout << b;
	cout << "------------------------------"<<endl;


	polynom po1;
	po1 += a;
	po1.print();
	po1 += b;
	po1.print();

	cout << po1;


	



	return 0;
}