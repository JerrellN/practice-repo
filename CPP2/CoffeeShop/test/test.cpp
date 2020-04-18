#include "../src/shoppingcart.hpp"
#include "../gtest/googletest/include/gtest/gtest.h"



TEST() {
    ShoppingCart * cart = new ShoppingCart(true);
    
    ASSERT_EQ(7.4, cart.AddTotal());
}

TEST() {
    ShoppingCart * cart = new ShoppingCart(true);
    cart.AddToCart("coffee");
    ASSERT_EQ(8.55, cart.AddTotal());
}

TEST() {
    ShoppingCart * cart = new ShoppingCart(true);
    ;
    ASSERT_EQ(true, cart.DetermineZero(0));
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}