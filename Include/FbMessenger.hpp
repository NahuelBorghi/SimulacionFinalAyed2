#ifndef FBMESSENGER_HPP
#define FBMESSENGER_HPP

#include <IMensajero.hpp>

// Implementación específica para Facebook
class FbMessenger : public IMensajero
{
private:
  int daysLeft;

public:
  FbMessenger(int daysLeft);
  void sendNotification() const override;
};

#endif