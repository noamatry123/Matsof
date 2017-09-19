#include "reDec.h"
#include <iostream>
using namespace std;
void main() // is it enough? unclear on what else to add
{
	//check constructor and print
	repeatingDecimal reDec(1, 3);
	cout << reDec << endl;
	//check float conversion
	cout << (float)reDec << endl;
	//check op+
	cout << reDec + repeatingDecimal(1, 3) << endl;
	//check op+=
	reDec += repeatingDecimal(2, 3);
	cout << reDec << endl;
	//check float conversion constructor
	reDec = repeatingDecimal(0.333333);
	cout << reDec << endl;
	cout << (float)reDec << endl;
	//check op- and op*
	reDec = repeatingDecimal(2, 3);
	cout << reDec - repeatingDecimal(1, 3) << endl;
	cout << reDec << " *3= " << reDec * 3 << endl;
	getchar();
}