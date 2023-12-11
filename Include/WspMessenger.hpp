#ifndef WSPMESSENGER_HPP
#define WSPMESSENGER_HPP

#include <Messenger.hpp>

// Implementación específica para Whatsapp
class WspMessenger : public Messenger
{
private:
  int daysLeft;

public:
  WspMessenger(int daysLeft);
  void sendNotification() const override;
};
#endif