#include "tv_control.h"
#include <iostream>
#include <cassert>

void TVControl::Info(TV& tv) {
	if (tv.IsTurnedOn()) {
		std::cout << "TV is turned on. Channel is " << tv.GetCurrentChannel() << "\n";
	}
	else {
		std::cout << "TV is turned off\n";
	}
}
void TVControl::TurnOn(TV& tv) {
	tv.TurnOn();
	std::cout << "Turning on\n";
}
void TVControl::TurnOff(TV& tv) {
	tv.TurnOff();
	std::cout << "TV is turned off\n";
}
void TVControl::SelectChannel(TV& tv) {
	int channel;
	assert(std::cin >> channel);
	
	if (!tv.IsTurnedOn()) {
		std::cout << "TV is not turned on\n";
	}
	else if (!tv.SelectChannel(channel)) {
		std::cout << "Invalid channel\n";
	}
	else {
		std::cout << "Channel selected\n";
	}
}

bool TVControl::ReadAndApplyCommand(TV& tv) {
	std::string command;
	if (!(std::cin >> command) || command == "Exit") {
		return false;
	}
	if (command == "Info") {
		Info(tv);
	}
	else if (command == "TurnOn") {
		TurnOn(tv);
	}
	else if (command == "TurnOff") {
		TurnOff(tv);
	}
	else if (command == "SelectChannel") {
		SelectChannel(tv);
	}
	return true;
}