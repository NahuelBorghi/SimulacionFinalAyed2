#include <Client.hpp>

Client::Client(const string &name, int dni, const string &contact)
    : name(name), dni(dni), contact(contact)
{
    if (contact != "Whatsapp" && contact != "Instagram" && contact != "Facebook")
    {
        throw invalid_argument("Invalid contact method");
    }
}

// Setters
void Client::setName(const string &name) { this->name = name; }
void Client::setDni(int dni) { this->dni = dni; }
void Client::setContact(const string &contact) { this->contact = contact; }

// Getters
string Client::getName() const { return name; }
int Client::getDni() const { return dni; }
string Client::getContact() const { return contact; }
