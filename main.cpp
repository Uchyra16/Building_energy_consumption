#include <iostream>
#include <algorithm>
#include <vector>
#include "menu.h"
#include "Building.h"
#include "Component.h"
#include "DeviceBuilder.h"
#include "Device.h"
#include "Room.h"
using namespace std;

// Aplikacja estymujaca zuzycie energii w budynku



bool running = true;
string building_name = "";
Building* building = new Building(building_name);

int main() {
	//W startowym menu uzytkownik wpisuje nazwe swojego budynku
	building_name = Starting_menu1();
	building->name = building_name;

	Starting_menu2();
	Starting_menu3();

	while(running) {
		  // zwraca wybór użytkownika
		  char choice = Main_menu();
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
