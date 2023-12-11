#ifndef IGMESSENGER_HPP
#define IGMESSENGER_HPP

#include <Messenger.hpp>

// Implementación específica para Instagram
class IgMessenger : public Messenger
{
private:
  int daysLeft;

public:
  IgMessenger(int daysLeft);
  void sendNotification() const override;
};
#endif