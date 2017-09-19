#include "reDec.h"
repeatingDecimal::repeatingDecimal(float number)
{
	_numerator = number * 1000000;
	_decimator = 1000000;
}
repeatingDecimal::repeatingDecimal(int numerator, int decimator)
{
	_numerator = numerator;
	_decimator = decimator;
}
int repeatingDecimal::getNumerator() const
{
	return _numerator;
}
int repeatingDecimal::getDecimator() const
{
	return _decimator;
}
repeatingDecimal repeatingDecimal::operator+(const repeatingDecimal &other)
{
	int newNume = (_numerator*other.getDecimator()) + (_decimator*other.getNumerator());
	int newDeci = _decimator*other.getDecimator();
	return repeatingDecimal(newNume, newDeci);
}
repeatingDecimal repeatingDecimal::operator-(const repeatingDecimal &other)
{
	int newNume = (_numerator*other.getDecimator()) + (_decimator*(other.getNumerator()*-1));
	int newDeci = _decimator*other.getDecimator();
	return repeatingDecimal(newNume, newDeci);
}
repeatingDecimal repeatingDecimal::operator*(const repeatingDecimal &other)
{
	int newNume = _numerator*other.getNumerator();
	int newDeci = _decimator*other.getDecimator();
	return repeatingDecimal(newNume, newDeci);
}
repeatingDecimal repeatingDecimal::operator*(const int &other)
{
	int newNume = _numerator*other;
	int newDeci = _decimator;
	return repeatingDecimal(newNume, newDeci);
}
ostream& operator<<(ostream& os, const repeatingDecimal &rd)
{
	os << rd.getNumerator() << "/" << rd.getDecimator();
	return os;
}
void repeatingDecimal::operator+=(const repeatingDecimal &other)
{
	_numerator = (_numerator*other.getDecimator()) + (_decimator*other.getNumerator());
	_decimator = _decimator*other.getDecimator();
}
repeatingDecimal::operator float() const
{
	return float(_numerator) / float(_decimator);
}