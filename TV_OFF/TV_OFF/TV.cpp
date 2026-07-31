#include "TV.h"

void TV::TurnOn() {
	is_on_ = true;
}
void TV::TurnOff() {
	is_on_ = false;
}
bool TV::IsTurnedOn() const {
	return is_on_;
}
bool TV::SelectChannel(int channel) {
	if (!is_on_ || channel < 1 || channel>99) {
		return false;
	}
	current_channel_ = channel;
	return true;
}
int TV::GetCurrentChannel() const {
	if (!is_on_) {
		return 0;
	}
	return current_channel_;
}