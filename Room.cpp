#include "Room.h"

Room::Room(string n, int id) {
    name = n;
    ID = id;
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
    cout << "\nUrzadzenia: \n";
    for(int i = 0; i < devices.size(); i++) {
        cout << "[ " << i+1 << " ] ";
        devices.at(i)->display();
    }
    cout << "\n\n";
}

void Room::setId(int id)
{
    this->ID = id;
}

vector<Component*> Room::getChildren() 
{
    vector<Component *> result;
    for (int i = 0; i < devices.size(); i++)
    {
        result.push_back(devices.at(i));
    }
    return result;
}

