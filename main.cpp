#include <iostream>
#include <Rent.hpp>
#include <Client.hpp>
#include <Product.hpp>
#include <Item.hpp>

int main()
{
  // Crear algunos productos
  auto product1 = std::make_shared<Product>("Chemical Toilet", 250.5);
  auto product2 = std::make_shared<Product>("Tent", 150.0);

  // Crear un cliente
  auto client = std::make_shared<Client>("John Doe", 12345678, "Whatsapp");

  // Crear algunos items
  auto item1 = std::make_shared<Item>(2, product1);
  auto item2 = std::make_shared<Item>(1, product2);

  // Crear una renta
  auto rent = std::make_shared<Rent>(client, 7);

  // Agregar items a la renta
  rent->addItem(item1);
  rent->addItem(item2);

  // Enviar notificación
  rent->sendNotification();

  return 0;
}
