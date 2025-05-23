#pragma once

#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

#include "Component.h"
#include "Room.h"

// Klasa device - liść w strukturze kompozytu
// Liść w strukturze kompozytu jest podstawowym elementem i nie posiada elementów podrzędnych
class Device : public Component {
	private:
		string name;
		int power;
		double hours;
		string type;
        int ID;

    public:

		// Domyślny konstruktor
        Device();

        // Ustawienia buildera
        void setID(int ID);
        void setName(const string &name);
        void setPower(int power);
        void setHours(double hours);
        void setType(const string &type);
        double getEnergyConsumption() const;
        double simulateDay();
        double simulateWeek();
        double simulateMonth();

        void display() override;

        friend void listAllDevices(Component *component);
        friend double consumptionSUM_day(Component *component);
        friend double consumptionSUM_week(Component *component);
        friend double consumptionSUM_month(Component *component);
};