#include <vector>
using std::vector;
#include "products.hpp"
#include <string>
using std::string;
#include "names.hpp"
#include <iostream>
using std::cout;
using std::endl;
#include "products.hpp"

class ShoppingCart
{
private: 
    vector<Product> m_cart;
public:

    ShoppingCart()
    {
        m_cart = vector<Product>();
    };

    ShoppingCart(bool test)
    {
        if(test)
        {
            Product coffee = Product(Coffee);
            m_cart.push_back(coffee);
            Product burger = Product(burger);
            m_cart.push_back(burger);
        }
    }

    void AddtoCart(string input)
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
        m_cart.push_back(product);
	
    }

    
    double AddTotal()
    {
        double total = 0;
        for (int i = 0; i < m_cart.size(); i++)
        {
            total += m_cart[i].price;
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

    void ListShoppingCart()
    {
        int coffeeCount = 0;
        int sandwichCount = 0;
        int teaCount = 0;
        int burgerCount = 0;
        cout << "Your shopping cart: " << endl;
        for (int i = 0; i < m_cart.size(); i++)
        {
            if (m_cart[i].daName == Coffee)
            {
                coffeeCount++;
            }
            else if (m_cart[i].daName == Tea)
            {
                teaCount++;
            }
            else if (m_cart[i].daName == Sandwich)
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
};