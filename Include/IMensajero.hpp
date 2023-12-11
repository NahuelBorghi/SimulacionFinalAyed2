#ifndef MESSENGER_HPP
#define MESSENGER_HPP

#include <string>
#include <iostream>

using namespace std;

class IMensajero
{
public:
  virtual ~IMensajero() = default;

  // Método para enviar la notificación
  virtual void sendNotification() const = 0;
};

#endif
