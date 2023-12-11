#ifndef FBMESSENGER_HPP
#define FBMESSENGER_HPP

#include <Messenger.hpp>

// Implementación específica para Facebook
class FbMessenger : public Messenger
{
private:
  int daysLeft;

public:
  FbMessenger(int daysLeft);
  void sendNotification() const override;
};

#endif