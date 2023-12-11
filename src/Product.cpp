#include <Product.hpp>

int Product::nextProductId = 1;

Product::Product(string name, float price)
    : productId(nextProductId++), name(name), price(price) {}

void Product::setId(int newId) { productId = newId; }
void Product::setName(string newName) { name = newName; }
void Product::setPrice(float newPrice) { price = newPrice; }
int Product::getId() { return productId; }
string Product::getName() { return name; }
float Product::getPrice() { return price; }