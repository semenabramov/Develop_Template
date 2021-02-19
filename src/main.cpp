#include <iostream>
#include "roman.h"

using namespace std;

int main() {
	
	Convertor conv;
	roman rom;
	int ar;
	string s = "II";

	//Sample 1:
	cin >> s;

	conv.set_roman(roman(s));
	conv.toArabic();
	conv.print();

	//Sample 2:
	cin >> ar;

	conv.set_arabic(arabic(ar));
	conv.toRoman();
	conv.print();

	return 0;
}