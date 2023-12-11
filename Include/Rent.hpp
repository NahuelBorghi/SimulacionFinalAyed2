#ifndef RENT_HPP
#define RENT_HPP
#pragma once

#include <Client.hpp>
#include <Messenger.hpp>
#include <WspMessenger.hpp>
#include <IgMessenger.hpp>
#include <FbMessenger.hpp>
#include <Inventory.hpp>
#include <Item.hpp>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Rent
{
private:
  static int nextRentID;
  int rentID;
  shared_ptr<Client> client;
  int durationInDays;
  vector<shared_ptr<Item>> items;

public:
  Rent(shared_ptr<Client> client, int durationInDays, Inventory &inventory);

  // Getters
  int getId() const;
  shared_ptr<Client> getClient() const;
  int getDurationInDays() const;
  const vector<shared_ptr<Item>> &getItems() const;
  // Setters
  void setClient(shared_ptr<Client> newClient);
  void setDurationInDays(int newDuration);
  void setId(int newId);
  // Items related methods. LIFO(last In, Firts Out)
  void addItem(shared_ptr<Item> item);
  shared_ptr<Item> popItem();
  shared_ptr<Item> findItemByName(const string &itemName);
  // Other methods
  void sendNotification() const;
  void printReport() const;
};

#endif