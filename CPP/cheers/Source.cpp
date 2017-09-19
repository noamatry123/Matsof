#include "Drinks.h"
void main()
{
	Bar bar;
	bar.DisplayMenu();
	bar.BuyDrink(0);
	bar.HowDidYouPrepare();
	bar.BuyDrink(1);
	bar.HowDidYouPrepare();
	bar.BuyDrink(4);
	bar.HowDidYouPrepare();
	bar.BuyDrink(5);
	bar.HowDidYouPrepare();

	getchar();
}