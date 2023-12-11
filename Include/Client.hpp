#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <stdexcept> //esta la incluyo para usar throw invalid_argument("Invalid contact method");

using namespace std;

class Client
{
private:
  string name;
  int dni;
  string contact;

public:
  Client(const string &name, int dni, const string &contact);

  // Setters
  void setName(const string &name);
  void setDni(int dni);
  void setContact(const string &contact);

  // Getters
  string getName() const;
  int getDni() const;
  string getContact() const;
};

#endif // CLIENT_HPP
