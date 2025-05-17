#include "Room.h"

Room::Room(string n) {
    name = n;
}

Room::~Room() {
    for (Component* c : devices) {
        delete c;
    }
}

void Room::add(Component* device) {
    devices.push_back(device);
}

void Room::remove(Component* device) {
    devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
}

void Room::display() {
    cout << "Pokoj: " << name << endl;
    if(devices.empty()) {
        cout << "Do tego pokoju nie dodano zadnych urzadzen!..." << endl;	
    } else {
        display_devices();
    }

}

void Room::display_devices() {
    cout << "Urzadzenia: ";
    for(int i = 0; i < devices.size(); i++) {
        devices.at(i)->display();
    }
    cout << "\n\n";
}
