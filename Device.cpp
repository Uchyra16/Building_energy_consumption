#include "Device.h"


// Klasa device - liść w strukturze kompozytu
// Liść w strukturze kompozytu jest podstawowym elementem i nie posiada elementów podrzędnych

Device::Device() : name(""), power(0), hours(0), type("") {}

// Ustawienia buildera
void Device::setName(const string& name) { this->name = name; }
void Device::setPower(int power) { this->power = power; }
void Device::setHours(int hours) { this->hours = hours; }
void Device::setType(const string& type) { this->type = type; }

void Device::display() {
    cout << "\n   Urzadzenie: " << name
        << ", Moc: " << power << "W"
        << ", Czas pracy: " << hours << "h"
        << ", Typ: " << type << endl;
}


