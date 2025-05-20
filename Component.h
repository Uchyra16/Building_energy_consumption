#pragma once

#include <iostream>
#include <vector>
using namespace std;

//Klasa bazowa struktury kompozytowej - drzewiastej
class Component {
    public:
        string name;
        int ID;
        int number_of_devices;

        virtual void add(Component *component) {}
        virtual void remove(Component *component) {}
        virtual void display() {}
        virtual std::vector<Component*> getChildren() { return {}; }

        virtual ~Component() {
            cout << "Destructor has been called!...\n";
        }
    };