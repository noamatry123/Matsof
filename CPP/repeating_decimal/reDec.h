#include <iostream>
using namespace std;
class repeatingDecimal
{
	private:
		int _numerator;
		int _decimator;
	public:
		repeatingDecimal(int numerator, int decimator);
		repeatingDecimal(float number);
		repeatingDecimal operator+(const repeatingDecimal &other);
		repeatingDecimal operator*(const repeatingDecimal &other);
		repeatingDecimal operator*(const int &other);
		repeatingDecimal operator-(const repeatingDecimal &other);
		void operator+=(const repeatingDecimal &other);
		friend ostream& operator<<(ostream& os, const repeatingDecimal &rd);
		operator float() const;
		int getNumerator() const;
		int getDecimator() const;
};