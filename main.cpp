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
		cout << "Destructor has been called!...\n";
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

		// Domyślny konstruktor
		Device() : name(""), power(0), hours(0), type("") {}

		// Ustawienia buildera
		void setName(const string& name) { this->name = name; }
		void setPower(int power) { this->power = power; }
		void setHours(int hours) { this->hours = hours; }
		void setType(const string& type) { this->type = type; }

		void display() override {
			cout << "\n   Urzadzenie: " << name
				<< ", Moc: " << power << "W"
				<< ", Czas pracy: " << hours << "h"
				<< ", Typ: " << type << endl;
		}
		
};

// Klasa DeviceBuilder - służąca do dodawania nowych urządzeń
class DeviceBuilder {
private:
	Device* device;

public:

	DeviceBuilder() {
		this->Reset();
	}

	~DeviceBuilder() {
		delete device;
	}

	// Nowe urządzenie
	void Reset() {
		delete this->device;
		this->device = new Device();
	}

	// Metody budowniczego
	DeviceBuilder& setName(const string& name) {
		this->device->setName(name);
		return *this;
	}

	DeviceBuilder& setPower(int power) {
		this->device->setPower(power);
		return *this;
	}

	DeviceBuilder& setHours(int hours) {
		this->device->setHours(hours);
		return *this;
	}

	DeviceBuilder& setType(const string& type) {
		this->device->setType(type);
		return *this;
	}

	// Budowanie urządzenia
	Device* build() {
		Device* result = this->device;
		this->device = nullptr;	
		this->Reset();
		return result;

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

bool running = true;

int main() {

	clearConsole();
	while(1) {
		menuHeader("EKRAN STARTOWY");
		cout << "\n\n\n\n";
		menuFooter();

		char menu_choice = _getch();

		if(menu_choice == '8') {
			break;
		} else {
			clearConsole();
		}
	}

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

	//  Building* building1 = new Building("Dom");

	//  Room* pokoj1 = new Room("Kuchnia");
	//  Room *pokoj2 = new Room("Lazienka");
   
	//  building1->add(pokoj1);
	//  building1->add(pokoj2);

	//  DeviceBuilder builder;
	//  Device* device1 = builder
	// 	 .setName("Vacuum Cleaner")
	// 	 .setPower(1200)
	// 	 .setHours(2)
	// 	 .setType("Cleaning")
	// 	 .build();
	//  Device* device2 = builder
	// 	 .setName("Fridge")
	// 	 .setPower(2000)
	// 	 .setHours(24)
	// 	 .setType("Food")
	// 	 .build();
	//  Device* device3 = builder
	// 	 .setName("TV")
	// 	 .setPower(120)
	// 	 .setHours(6)
	// 	 .setType("RTV")
	// 	 .build();
	//  Device* device4 = builder
	// 	 .setName("Ludzik")
	// 	 .setPower(12000)
	// 	 .setHours(11)
	// 	 .setType("ludzik")
	// 	 .build();

	//  pokoj1->add(device1);
	//  pokoj1->add(device2);

	//  pokoj2->add(device3);
	//  pokoj2->add(device4);

	//  building1->display();

	//  getchar();
	//  getchar();
}
