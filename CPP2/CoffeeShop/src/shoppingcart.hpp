#include <vector>
using std::vector;
#include "products.hpp"
#include <string>
using std::string;
#include "products.hpp"

class ShoppingCart
{
private: 
    vector<Product> m_cart;
public:
    ShoppingCart();
    ShoppingCart(bool test);
    Product AddtoCart(string input);
    double AddTotal();
    void ListShoppingCart();
    bool determineZero(int val);
};