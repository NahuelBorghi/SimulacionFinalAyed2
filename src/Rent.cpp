#include <Rent.hpp>

using namespace std;

int Rent::nextRentID = 1;

Rent::Rent(shared_ptr<Client> client, int durationInDays, Inventory &inventory) : client(client), durationInDays(durationInDays), rentID(nextRentID++)
{
  // Asignar productos disponibles al alquiler y cambiar su estado a Rented
  auto &inventoryItems = inventory.getItems();
  for (auto &inventoryItem : inventoryItems)
  {
    if (inventoryItem.state == ItemState::Available)
    {
      addItem(std::make_shared<Item>(1, inventoryItem.product));
      inventoryItem.state = ItemState::Rented;
    }
  }
}

int Rent::getId() const { return rentID; }

shared_ptr<Client> Rent::getClient() const { return client; }

int Rent::getDurationInDays() const { return durationInDays; }

const vector<shared_ptr<Item>> &Rent::getItems() const { return items; }

void Rent::setClient(shared_ptr<Client> newClient) { client = newClient; }

void Rent::setDurationInDays(int newDuration) { durationInDays = newDuration; }

void Rent::addItem(shared_ptr<Item> item)
{
  if (!item->getProduct())
  {
    throw invalid_argument("Item must have a Product");
  }
  items.push_back(item);
}

shared_ptr<Item> Rent::popItem()
{
  if (!items.empty())
  {
    auto lastItem = items.back();
    items.pop_back();
    return lastItem;
  }
  return nullptr; // Return nullptr if this cant find any item
}

shared_ptr<Item> Rent::findItemByName(const string &itemName)
{
  auto it = find_if(items.begin(), items.end(), [&itemName](const shared_ptr<Item> &item)
                    { return item->getProduct()->getName() == itemName; });

  if (it != items.end())
  {
    auto foundItem = *it;
    items.erase(it);
    return foundItem;
  }

  return nullptr;
}
void Rent::sendNotification() const
{
  // Obtener el contacto del cliente
  string contactMethod = client->getContact();

  // Crear el messenger correspondiente según el método de contacto
  unique_ptr<Messenger> messenger;

  if (contactMethod == "Whatsapp")
  {
    messenger = make_unique<WspMessenger>(durationInDays);
  }
  else if (contactMethod == "Instagram")
  {
    messenger = make_unique<IgMessenger>(durationInDays);
  }
  else if (contactMethod == "Facebook")
  {
    messenger = make_unique<FbMessenger>(durationInDays);
  }
  else
  {
    // Manejar el caso en que el método de contacto no sea reconocido
    cout << "Error: Método de contacto no reconocido\n";
    return; // Salir si el método de contacto no es reconocido
  }

  // Verificar si se creó el messenger y enviar la notificación
  if (messenger)
  {
    messenger->sendNotification();
  }
  else
  {
    // Manejar el caso en que el messenger no se haya creado correctamente
    cout << "Error: No se pudo crear el messenger\n";
  }
}

void Rent::printReport() const
{
  cout << "Rent ID: " << rentID << endl
       << "Client: " << client->getName() << endl
       << "Duration: " << durationInDays << " days" << endl
       << "Items rented:" << endl;
  for (const auto &item : items)
  {
    cout << "- " << item->getQuantity() << " | " << item->getProduct()->getName() << endl;
  }
  cout << endl;
}
