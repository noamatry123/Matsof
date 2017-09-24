#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class calculatorOperation
{
protected:
	vector<string> _allowedOperations;
	int _parametersNumer;
public:
	bool supportsOperation(string op_string) {
		if (std::find(_allowedOperations.begin(), _allowedOperations.end(), op_string) != _allowedOperations.end())
			return true;
		return false;
	}
	int requiredParameters() { return _parametersNumer; };
	virtual double calcResult(double currVal, vector<string> parameters)=0;
	calculatorOperation(int parametersNumber);
};
class op_Add : public calculatorOperation {
public :
	virtual double calcResult(double currVal, vector<string> parameters);
	op_Add();
};
class op_Sqrt : public calculatorOperation {
public:
	virtual double calcResult(double currVal, vector<string> parameters);
	op_Sqrt();
};