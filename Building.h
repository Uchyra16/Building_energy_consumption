#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#include "Component.h"
// Klasa Building - Kompozyt(Kontener) posiada elementy podrzędne - liście lub inne kontenery w tym przypadku urządzenia lub pokoje
// Kontener komunikuje się z elementami podrzednymi tylko poprzez interfejs komponentu
// Kontener deleguje prace do swoich podelementów
class Building : public Component {
    private:
        vector<Component*> rooms;
    
    public:
        Building(string n);

        ~Building();

        void add(Component *room) override;

        void remove(Component *room) override;

        void display();
    };