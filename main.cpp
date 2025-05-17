#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Aplikacja estymujaca zuzycie energii w budynku


//Klasa bazowa struktury kompozytowej - drzewiastej
class Component {
public:
    string name;

	virtual void add(Component *component) {}
	virtual void remove(Component *component) {}
	virtual void display() {}
};


// Klasa Building - Kompozyt(Kontener) posiada elementy podrzędne - liście lub inne kontenery w tym przypadku urządzenia lub pokoje
// Kontener komunikuje się z elementami podrzednymi tylko poprzez interfejs komponentu
// Kontener deleguje prace do swoich podelementów
class Building : public Component {
private:
    vector<Component*> rooms;

public:
    Building(string n) {
        name = n;
    }

    void add(Component* component) override {
        this->rooms.push_back(component);
    }

	void remove(Component* component) override {
		rooms.erase(std::remove(rooms.begin(), rooms.end(), component), rooms.end());
	}

    void traverse_rooms() {
        for (int i = 0; i < rooms.size(); i++) {
            rooms.at(i)->display(); 
        }
    }
};


// Klasa device - liść w strukturze kompozytu
// Liść w strukturze kompozytu jest podstawowym elementem i nie posiada elementów podrzędnych
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

// Klasa Room - jest podrzędnym kontenerem klasy Building
// W pokoju znajdują sie inne urządzenia - liście
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
             cout << "Do tego pokoju nie dodano zadnych urzadzen!..." << endl;	
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
