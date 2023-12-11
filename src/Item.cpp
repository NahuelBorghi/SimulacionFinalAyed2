#include <Item.hpp>

Item::Item(int quantity, shared_ptr<Product> product)
    : quantity(quantity), product(product) {}

void Item::setQuantity(int newQuantity) { quantity = newQuantity; }
void Item::setProduct(shared_ptr<Product> newProduct) { product = newProduct; }
int Item::getQuantity() { return quantity; }
shared_ptr<Product> Item::getProduct() { return product; }