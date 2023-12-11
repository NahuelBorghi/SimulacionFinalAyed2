#include <Product.hpp>

Product::Product(string name, float price)
    : name(name), price(price) {}

void Product::setName(string newName) { name = newName; }
void Product::setPrice(float newPrice) { price = newPrice; }
string Product::getName() { return name; }
float Product::getPrice() { return price; }