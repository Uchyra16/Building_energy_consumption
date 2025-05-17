#include <iostream>
#include <vector>
using namespace std;

// Aplikacja estymujaca zuzycie energii w budynku

class Component {
public:
    string name;

    virtual void display() {}
};

class Building : public Component {
private:
    vector<Component*> rooms;

public:
    Building(string n) {
        name = n;
    }

    void add(Component* component) {
        rooms.push_back(component);
    }

    void traverse_rooms() {
        for (int i = 0; i < rooms.size(); i++) {
            rooms.at(i)->display(); 
        }
    }
};

class Device {
	private:
		string name;
		int power;
		int hours;
		string type;
		
	public:
		Device(string name, int power) {
			this->name = name;
			this->power = power; 
		}
		
		void getName() {
			cout << this->name;
		}
		
};


class Room : public Component {
	private:
		vector<Device*> devices;
	
	public:
    Room(string n) {
        name = n;
    }

    void display() override {
        cout << "Pokoj: " << name << endl;
        if(devices.empty()) {
             cout << "Nie ma na razie urzadzen" << endl;	
		} else {
			display_devices();
		}

    }
    
    void addDevice(Device* device) {
    	devices.push_back(device);
	}
	
	void display_devices() {
		for(int i = 0; i < devices.size(); i++) {
			devices.at(i)->getName();
		}
	}
};


int main() {
    cout << "Aplikacja estymujaca zuzycie energii w budynku" << endl;

    Room* pokoj1 = new Room("Kuchnia");
    Building* building1 = new Building("Dom");
    Device* device1 = new Device("Piekarnik", 123);

    building1->add(pokoj1);
    
    pokoj1->addDevice(device1);

    building1->traverse_rooms();

	getchar();
	getchar();
}
