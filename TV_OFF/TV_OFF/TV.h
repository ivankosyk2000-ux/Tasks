#pragma once

class TV {
private:
	bool is_on_ = false;
	int current_channel_ = 1;
public:
	void TurnOn();
	void TurnOff();
	bool IsTurnedOn() const;
	bool SelectChannel(int channel);
	int GetCurrentChannel() const;
};