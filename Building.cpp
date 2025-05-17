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
    cout << "Budynek: " << this->name << endl;
    for (int i = 0; i < rooms.size(); i++) {
        rooms.at(i)->display(); 
    }
}
   