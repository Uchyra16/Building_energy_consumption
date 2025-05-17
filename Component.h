#pragma once

#include <iostream>
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
    
        virtual ~Component() {
            cout << "Destructor has been called!...\n";
        }
    };