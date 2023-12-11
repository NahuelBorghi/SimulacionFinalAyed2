#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include <Client.hpp>
#include <Item.hpp>
#include <Rent.hpp>
#include <Product.hpp>
#include <iostream>
#include <sstream>
#include <catch.hpp>

#define chango auto

using namespace std;

string captureOutput(function<void()> func)
{
  ostringstream oss;
  auto oldCoutBuffer = cout.rdbuf(oss.rdbuf());
  func();
  cout.rdbuf(oldCoutBuffer); // Restaurar el buffer original
  return oss.str();
}
//
// Client   -----------------------------------------------------------------------
//

TEST_CASE("Correct getName from Client", "[getName method]")
{
  // Arrange                                                                      |
  chango client1 = make_shared<Client>("Jose Luis Oemig", 30456987, "Whatsapp");
  // Act                                                                          |
  string clientName = client1->getName();
  // Assert                                                                       |
  REQUIRE(clientName == "Jose Luis Oemig");
}
TEST_CASE("Correct getContact from Client", "[getContact method]")
{
  // Arrange                                                                      |
  chango client1 = make_shared<Client>("Jose Luis Oemig", 30456987, "Whatsapp");
  // Act                                                                          |
  string clientContact = client1->getContact();
  // Assert                                                                       |
  REQUIRE(clientContact == "Whatsapp");
}
TEST_CASE("Correct getDni from Client", "[getDni method]")
{
  // Arrange                                                                      |
  chango client1 = make_shared<Client>("Jose Luis Oemig", 30456987, "Whatsapp");
  // Act                                                                          |
  int clientDni = client1->getDni();
  // Assert                                                                       |
  REQUIRE(clientDni == 30456987);
}

//
// Item and Product   -------------------------------------------------------------
//

TEST_CASE("Correct getQuantity from Item", "[getQuantity method]")
{
  // Arrange                                                                      |
  chango product1 = make_shared<Product>("Chemical Toilet", 250.5);
  chango item1 = make_shared<Item>(2, product1);
  // Act                                                                          |
  int itemQuantity = item1->getQuantity();
  // Assert                                                                       |
  REQUIRE(itemQuantity == 2);
}
TEST_CASE("Correct getProduct from Item", "[getProduct method]")
{
  // Arrange                                                                      |
  chango product1 = make_shared<Product>("Chemical Toilet", 250.5);
  chango item1 = make_shared<Item>(2, product1);
  // Act & Assert                                                                 |
  REQUIRE(item1->getProduct() == product1);
}
TEST_CASE("Correct getName from Product", "[getName method]")
{
  // Arrange                                                                      |
  chango product1 = make_shared<Product>("Chemical Toilet", 250.5);
  chango item1 = make_shared<Item>(2, product1);
  // Act
  shared_ptr<Product> itemProduct = item1->getProduct();
  string productName = itemProduct->getName();
  // Assert                                                                       |
  REQUIRE(productName == "Chemical Toilet");
}

//
// Rent   -------------------------------------------------------------------------
//
TEST_CASE("Correct addItem and getItem from Rent", "[getItem method]")
{
  // Arrange                                                                      |
  chango client1 = make_shared<Client>("Jose Luis Oemig", 30456987, "Whatsapp");
  chango product1 = make_shared<Product>("Chemical Toilet", 250.5);
  chango item1 = make_shared<Item>(2, product1);
  chango rent1 = make_shared<Rent>(client1, 7);
  rent1->addItem(item1);
  // Act & Assert                                                                 |
  REQUIRE(rent1->popItem() == item1);
}
TEST_CASE("Correct sendNotification from Rent", "[sendNotification method]")
{
  // Arrange                                                                      |
  chango client1 = make_shared<Client>("Jose Luis Oemig", 30456987, "Whatsapp");
  chango product1 = make_shared<Product>("Chemical Toilet", 250.5);
  chango item1 = make_shared<Item>(2, product1);
  chango rent1 = make_shared<Rent>(client1, 7);
  rent1->addItem(item1);

  // Act                                                                          |
  string output = captureOutput([&]
                                { rent1->sendNotification(); });

  // Assert                                                                       |
  REQUIRE(output == "Whatsapp : 7 days left to rent expiration\n");
}
TEST_CASE("Exception thrown when adding Item without Product", "[addItem method]")
{
  // Arrange                                                                      |
  chango client1 = make_shared<Client>("Jose Luis Oemig", 30456987, "Whatsapp");
  chango rent1 = make_shared<Rent>(client1, 7);

  // Act & Assert                                                                 |
  REQUIRE_THROWS_AS(rent1->addItem(make_shared<Item>(2, nullptr)), invalid_argument);
}
TEST_CASE("Exception thrown for invalid contact method", "[Client constructor]")
{
  // Arrange, Act & Assert                                                        |
  REQUIRE_THROWS_AS(make_shared<Client>("Jose Luis Oemig", 30456987, "InvalidContact"), invalid_argument);
}
