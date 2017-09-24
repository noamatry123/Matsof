#include <iostream>
#include "mCalc.h"
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
	double currVal = 0;
	//setting up the calculator (maybe add this to a class? depends on the requirements..)
	unordered_map<string, calculatorOperation*> instructionset;
	op_Add opadd;
	op_Sqrt opsqrt;
	instructionset["add"] = &opadd;
	instructionset["+"] = &opadd;
	instructionset["Sqrt"] = &opsqrt;
	instructionset["sqrt"] = &opsqrt;
	//actually do stuff
	string str = "";
	while (true) //break if when he types exit
	{
		cout << "current value: " << currVal << endl;
		cout << "enter command: " << endl;
		cin >> str;
		if (str == "exit")
			break;
		if (instructionset.find(str) == instructionset.end())
		{
			//throw("The command does not exist");
			cout << "The command does not exist" << endl;
			_flushall();
			continue;
		}
		//all good, calculate
		vector<string> param_vec;
		for (int i = 0; i < instructionset[str]->requiredParameters(); i++)
		{
			string param = "";
			cin >> param;
			param_vec.push_back(param);
		}
		currVal = instructionset[str]->calcResult(currVal, param_vec);
		cout << "current value: " << currVal << endl;
		str = "";
	}
	getchar();
	return 0;
}