#pragma once

#include <iostream>
using namespace std;

#include "Component.h"
#include "Device.h"

// Klasa DeviceBuilder - służąca do dodawania nowych urządzeń
class DeviceBuilder {
    private:
        Device* device;
    
    public:
        DeviceBuilder();

        ~DeviceBuilder();

        // Nowe urządzenie
        void Reset();

        // Metody budowniczego
        DeviceBuilder &setName(const string &name);

        DeviceBuilder &setPower(int power);

        DeviceBuilder &setHours(int hours);

        DeviceBuilder &setType(const string &type);

        // Budowanie urządzenia
        Device *build();
    };