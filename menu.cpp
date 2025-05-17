#include "menu.h"


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

void RoomList_menu()
{
	clearConsole();
	while(1) {
		menuHeader("LISTA POMIESZCZEN");
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
extern string building_name;
int menu_choice = 0;
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

extern bool running;
string Starting_menu1()
{
	string building_name = "";

	clearConsole();
	menuHeader("EKRAN STARTOWY");
	cout << "\n\n";
	cout << "\t\t\tPodaj nazwe swojego budynku: \n\n";
	menuFooter_starting();
	cout << "\033[A"<< "\033[A"<< "\033[A"<< "\033[A"<< "\033[A" << "\t\t\t\t\t\t\t";

	while(1) {
		char c = _getch();

		if(c == '9') {
			running = false;
			break;
		} else if (c == '\r') {	//Enter potwierdza wpisana nazwe
			cout << endl;
			break;
		}else if (c == '\b' && !building_name.empty()) {  // Backspace obsługa
			building_name.pop_back();
			cout << "\b \b"; // usuń z konsoli
			continue;
		}
		
		// Wpisywanie znaku
		building_name += c;
		cout << c;
	}

	return building_name;
}

void Starting_menu2()
{
	int number_of_rooms = 0;

	menuHeader("EKRAN STARTOWY");
	cout << "\n\n";
	cout << "\t\t\tPodaj liczbe pokoi: \n\n";
	menuFooter_starting();
	cout << "\033[A"<< "\033[A"<< "\033[A"<< "\033[A"<< "\033[A" << "\t\t\t\t\t\t\t";
	cin >> number_of_rooms;

	for (int i = 0; i < number_of_rooms; i++)
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
		Room *newRoom = new Room(input);
	}
}
