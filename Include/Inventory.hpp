// Inventory.hpp
#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include <memory>
#include <Product.hpp>

enum class ItemState
{
  Available,
  Rented
};

struct InventoryItem
{
  shared_ptr<Product> product;
  ItemState state;
};

class Inventory
{
private:
  vector<InventoryItem> items;

public:
  Inventory();

  void addItem(shared_ptr<Product> product);
  vector<InventoryItem> &getItems();
};

#endif
