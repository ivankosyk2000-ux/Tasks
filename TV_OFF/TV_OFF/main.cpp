#include<iostream>
#include <cassert>
#include "TV.h"
using namespace std;

int main() {
	//Тест 1. Перевіряє, що телевізор за замовчуванням вимкнений.
		//C++ • Класи та об’єкти
		TV tv1;
	assert(!tv1.IsTurnedOn());

	//Тест 2. Перевіряє роботу методів TurnOn і TurnOff.
		TV tv2;
	assert(!tv2.IsTurnedOn());
	tv2.TurnOn();
	assert(tv2.IsTurnedOn());
	tv2.TurnOff();
	assert(!tv2.IsTurnedOn());

	//Тест 3. Перевіряє роботу методу GetCurrentChannel.
		TV tv3;
	assert(!tv3.IsTurnedOn());
	assert(tv3.GetCurrentChannel() == 0);
	tv3.TurnOn();
	assert(tv3.GetCurrentChannel() == 1);
	tv3.TurnOff();
	assert(tv3.GetCurrentChannel() == 0);

	//Тест 4. Перевіряє перемикання різних каналів.
		TV tv4;
	tv4.TurnOn();
	for (auto i = 0; i < 10; ++i) {
		int channel = (71 * i) % MAX_CHANNEL + 1;
		assert(tv4.SelectChannel(channel));
		assert(tv4.GetCurrentChannel() == channel);
	}
	//Тест 5. Перевіряє, що канал не буде увімкнено, якщо телевізор вимкнений.
		TV tv5;
	tv5.TurnOff();
	int channel = 50;
	assert(!tv5.SelectChannel(channel));
	assert(tv5.GetCurrentChannel() == 0);

	//Тест 6. Перевіряє перемикання різних каналів і їхнє збереження після вимкнення телевізора.
		TV tv6;
	tv6.TurnOn();
	for (auto i = 0; i < 10; ++i) {
		int channel = (641 * i) % MAX_CHANNEL + 1;
		assert(tv6.SelectChannel(channel));
		assert(tv6.GetCurrentChannel() == channel);
		tv6.TurnOff();
		assert(!tv6.IsTurnedOn());
		assert(tv6.GetCurrentChannel() == 0);
		tv6.TurnOn();
		assert(tv6.GetCurrentChannel() == channel);
	}
}