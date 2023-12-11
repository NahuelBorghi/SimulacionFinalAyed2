#include <IgMessenger.hpp>

IgMessenger::IgMessenger(int daysLeft)
    : daysLeft(daysLeft) {}

void IgMessenger::sendNotification() const
{
  cout << "Instagram : " << daysLeft << " days left to rent expiration\n";
}