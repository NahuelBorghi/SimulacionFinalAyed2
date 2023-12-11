#include <iostream>
#include <Rent.hpp>
#include <Client.hpp>
#include <Product.hpp>
#include <Item.hpp>

using namespace std;

int rentId = 0;

int main()
{
  // Crear productos y agregarlos al inventario
  auto product1 = make_shared<Product>("Chemical Toilet", 250.5);
  auto product2 = make_shared<Product>("Tent", 150.0);

  Inventory inventory;
  inventory.addItem(product1);
  inventory.addItem(product2);

  cout << "Products available for rent:\n";
  const auto &inventoryItems = inventory.getItems();
  for (const auto &inventoryItem : inventoryItems)
  {
    cout << "- " << inventoryItem.product->getName() << " ($" << inventoryItem.product->getPrice() << ")\n";
  }

  // Crear un cliente
  auto client = make_shared<Client>("Jose Luis", 12345678, "Whatsapp");

  // Crear una renta
  auto rent = make_shared<Rent>(client, 7, inventory);

  // Enviar notificación
  rent->sendNotification();

  // Mostrar reporte
  rent->printReport();

  return 0;
}
