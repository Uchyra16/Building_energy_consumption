#include "DeviceBuilder.h"
    
DeviceBuilder::DeviceBuilder() {
    this->Reset();
}

DeviceBuilder::~DeviceBuilder() {
    delete device;
}

// Nowe urządzenie
void DeviceBuilder::Reset() {
    delete this->device;
    this->device = new Device();
}

// Metody budowniczego

DeviceBuilder& DeviceBuilder::setID(int ID) {
    this->device->setID(ID);
    return *this;
}

DeviceBuilder& DeviceBuilder::setName(const string& name) {
    this->device->setName(name);
    return *this;
}

DeviceBuilder& DeviceBuilder::setPower(int power) {
    this->device->setPower(power);
    return *this;
}

DeviceBuilder& DeviceBuilder::setHours(double hours) {
    this->device->setHours(hours);
    return *this;
}

DeviceBuilder& DeviceBuilder::setType(const string& type) {
    this->device->setType(type);
    return *this;
}

// Budowanie urządzenia
Device* DeviceBuilder::build() {
    Device* result = this->device;
    this->device = nullptr;	
    this->Reset();
    return result;
}
    
   