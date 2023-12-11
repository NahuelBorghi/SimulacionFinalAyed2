#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

using namespace std;

class Product
{
private:
  string name;
  float price;

public:
  Product(string name, float price);

  // setters
  void setName(string newName);
  void setPrice(float newPrice);
  string getName();
  float getPrice();
};

#endif