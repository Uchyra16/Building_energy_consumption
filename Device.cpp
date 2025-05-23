#include "Device.h"


// Klasa device - liść w strukturze kompozytu
// Liść w strukturze kompozytu jest podstawowym elementem i nie posiada elementów podrzędnych

Device::Device() : name(""), power(0), hours(0), type(""), ID(0) {}

// Ustawienia buildera
void Device::setName(const string& name) { this->name = name; }
void Device::setPower(int power) { this->power = power; }
void Device::setHours(double hours) { this->hours = hours; }
void Device::setType(const string& type) { this->type = type; }
void Device::setID(int ID) { this->ID = ID; }

void Device::display() {
    cout << name
        << ", Moc: " << power << "W"
        << ", Czas pracy: " << hours << "h"
        << ", Typ: " << type << endl;
}

double Device::getEnergyConsumption() const {
    return (power * hours) / 1000.0; //Zwraca zuzycie w kWh
}

double randomFloat(double min, double max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

double Device::simulateDay() {
    double randomHours = randomFloat(1.0, 5.0); // Załóżmy 1–10h dziennie
    return (power * randomHours) / 1000.0;
}

double Device::simulateWeek() {
    double total = 0.0;
    for (int i = 0; i < 7; ++i) {
        total += simulateDay(); // Użyj simulateDay(), które ma sensowny zakres godzin
    }
    return total;
}

double Device::simulateMonth() {
    double total = 0.0;
    for (int i = 0; i < 31; ++i) {
        total += simulateDay(); // Suma zużycia z 31 dni
    }
    return total;
}



