#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

using namespace std;

class Product
{
private:
  static int nextProductId;
  int productId;
  string name;
  float price;

public:
  Product(string name, float price);

  // setters
  void setId(int newId);
  void setName(string newName);
  void setPrice(float newPrice);
  int getId();
  string getName();
  float getPrice();
};

#endif