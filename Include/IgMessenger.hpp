#ifndef IGMESSENGER_HPP
#define IGMESSENGER_HPP

#include <IMensajero.hpp>

// Implementación específica para Instagram
class IgMessenger : public IMensajero
{
private:
  int daysLeft;

public:
  IgMessenger(int daysLeft);
  void sendNotification() const override;
};
#endif