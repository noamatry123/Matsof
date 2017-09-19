#include "Drinks.h"
Bar::Bar()
{
	_lastOrdered = nullptr;
	for each (Drink* d in _stock)
	{
		d = nullptr;
	}

	//now initialize inventory
	_stock[0] = new Beer("Carlsberg");
	_stock[1] = new Beer("Heiniken");
	_stock[2] = new Beer("Macabi");
	_stock[3] = new WhiteWine("Emerald riesling", 1986);
	_stock[4] = new WhiteWine("GolanSmadar", 1989);
	_stock[5] = new RedWine("Yarden Mt. Hermon", 1994);
	_stock[6] = new WhiteWine("Yarden Chardonnay", 1997);
	_stock[7] = new RedWine("Chianti", 1997);
	_stock[8] = new RedWine("Yarden Cabernet Sauvignon", 1997);
	_stock[9] = new RedWine("Chadeau Margot", 1997);

}
void Bar::HowDidYouPrepare()
{
	cout << _lastOrdered->prepare() << endl;
}
void Bar::BuyDrink(int index)
{
	_lastOrdered = _stock[index];
	cout << "You bought " << _stock[index]->getName() << endl;
}
void Bar::DisplayMenu()
{
	for (int i = 0; i < SHELF_SIZE; i++)
	{
		if (_stock[i] == nullptr)
			continue;
		cout << "(" << i << ")    " << _stock[i]->getName() << endl;
	}
}
string Drink::getName()
{
	return _name;
}
Drink::Drink(string name)
{
	_name = name;
}
string Beer::prepare()
{
	return "Well, all you need to do is pour it into a glass and serve :/";
}
string Wine::getName()
{
	return _name + " (" + std::to_string(_year) + ")";
}
string WhiteWine::prepare()
{
	return "Its not different from beer, just served cold.";
}
string RedWine::prepare()
{
	return "Its not different from beer, served at room temp.";
}