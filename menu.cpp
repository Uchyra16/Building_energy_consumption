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
		}
	}
}

int menu_choice = 0;
char Starting_menu() {

	clearConsole();

	menuHeader("SYSTEM MONITORINGU ENERGII");

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