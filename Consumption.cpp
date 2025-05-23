#include "Consumption.h"

void listAllDevices(Component* component) {
    if (!component) return;

    // Spróbuj zrzutować na Device
    Device* device = dynamic_cast<Device*>(component);
    if (device != nullptr) {
        cout << device->name;
		cout << " - Estymowane zuzycie: ";
		cout << device->getEnergyConsumption() << " kWh\n\n";
		return;
    }

    // Przejdź do dzieci komponentu
    for (Component* child : component->getChildren()) {
        listAllDevices(child);
    }
}

int countAllDevices(Component* component) {
    if (!component) return 0;

    int count = 0;

    // Sprawdź, czy to Device
    Device* device = dynamic_cast<Device*>(component);
    if (device != nullptr) {
        return 1; // To jest urządzenie – liczymy je i NIE przechodzimy do dzieci (bo Device nie ma dzieci?)
    }

    // Przejdź do dzieci
    for (Component* child : component->getChildren()) {
        count += countAllDevices(child);
    }

    return count;
}


double consumptionSUM_day(Component* component) {
    if (!component) return 0.0;

	double result = 0;

	// Spróbuj zrzutować na Device
    Device* device = dynamic_cast<Device*>(component);
    if (device != nullptr) {
		result += device->simulateDay();
    }

    // Przejdź do dzieci komponentu
    for (Component* child : component->getChildren()) {
        result += consumptionSUM_day(child);
    }

	return result;
}

double consumptionSUM_week(Component* component) {
    if (!component) return 0.0;

	double result = 0;

	// Spróbuj zrzutować na Device
    Device* device = dynamic_cast<Device*>(component);
    if (device != nullptr) {
		result += device->simulateWeek();
    }

    // Przejdź do dzieci komponentu
    for (Component* child : component->getChildren()) {
        result += consumptionSUM_week(child);
    }

	return result;
}

double consumptionSUM_month(Component* component) {
    if (!component) return 0.0;

	double result = 0;

	// Spróbuj zrzutować na Device
    Device* device = dynamic_cast<Device*>(component);
    if (device != nullptr) {
		result += device->simulateMonth();
    }

    // Przejdź do dzieci komponentu
    for (Component* child : component->getChildren()) {
        result += consumptionSUM_month(child);
    }

	return result;
}

