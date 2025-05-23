#include "menu.h"


//Variables from other files:
extern bool running;
extern string building_name;
int menu_choice = 0;
extern Building *building;
extern DeviceBuilder builder;


//Variables of this file 
int OLD_number_of_devices = 0;
double consumptionSUM_day_var = 0;
double consumptionSUM_month_var = 0;
double consumptionSUM_week_var = 0;


string clientInput()
{
	string input = "";
	while(1) {
		char c = _getch();

		if(c == '9') {
			running = false;
			break;
		} else if (c == '\r') {	//Enter potwierdza wpisana nazwe
			cout << endl;
			break;
		}else if (c == '\b' && !input.empty()) {  // Backspace obsługa
			input.pop_back();
			cout << "\b \b"; // usuń z konsoli
			continue;
		}
		
		// Wpisywanie znaku
		input += c;
		cout << c;
	}

	return input;
}

void cursorLine_UP(int num_of_lines)
{
	for (int i = 0; i < num_of_lines; i++)
	{
		cout << "\033[A";
	}
	cout << "\t\t\t\t\t\t\t";
}

void menuHeader(string text)
{
	cout << "========================================================================================================================\n";
	cout << "\t\t\t\t\t\t" << text << "\t\t\t\n";
	cout << "========================================================================================================================\n";
}

void menuFooter()
{
	cout << "========================================================================================================================\n";
	cout << "\t\t\t\t\t\t" << "[8] Powrot" << "\t\t\t\n";
	cout << "========================================================================================================================\n";
}


void menuFooter_empty()
{
	cout << "========================================================================================================================\n";
	cout << endl;
	cout << "========================================================================================================================\n";
}

void menuFooter_starting()
{
	cout << "========================================================================================================================\n";
	cout << "\t\t\t\t\t\t" << "[9] Wyjdz" << "\t\t\t\n";
	cout << "========================================================================================================================\n";
}

void clearConsole() {
    system("cls");
}

void ConsumptionSummary_menu()
{
	if(building->number_of_devices != OLD_number_of_devices)
	{
		consumptionSUM_day_var = consumptionSUM_day(building);
		consumptionSUM_month_var = consumptionSUM_month(building);
		consumptionSUM_week_var = consumptionSUM_week(building);
		OLD_number_of_devices = building->number_of_devices;
	}

	clearConsole();
	while(1) {
		menuHeader("PODSUMOWANIE ZUZYCIA" + building->name);
		cout << "\n\n";
		cout << "ESTYMOWANE ZUZYCIE\nDZISIAJ: ";
		cout << consumptionSUM_day_var << " kWh\n\n";
		cout << "TYDZIEN: ";
		cout << consumptionSUM_week_var << " kWh\n\n";
		cout << "MIESIAC: ";
		cout << consumptionSUM_month_var << " kWh\n\n";
		menuFooter();

		char menu_choice = _getch();
	
		if(menu_choice == '8') {
			break;
		} else {
			clearConsole();
		}
	}
}

void Room_menu(int ID)
{
	clearConsole();
	while(1) {
		menuHeader(building->rooms.at(ID-1)->name);
		cout << "\n\n";
		building->rooms.at(ID - 1)->display();
		cout << "\n\n\n\n";
		menuFooter();

		char menu_choice = _getch();

		
		if (menu_choice == '8')
		{
			break;
		}
		else
		{
			clearConsole();
		}
	}
}

void RoomList_menu()
{
	clearConsole();
	while(1) {
		menuHeader("LISTA POMIESZCZEN - " + building_name);
		cout << "\n\n";
		cout << "Aby przejsc do pokoju wcisnij odpowiadajacy mu przycisk: \n";
		cout << "\n\n";
			building->display();
		cout << "\n\n\n\n";
		menuFooter();
	
		char menu_choice = _getch();
		menu_choice = menu_choice - '0'; // CONVERT CHAR TO INT
		for (int i = 1; i <= building->rooms.size(); i++)
		{

			if(menu_choice == building->rooms.at(i-1)->ID)
			{
				Room_menu(menu_choice);
				break;
			}
		}
			if (menu_choice == 8)
			{
				break;
			}
			else
			{
				clearConsole();
			}
	}

}

void print_data_to_file()
{
    const string filename = "Building_consumption.csv";
    bool file_exists = ifstream(filename).good();

    ofstream consumption_output(filename, ios::app); // tryb dopisywania

    if (!consumption_output.is_open()) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }

    // Dodaj nagłówek tylko jeśli plik jeszcze nie istnieje
    if (!file_exists) {
        consumption_output << "Timestamp,Day,Week,Month\n";
    }

    // Pobranie i sformatowanie aktualnego czasu
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Format: YYYY-MM-DD HH:MM:SS
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);

    // Zapis danych
    consumption_output << buffer << ","
                       << consumptionSUM_day_var << ","
                       << consumptionSUM_week_var << ","
                       << consumptionSUM_month_var << "\n";

    consumption_output.close();

	clearConsole();
	menuHeader("HISOTRIA ZUZYCIA" + building->name);
	cout << "\n\n\n";
	cout << "\t\t\t\t\t" << "POMYSLNIE EKSPORTOWANO DANE! ";
	cout << "\n\n\n";
	menuFooter_empty();
	this_thread::sleep_for(chrono::seconds(3));
}

void History_menu()
{
	//First check if we have to recalculate the consumption 
	// We do have to recalculate when new device was added since last simulation
	if(building->number_of_devices != OLD_number_of_devices)
	{
		consumptionSUM_day_var = consumptionSUM_day(building);
		consumptionSUM_month_var = consumptionSUM_month(building);
		consumptionSUM_week_var = consumptionSUM_week(building);
		OLD_number_of_devices = building->number_of_devices;
	}

	clearConsole();
	while(1) {
		menuHeader("HISOTRIA ZUZYCIA" + building->name);
		cout << "\n\n\n";
		cout << "[1] Eksportuj dane z aktualnego dnia tygodnia oraz miesiaca do pliku .csv\n\n";
		menuFooter();
		char menu_choice = _getch();

		if(menu_choice == '1') {
			print_data_to_file();
			clearConsole();
		} else if(menu_choice == '8') {
			break;
		} else {
			clearConsole();
		}
	}
}

void Notifications_menu()
{
	clearConsole();
	while(1) {
		menuHeader("POWIADOMIENIA" + building->name);
		cout << "\n\n\n\n";
		menuFooter();

		char menu_choice = _getch();
	
		if(menu_choice == '8') {
			break;
		} else {
			clearConsole();
		}
	}
}

void add_new_device()
{
	//1. Wybierz pokoj
	clearConsole();
	menuHeader("USTAWIENIA - " + building_name);
	cout << "\n\n";
	cout << "Wybierz pokoj docelowy: \n";
	cout << "\n\n";
		building->display();
	cout << "\n\n\n\n";
	menuFooter_empty();

	char menu_choice = _getch();
	menu_choice = menu_choice - '0'; // CONVERT CHAR TO INT
	for (auto room : building->rooms)
	{
		if(menu_choice == room->ID)
		{
				//2. Podaj wlasciwosci urzadzenia
			int power = 0;
			double hours = 0;
			string name, type;
			int id = countAllDevices(building);
			id += 1;
			
			clearConsole();
			menuHeader("USTAWIENIA - " + building->name);
			cout << "\n\n";
			cout << "\t\t\t" << room->name << endl;
			cout << "\t\t\tPodaj nazwe urzadzenia [" << id << "] : ";
			cout << "\n\n";
			menuFooter_empty();
			cursorLine_UP(5);

			name = clientInput();

			clearConsole();
			menuHeader("USTAWIENIA - " + building->name);
			cout << "\n\n";
			cout << "\t\t\t" << room->name << endl;
			cout << "\t\t\tPodaj moc (W) urzadzenia [" << id << "] : ";
			cout << "\n\n";
			menuFooter_empty();
			cursorLine_UP(5);

			power = stoi(clientInput());

			clearConsole();
			menuHeader("USTAWIENIA - " + building->name);
			cout << "\n\n";
			cout << "\t\t\t" << room->name << endl;
			cout << "\t\t\tPodaj czas pracy na dobe urzadzenia (h) [" << id << "] : ";
			cout << "\n\n";
			menuFooter_empty();
			cursorLine_UP(5);
			cout << "\t\t";

			hours = stod(clientInput());

			clearConsole();
			menuHeader("USTAWIENIA - " + building->name);
			cout << "\n\n";
			cout << "\t\t\t" << room->name << endl;
			cout << "\t\t\tPodaj typ urzadzenia np. AGD [" << id << "] : ";
			cout << "\n\n";
			menuFooter_empty();
			cursorLine_UP(5);
			cout << "\t";

			type = clientInput();

			Device *newDevice = builder
									.setID(id)
									.setName(name)
									.setPower(power)
									.setHours(hours)
									.setType(type)
									.build();

			room->add(newDevice);
			building->number_of_devices += 1;
			break;
		}
	}

	//komunikat o pomyslnym dodaniu urzadzenia
	clearConsole();
	menuHeader("USTAWIENIA - " + building->name);
	cout << "\n\n\n";
	cout << "\t\t\t\t" << "POMYSLNIE DODANO URZADZENIE! ";
	cout << "\n\n\n";
	menuFooter_empty();

	this_thread::sleep_for(chrono::seconds(3));
}

void remove_device() 
{
	clearConsole();
	menuHeader("USTAWIENIA - " + building->name);
	cout << "\n\n";
	cout << "Wybierz pokoj docelowy: \n";
	cout << "\n\n";
		building->display();
	cout << "\n\n\n\n";
	menuFooter_empty();

	char menu_choice = _getch();
	menu_choice = menu_choice - '0'; // CONVERT CHAR TO INT
	for (auto room : building->rooms)
	{
		if(menu_choice == room->ID)
		{
			clearConsole();
			menuHeader("USTAWIENIA - " + building->name);
			cout << "\n\n";
			cout << "Wybierz urzadzenie, ktore chcesz usunac: \n";
			room->display();
			cout << "\n\n\n\n";
			menuFooter_empty();
			vector<Component*> devices_in_room = room->getChildren();

			char menu_choice = _getch();
			menu_choice = menu_choice - '0'; // CONVERT CHAR TO INT

			room->remove(devices_in_room.at(menu_choice-1));
			building->number_of_devices -= 1;
			break;
		}
	}

		//komunikat o pomyslnym usunieciu urzadzenia
		clearConsole();
		menuHeader("USTAWIENIA - " + building->name);
		cout << "\n\n\n";
		cout << "\t\t\t\t\t" << "POMYSLNIE USUNIETO URZADZENIE! ";
		cout << "\n\n\n";
		menuFooter_empty();
		this_thread::sleep_for(chrono::seconds(3));
}

void add_new_room()
{
	clearConsole();
	menuHeader("USTAWIENIA - " + building_name);
	cout << "\n\n";
	cout << "Podaj nazwe nowego pokoju: \n";
	cout << "\n\n";
	menuFooter_empty();
	cursorLine_UP(6);
	cout << "\r\t\t\t\t";

	string room_name = clientInput();

	Room *newRoom = new Room(room_name, building->rooms.size()+1);
	building->add(newRoom);

	clearConsole();
	menuHeader("USTAWIENIA - " + building->name);
	cout << "\n\n\n";
	cout << "\t\t\t\t\t" << "POMYSLNIE DODANO POMIESZCZENIE! ";
	cout << "\n\n\n";
	menuFooter_empty();
	this_thread::sleep_for(chrono::seconds(3));
}

void remove_room()
{
	clearConsole();
	menuHeader("USTAWIENIA - " + building_name);
	cout << "\n\n";
	cout << "Wybierz pokoj ktory chcesz usunac: \n";
	cout << "\n\n";
		building->display();
	cout << "\n\n\n\n";
	menuFooter();

	char menu_choice = _getch();
	menu_choice = menu_choice - '0'; // CONVERT CHAR TO INT

	if(menu_choice == '8')
		return;

	vector<Component *> rooms_list = building->getChildren();

	building->remove(rooms_list.at(menu_choice - 1));

	clearConsole();
	menuHeader("USTAWIENIA - " + building->name);
	cout << "\n\n\n";
	cout << "\t\t\t\t\t" << "POMYSLNIE USUNIETO POMIESZCZENIE! ";
	cout << "\n\n\n";
	menuFooter_empty();
	this_thread::sleep_for(chrono::seconds(3));
}

void Settings_menu()
{
	clearConsole();
	while(1) {
		menuHeader("USTAWIENIA - " + building->name);
		cout << "\n\n\n";
		cout << "[1] Dodaj nowe urzadzenie\n";
		cout << "[2] Usun urzadzenie\n";
		cout << "[3] Dodaj nowe pomieszczenie\n";
		cout << "[4] Usun pomiesczenie\n\n\n";
		menuFooter();

		char menu_choice = _getch();

		if(menu_choice == '1') {
			add_new_device();
			clearConsole();
		} else if (menu_choice == '2') {
			remove_device();
			clearConsole();
		} else if (menu_choice == '3') {
			add_new_room();
			clearConsole();
		} else if (menu_choice == '4') {
			remove_room();
			clearConsole();
		} else if(menu_choice == '8') {
			break;
		} else {
			clearConsole();
		}
	}
}

char Main_menu() {

	clearConsole();

	menuHeader("SYSTEM MONITORINGU ENERGII - " + building_name);

	cout << "\t\t\t\t\t\t[1] Podsumowanie zuzycia\n";
	cout << "\t\t\t\t\t\t[2] Lista pomieszczen\n";
	cout << "\t\t\t\t\t\t[3] Historia zuzycia\n";
	cout << "\t\t\t\t\t\t[4] Powiadomienia\n";
	cout << "\t\t\t\t\t\t[5] Ustawienia\n";
	cout << "\t\t\t\t\t\t[6] Wyjscie\n";
	cout << "\n\n\n";

	cout << "\t\t\t\t\t\t----------------------\n";
	cout << "\t\t\t\t\t\tOSTATNIE POWIADOMIENIA\n";
	cout << "\t\t\t\t\t\t----------------------\n";
	cout << "\t\t\t\t\t\tTutaj beda powiadomienia...\n";
	cout << "\t\t\t\t\t\tTutaj beda powiadomienia...\n";
	cout << "\t\t\t\t\t\tTutaj beda powiadomienia...\n";
	cout << "\t\t\t\t\t\t----------------------\n\n\n";

	char menu_choice = _getch();
	return menu_choice;
}


string Starting_menu1()
{
	clearConsole();
	menuHeader("EKRAN STARTOWY");
	cout << "\n\n";
	cout << "\t\t\tPodaj nazwe swojego budynku: \n\n";
	menuFooter_starting();
	cursorLine_UP(5);
	string building_name = clientInput();

	return building_name;
}

void Starting_menu2()
{
	int number_of_rooms = 1;

	do {
	clearConsole();
	menuHeader("EKRAN STARTOWY");
	cout << "\n\n";
	cout << "\t\t\tPodaj liczbe pokoi: \n\n";
	menuFooter_starting();
	cursorLine_UP(5);

	if(number_of_rooms < 0 || number_of_rooms > 2000) {
		cout << "\n\a\t\t\tLiczba pokoi spoza zakresu! Prosze wpisac liczbe od 0 do 2000...\r";
		cursorLine_UP(1);
	}

	cin >> number_of_rooms;

	// Sprawdzenie błędu wejścia (np. wpisano 'a')
	if (cin.fail()) {
		cin.clear();                    // czyści flagę błędu
		cin.ignore(10000, '\n');        // ignoruje resztę linii
		number_of_rooms = -1;           // ustawia na niepoprawną wartość, żeby pętla trwała
	} else {
		cin.ignore(10000, '\n');        // czyści bufor (np. Enter po liczbie)
	}


	} while(number_of_rooms < 0 || number_of_rooms > 2000);


	for (int i = 1; i <= number_of_rooms; i++)
	{
		clearConsole();
		menuHeader("EKRAN STARTOWY");
		cout << "\n\n";
		cout << "\t\t\tPodaj nazwe pokoju " << i << ": \n\n";
		menuFooter_starting();
		cursorLine_UP(5);

		string room_name = clientInput();

		Room *newRoom = new Room(room_name, i);
		building->add(newRoom);
	}
}


void Starting_menu3() 
{
	int number_of_devices = 0;
	int number_of_rooms = building->rooms.size();

	for (auto room : building->rooms)
	{
		do {
			clearConsole();
			menuHeader("EKRAN STARTOWY");
			cout << "\n\n";
			cout << "\t\t\tPodaj liczbe urzadzen w pokoju - " << room->name << ": ";
			cout << "\n\n";
			menuFooter_starting();
			cursorLine_UP(5);
			cout << "\t\t";

			if(number_of_devices < 0 || number_of_devices > 15)
			{
				cout << "\nWpisano zla liczbe!! Zakres ilosci urzadzen w pomieszczeniu to 0 do 15....\r";
				cursorLine_UP(1);
				cout << "\t";
			}

			// Sprawdzenie błędu wejścia (np. wpisano 'a')
			cin >> number_of_devices;
			if (cin.fail()) {
				cin.clear();                    // czyści flagę błędu
				cin.ignore(10000, '\n');        // ignoruje resztę linii
				number_of_devices = -1;           // ustawia na niepoprawną wartość, żeby pętla trwała
			} else {
				cin.ignore(10000, '\n');        // czyści bufor (np. Enter po liczbie)
			}

		} while (number_of_devices < 0 || number_of_devices > 15);
		
		room->number_of_devices = number_of_devices;

		int id = 0, power = 0;
		double hours = 0;
		string name, type;

		for (int i = 0; i < number_of_devices; i++)
		{
			id += 1;
	
			clearConsole();
			menuHeader("EKRAN STARTOWY");
			cout << "\n\n";
			cout << "\t\t\t" << room->name << endl;
			cout << "\t\t\tPodaj nazwe urzadzenia [" << id << "] : ";
			cout << "\n\n";
			menuFooter_starting();
			cursorLine_UP(5);
	
			name = clientInput();
	
			clearConsole();
			menuHeader("EKRAN STARTOWY");
			cout << "\n\n";
			cout << "\t\t\t" << room->name << endl;
			cout << "\t\t\tPodaj moc (W) urzadzenia [" << id << "] : ";
			cout << "\n\n";
			menuFooter_starting();
			cursorLine_UP(5);
	
			power = stoi(clientInput());
	
			clearConsole();
			menuHeader("EKRAN STARTOWY");
			cout << "\n\n";
			cout << "\t\t\t" << room->name << endl;
			cout << "\t\t\tPodaj czas pracy na dobe urzadzenia (h) [" << id << "] : ";
			cout << "\n\n";
			menuFooter_starting();
			cursorLine_UP(5);
			cout << "\t\t";
	
			hours = stod(clientInput());
	
			clearConsole();
			menuHeader("EKRAN STARTOWY");
			cout << "\n\n";
			cout << "\t\t\t" << room->name << endl;
			cout << "\t\t\tPodaj typ urzadzenia np. AGD [" << id << "] : ";
			cout << "\n\n";
			menuFooter_starting();
			cursorLine_UP(5);
			cout << "\t";
	
			type = clientInput();
	
			Device *newDevice = builder
									.setID(id)
									.setName(name)
									.setPower(power)
									.setHours(hours)
									.setType(type)
									.build();
	
			room->add(newDevice);
			building->number_of_devices += 1;
		}

	}
}




