#include "products.hpp"
#include <string>
using std::string;
#include "names.hpp"

class Product
{
public:
	double price;
	Name daName;
	string name;

	Product(Name leName)
	{
		daName = leName;
		if (daName == Coffee)
		{
			name = "coffee";
			price = 2.15;
		}
		else if (daName == Tea)
		{
			price = 2.75;
			name = "tea";
		}
		else if (daName == Sandwich)
		{
			name = "sandwich";
			price = 2.50;
		}
		else
		{
			name = "burger";
			price = 5.25;
		}
	}
};
