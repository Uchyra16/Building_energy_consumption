#pragma once

#include <iostream>
using namespace std;

#include "Component.h"
#include "Device.h"


void listAllDevices(Component *component);

int countAllDevices(Component *component);

double consumptionSUM_day(Component *component);

double consumptionSUM_week(Component *component);

double consumptionSUM_month(Component *component);