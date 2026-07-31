#include "TV.h"

void TV::TurnOn() {
	is_turned_on_ = true;
}
void TV::TurnOff() {
	is_turned_on_ = false;
}
bool TV::IsTurnedOn() const {
	return is_turned_on_;
}
bool TV::SelectChannel(int channel) {
	if (!IsTurnedOn() || channel < MIN_CHANNEL || channel > MAX_CHANNEL) {
		return false;
	}
	current_channel_ = channel;
	return true;
}
int TV::GetCurrentChannel() const {
	return IsTurnedOn() ? current_channel_ : 0;
}