#include <FbMessenger.hpp>

FbMessenger::FbMessenger(int daysLeft)
    : daysLeft(daysLeft) {}

void FbMessenger::sendNotification() const
{
  cout << "Facebook : " << daysLeft << " days left to rent expiration\n";
}