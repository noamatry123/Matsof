#include "parr.h"
#include <string>
using namespace std;
//Seif 56 - are we supposed to overload iterator arithmetics?
//because im pretty sure smart pointers and shared pointers are only available on cpp11
void main()
{
	parr<int> protected_array;
	protected_array.push_back(3);
	cout << protected_array[0] << endl;
	parr<string> string_array;
	string_array.push_back("sup");
	cout << string_array[0] << endl;
	string_array[0] = "!!!";
	cout << string_array[0] << endl;
	getchar();
}