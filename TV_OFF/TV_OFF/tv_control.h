#pragma once
#include "TV.h"
#include <string>

class TVControl {
public:
	static bool ReadAndApplyCommand(TV& tv);
private:
	static void Info(TV& tv);
	static void TurnOn(TV& tv);
	static void TurnOff(TV& tv);
	static void SelectChannel(TV& tv);
};