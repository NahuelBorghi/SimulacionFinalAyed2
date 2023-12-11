#include <Inventory.hpp>

Inventory::Inventory()
{
  // Inicializar el inventario con algunos productos disponibles
  items.push_back({make_shared<Product>("Product1", 50.0), ItemState::Available});
  items.push_back({make_shared<Product>("Product2", 30.0), ItemState::Available});
}

void Inventory::addItem(shared_ptr<Product> product)
{
  items.push_back({product, ItemState::Available});
}

vector<InventoryItem> &Inventory::getItems()
{
  return items;
}
