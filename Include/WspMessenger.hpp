#ifndef WSPMESSENGER_HPP
#define WSPMESSENGER_HPP

#include <IMensajero.hpp>

// Implementación específica para Whatsapp
class WspMessenger : public IMensajero
{
private:
  int daysLeft;

public:
  WspMessenger(int daysLeft);
  void sendNotification() const override;
};
#endif