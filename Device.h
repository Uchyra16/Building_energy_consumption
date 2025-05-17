#pragma once

#include <iostream>
using namespace std;

#include "Component.h"

// Klasa device - liść w strukturze kompozytu
// Liść w strukturze kompozytu jest podstawowym elementem i nie posiada elementów podrzędnych
class Device : public Component {
	private:
		string name;
		int power;
		int hours;
		string type;
		
	public:

		// Domyślny konstruktor
        Device();

        // Ustawienia buildera
        void setName(const string &name);
        void setPower(int power);
        void setHours(int hours);
        void setType(const string &type);

        void display() override;
};