#include "menu.h"

//Variables from other files:
extern bool running;
extern string building_name;
int menu_choice = 0;
extern Building *building;

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
	clearConsole();
	while(1) {
		menuHeader("PODSUMOWANIE ZUZYCIA");
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

void History_menu()
{
	clearConsole();
	while(1) {
		menuHeader("HISOTRIA ZUZYCIA");
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

void Notifications_menu()
{
	clearConsole();
	while(1) {
		menuHeader("POWIADOMIENIA");
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

void Settings_menu()
{
	clearConsole();
	while(1) {
		menuHeader("POWIADOMIENIA");
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

	if(number_of_rooms <= 0 || number_of_rooms > 2000) {
		cout << "\n\t\t\tLiczba pokoi spoza zakresu! Prosze wpisac liczbe od 1 do 2000...\r";
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


	} while(number_of_rooms < 1 || number_of_rooms > 2000);


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
	}
}

void Starting_menu4()
{

}


