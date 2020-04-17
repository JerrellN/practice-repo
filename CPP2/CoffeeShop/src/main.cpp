#include <iostream>
#include <string>
using std::string;
#include <vector>
using std::vector;
using std::cout;
using std::cin;
#include <cctype>
using std::tolower;
using std::endl;
#include "products.hpp"
#include "names.hpp"
#include "currency.hpp"





string getInput()
{
	string input = " ";
	cout << "Please type what product you'd like." << endl;
	cin >> input;
	for (int i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}
	if (input != "coffee" && input != "tea" && input != "sandwich" && input != "burger")
	{
		cout << "That is not a valid input, please trying again." << endl;
		getInput();
	}
	return input;
}

Product addToCart(string input, vector<Product> theProducts)
{
	Product product = Product(Coffee);
	if (input == "coffee")
	{
		product = Product(Coffee);
	}
	else if (input == "tea")
	{
		product = Product(Tea);
	}
	else if (input == "sandwich")
	{
		product = Product(Sandwich);
	}
	else 
	{
		product = Product(Burger);
	}
	return product;
	
}

double AddTotal(vector<Product> shoppingCart)
{
	double total = 0;
	for (int i = 0; i < shoppingCart.size(); i++)
	{
		total += shoppingCart[i].price;
	}
	return total;
}

bool determineZero(int val)
{
	if (val == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void listShoppingCart(vector<Product> shoppingCart)
{
	int coffeeCount = 0;
	int sandwichCount = 0;
	int teaCount = 0;
	int burgerCount = 0;
	cout << "Your shopping cart: " << endl;
	for (int i = 0; i < shoppingCart.size(); i++)
	{
		if (shoppingCart[i].daName == Coffee)
		{
			coffeeCount++;
		}
		else if (shoppingCart[i].daName == Tea)
		{
			teaCount++;
		}
		else if (shoppingCart[i].daName == Sandwich)
		{
			sandwichCount++;
		}
		else
		{
			burgerCount++;
		}
	}
	if (!determineZero(burgerCount))
	{
		cout << "Burger(s) " << burgerCount << endl;
	}
	if (!determineZero(sandwichCount))
	{
		cout << "Sandwich(es) " << sandwichCount << endl;
	}
	if (!determineZero(teaCount))
	{
		cout << "Tea(s) " << teaCount << endl;
	}
	if (!determineZero(coffeeCount))
	{
		cout << "Coffee(s) " << coffeeCount << endl;
	}
}


void listInventory(vector<Product> theProducts)
{
	for (int i = 0; i < theProducts.size(); i++)
	{
		cout << "We have " << theProducts[i].name << " for $" << theProducts[i].price << endl;
	}
}

bool checkInputNum(string input)
{
	if (input != "1" && input != "5" && input != "10" && input != "20")
	{
		return false;
	}
	else
	{
		return true;
	}
}

int convertInputNum(string input)
{
	if (input == "1")
	{
		return 1;
	}
	else if (input == "10")
	{
		return 10;
	}
	else if (input == "20")
	{
		return 20;
	}
	else
	{
		return 5;
	}
}

bool checkPayment(double moneyGiven, double cartTotal)
{
	if (cartTotal > moneyGiven)
	{
		return false;
	}
	else
	{
		return true;
	}
}

vector<Currency *> *MakeChange(int moneyGiven, double cartTotal)
{
	vector<Currency *> * currencyRepo = new vector<Currency *>;
	double change = 0;
	change = moneyGiven - cartTotal;
	cout << "Your change is $" << change << endl;
	while (change != 0)
	{
		if (change > 20)
		{
			currencyRepo->push_back(new Twenty);
			change -= 20;
		}
		else if (change > 10)
		{
			currencyRepo->push_back(new Ten);
			change -= 10;
		}
		else if (change > 5)
		{
			currencyRepo->push_back(new Five);
			change -= 5;
		}
		else if (change > 1)
		{
			currencyRepo->push_back(new One);
			change -= 1;
		}
		else if (change > .25)
		{
			currencyRepo->push_back(new Quarter);
			change -= .25;
		}
		else if (change > .10)
		{
			currencyRepo->push_back(new Dime);
			change -= .10;
		}
		else if (change > .05)
		{
			currencyRepo->push_back(new Nickle);
			change -= .05;
		}
		else if (change > .01)
		{
			currencyRepo->push_back(new Penny);
			change -= .01;
		}
		else
		{
			change = 0;
		}
	}

	return currencyRepo;
}

int main()
{
	double total = 0;
	vector<Product> products = vector<Product>();
	Product exSandwich = Product(Sandwich);
	Product exTea = Product(Tea);
	Product exCoffee = Product(Coffee);
	Product exBurger = Product(Burger);

	products.push_back(exCoffee);
	products.push_back(exTea);
	products.push_back(exBurger);
	products.push_back(exSandwich);

	vector<Product> shoppingCart = vector<Product>();

	string input = " ";
	string cont = " ";
	int num;
	while (cont != "n")
	{
		listInventory(products);
		input = getInput();
		cout << "How many? " << endl;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			shoppingCart.push_back(addToCart(input, products));
		}
		cout << "Would you like to continue shopping? (y/n)" << endl;;
		cin >> cont;
	}
	vector<Currency *> *Change = new vector<Currency *>;
	listShoppingCart(shoppingCart);
	total = AddTotal(shoppingCart);
	cout << "Your total is $" << total << endl;
	cout << "How would you like to pay? (Enter 1, 5, 10, or 20)" << endl;

	cin >> input;
	double moneyOwed = 0;
	moneyOwed = total;
	if (moneyOwed > 20)
	{
		int payment = 0;
		while (moneyOwed > 0)
		{
			while (!checkInputNum(input))
			{
				cout << "invalid input, please put in 1, 5, 10, or 20." << endl;
				cin >> input;
				checkInputNum(input);
				if (checkInputNum(input))
				{
					int payment = convertInputNum(input);
					checkPayment(payment, total);
					Change = MakeChange(payment, total);
				}
			}
			if (checkInputNum(input))
			{
				payment += convertInputNum(input);
				moneyOwed -= convertInputNum(input);
				if (moneyOwed < 0)
				{
					moneyOwed = 0;
				}
			}
			cout << "$" << moneyOwed << " remaining." << endl;
			if (moneyOwed > 0)
			{
				cout << "How would you like to pay? (Enter 1, 5, 10, or 20)" << endl;
				cin >> input;
			}
		}
		checkPayment(payment, total);
		Change = MakeChange(payment, total);
	}
	else
	{
		while (!checkInputNum(input))
		{
			cout << "invalid input, please put in 1, 5, 10, or 20." << endl;
			cin >> input;
			checkInputNum(input);
			if (checkInputNum(input))
			{
				int payment = convertInputNum(input);
				checkPayment(payment, total);
				Change = MakeChange(payment, total);
			}
		}
		if (checkInputNum(input))
		{
			int payment = convertInputNum(input);
			checkPayment(payment, total);
			Change = MakeChange(payment, total);
		}
	}
}