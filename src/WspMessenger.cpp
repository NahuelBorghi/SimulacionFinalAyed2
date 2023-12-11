#include <WspMessenger.hpp>

WspMessenger::WspMessenger(int daysLeft)
    : daysLeft(daysLeft) {}

void WspMessenger::sendNotification() const
{
  cout << "Whatsapp : " << daysLeft << " days left to rent expiration\n";
}