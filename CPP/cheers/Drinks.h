#include <iostream>
#include <string>
using namespace std;
#define SHELF_SIZE 100
class Drink
{
	protected:
		string _name;
	public:
		string virtual getName();
		string virtual prepare() = 0;
		Drink(string name);
};
class Beer : public Drink
{
	public:
		string virtual prepare();
		Beer(string name) :Drink(name) {};
};
class Wine : public Drink
{
	public:
		string virtual getName();
		string virtual prepare()=0;
		Wine(string name, int year) :Drink(name) { _year = year; };
	private:
		int _year;
};
class WhiteWine : public Wine
{
public:
	string virtual prepare();
	WhiteWine(string name, int year) :Wine(name, year) {};
};
class RedWine : public Wine
{
public:
	string virtual prepare();
	RedWine(string name, int year) :Wine(name, year) {};
};
class Bar
{
	private:
		Drink* _stock[SHELF_SIZE];
		Drink* _lastOrdered;
	public:
		Bar();
		void DisplayMenu();
		void HowDidYouPrepare();
		void BuyDrink(int index);

};