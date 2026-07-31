#pragma once
const int MIN_CHANNEL = 1;
const int MAX_CHANNEL = 99;

class TV {
private:
	bool is_turned_on_ = false;
	int current_channel_ = 1;
public:
	void TurnOn();
	void TurnOff();
	bool IsTurnedOn() const;
	bool SelectChannel(int channel);
	int GetCurrentChannel() const;
};