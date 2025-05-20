#include "Device.h"


// Klasa device - liść w strukturze kompozytu
// Liść w strukturze kompozytu jest podstawowym elementem i nie posiada elementów podrzędnych

Device::Device() : name(""), power(0), hours(0), type(""), ID(0) {}

// Ustawienia buildera
void Device::setName(const string& name) { this->name = name; }
void Device::setPower(int power) { this->power = power; }
void Device::setHours(int hours) { this->hours = hours; }
void Device::setType(const string& type) { this->type = type; }
void Device::setID(int ID) { this->ID = ID; }

void Device::display() {
    cout << "[" << ID << "] " << name
        << ", Moc: " << power << "W"
        << ", Czas pracy: " << hours << "h"
        << ", Typ: " << type << endl;
}

double Device::getEnergyConsumption() const {
    return (power * hours) / 1000.0; //Zwraca zuzycie w kWh
}

float randomFloat()
{
    return (float)(rand()) / (float)(rand());
}

double Device::simulateDay() {
    double randomHours = randomFloat();
    return (power * randomHours) / 1000.0;
}

double Device::simulateWeek() {
    double randomHours = randomFloat();
    return 7*(power * randomHours) / 1000.0;
}

double Device::simulateMonth() {
    double randomHours = randomFloat();
    return 31*(power * randomHours) / 1000.0;
}




