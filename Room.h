#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "Component.h"

// Klasa Room - jest podrzędnym kontenerem klasy Building
// W pokoju znajdują sie inne urządzenia - liście
class Room : public Component {
	private:
		vector<Component*> devices;

    public:
        Room(string n, int ID);
        ~Room();

        void add(Component *device) override;

        void remove(Component *device) override;

        void display() override;

        void display_devices();

        friend void RoomList_menu();
        friend void Starting_menu3();
        friend void Starting_menu4();
};