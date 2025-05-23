#pragma once

#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
#include "Building.h"
#include "Device.h"
#include "DeviceBuilder.h"
#include "Room.h"
#include "Consumption.h"
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;


// MENU WINDOWS
string Starting_menu1();

void Starting_menu2();

void Starting_menu3();

char Main_menu();

void ConsumptionSummary_menu();

void Room_menu(int ID);

void RoomList_menu();

void History_menu();

void Notifications_menu();

void Settings_menu();

void menuFooter_starting();

// MENU INTERFACE 

void menuHeader(string text);

void cursorLine_UP(int num_of_lines);

void menuFooter();

void menuFooter_empty();

void clearConsole();

string clientInput();

// OTHER FUNCTIONS
void print_data_to_file();
