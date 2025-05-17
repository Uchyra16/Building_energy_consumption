#include "Building.h"


Building::Building(string n) {
    name = n;
}

Building::~Building() {
    for (Component* c : rooms) {
        delete c;
    }
}

void Building::add(Component* room) {
    this->rooms.push_back(room);
}

void Building::remove(Component* room) {
    rooms.erase(std::remove(rooms.begin(), rooms.end(), room), rooms.end());
}

void Building::display() {

    for (int i = 1; i <= rooms.size(); i++)
    {
        cout << "Pokoj [" << i << "] :" << rooms.at(i-1)->name << endl;
    }

}
   