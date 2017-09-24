#include "mCalc.h"
#include <math.h> 
calculatorOperation::calculatorOperation(int parametersNumber)
{
	_allowedOperations = vector<string>();
	_parametersNumer = parametersNumber;
}
double op_Add::calcResult(double currVal, vector<string> parameters)
{
	return currVal += atof(parameters[0].c_str());
}
op_Add::op_Add():calculatorOperation(1)
{
	_allowedOperations.push_back("+");
	_allowedOperations.push_back("add");
}
double op_Sqrt::calcResult(double currVal, vector<string> parameters)
{
	return currVal = sqrt(currVal);
}
op_Sqrt::op_Sqrt() :calculatorOperation(0)
{
	_allowedOperations.push_back("Sqrt");
	_allowedOperations.push_back("sqrt");
}