#include <iostream>
#include <algorithm>
#include <vector>
#include "menu.h"
using namespace std;

// Aplikacja estymujaca zuzycie energii w budynku


//Klasa bazowa struktury kompozytowej - drzewiastej
class Component {
public:
    string name;

	virtual void add(Component *component) {}
	virtual void remove(Component *component) {}
	virtual void display() {}

	virtual ~Component() {
		cout << "Destructor has been called!...";
	}
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

	~Building() {
		for (Component* c : rooms) {
			delete c;
		}
	}

    void add(Component* room) override {
        this->rooms.push_back(room);
    }

	void remove(Component* room) override {
		rooms.erase(std::remove(rooms.begin(), rooms.end(), room), rooms.end());
	}

    void display() {
        for (int i = 0; i < rooms.size(); i++) {
			cout << "Budynek: " << this->name << endl;
			rooms.at(i)->display(); 
        }
    }
};


// Klasa device - liść w strukturze kompozytu
// Liść w strukturze kompozytu jest podstawowym elementem i nie posiada elementów podrzędnych
class Device : public Component {
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
		
		void display() override {
			cout << this->name << ", ";
		}
		
};

// Klasa Room - jest podrzędnym kontenerem klasy Building
// W pokoju znajdują sie inne urządzenia - liście
class Room : public Component {
	private:
		vector<Component*> devices;
	
	public:
		Room(string n) {
			name = n;
		}

		~Room() {
			for (Component* c : devices) {
				delete c;
			}
		}
		
		void add(Component* device) override {
			devices.push_back(device);
		}

		void remove(Component* device) override {
			devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
		}
		
		void display() override {
			cout << "Pokoj: " << name << endl;
			if(devices.empty()) {
				cout << "Do tego pokoju nie dodano zadnych urzadzen!..." << endl;	
			} else {
				display_devices();
			}

		}

		void display_devices() {
			cout << "Urzadzenia: ";
			for(int i = 0; i < devices.size(); i++) {
				devices.at(i)->display();
			}
			cout << "\n\n";
		}
};

int main() {

	
	bool running = true;

	while(running) {
		  // zwraca wybór użytkownika
		  char choice = Starting_menu();
        switch (choice) {
            case '1':
                ConsumptionSummary_menu();
                break;
            case '2':
                RoomList_menu();
                break;
            case '3':
				History_menu();
				break;
            case '4':
				Notifications_menu();
				break;
            case '5':
				Settings_menu();
				break;
            case '6':
                running = false; // zakończ aplikację
                break;
            default:
                cout << "Nieprawidlowy wybor!\n";
                break;
        }
	}

	// Building* building1 = new Building("Dom");

	// Room* pokoj1 = new Room("Kuchnia");
	// Device* device1 = new Device("Piekarnik", 123);
	// Device *device2 = new Device("Zmywarka", 345);

	// Room *pokoj2 = new Room("Lazienka");
	// Device* device3 = new Device("Kibel", 123);
	// Device *device4 = new Device("Prysznic", 345);
   

	// building1->add(pokoj1);
	// building1->add(pokoj2);

	// pokoj1->add(device1);
	// pokoj1->add(device2);

	// pokoj2->add(device3);
	// pokoj2->add(device4);

	// building1->display();

}
