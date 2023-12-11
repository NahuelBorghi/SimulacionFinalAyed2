#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <memory>
#include <Product.hpp>

using namespace std;

class Item
{
private:
  int quantity;
  shared_ptr<Product> product;

public:
  Item(int quantity, shared_ptr<Product> product);

  // setters
  void setQuantity(int newQuantity);
  void setProduct(shared_ptr<Product> newProduct);
  int getQuantity();
  shared_ptr<Product> getProduct();
};

#endif