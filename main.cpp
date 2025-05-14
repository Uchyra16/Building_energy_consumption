#include <iostream>
#include <vector>
using namespace std;

//Aplikacja estymujaca zuzycie energii w budynku


/**
 * The base Component class declares common operations for both simple and
 * complex objects of a composition.
 */
//class Component {
//	public:
//		string name;
//		
//		virtual void display() {}
//		
//};
//
//
//class Building : public Component {
//	private:
//		vector<Component*> rooms;
//		
//	public:
//		Building(string n) {
//			name = n;
//		}
//		void add(Component* component) {
//			rooms.push_back(component);
//		}
//		
//
//		void traverse_rooms() {
//			for(int i = 0; i < rooms.size(); i++) {
//			//	cout << "Room: " << rooms.at(i)->display() << endl;
//			}
//		}
//};
//
//class Room: public Component {
//	
//	public:
//	
//		Room(string n) {
//			name = n;
//		}
//		
//		void display() override {
//			cout << "Pokoj: " << name << endl;
//			cout << "Nie ma na razie urzdzen";
//		}
//};






int main() {
	
	cout << "Aplikacja estymujaca zuzycie energii w budynku";
	
//	Room* pokoj1 = new Room("Kuchnia");
//	
//	Building* building1 = new Building("Dom");
//	
//	building1->add(pokoj1);
//
//	
//	building1->traverse_rooms();
//	
//	delete pokoj1;
//	delete building1;
//	
	return 0;
}