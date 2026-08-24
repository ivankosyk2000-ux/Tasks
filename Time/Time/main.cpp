#include <cassert>
#include <iostream>
#include <string>
class Time {
public:
	// Кількість годин у добі.
	inline static const int HOURS_PER_DAY = 24;
	// Кількість хвилин у годині.
	inline static const int MINUTES_PER_HOUR = 60;
	// Кількість секунд у хвилині.
	inline static const int SECONDS_PER_MINUTE = 60;
	// Кількість секунд у годині.
	inline static const int SECONDS_PER_HOUR = SECONDS_PER_MINUTE * MINUTES_PER_HOUR;
	// Кількість секунд у добі.
	inline static const int SECONDS_PER_DAY = SECONDS_PER_HOUR * HOURS_PER_DAY;
	// Змінює поточне значення часу.
	void SetTime(int hours, int minutes, int seconds) {
		time_offset_ = hours * SECONDS_PER_HOUR + minutes * SECONDS_PER_MINUTE + seconds;
	}
	// Повертає кількість секунд (від 0 до 59).
	int GetSeconds() const{
		return time_offset_ % SECONDS_PER_MINUTE;
	}
	// Повертає кількість хвилин (від 0 до 59).
	int GetMinutes() const{
		// time_offset_ / SECONDS_PER_MINUTE - це кількість хвилин,
		// що минули від початку доби.
		// Взявши остачу від ділення цього числа на 60, отримаємо кількість хвилин,
		// що минули від початку поточної години.
		return (time_offset_ / SECONDS_PER_MINUTE) % MINUTES_PER_HOUR;
	}
	// Повертає кількість годин (від 0 до 23).
	int GetHours() const{
		return time_offset_ / SECONDS_PER_HOUR;
	}
	// Повертає різницю між моментами часу to і from у секундах.
	// Передбачається, що обидва моменти відбуваються в межах однієї доби.
	// Поточний час не змінюється.
	static int GetDistance(const Time& from, const Time& to) {
		return to.time_offset_ - from.time_offset_;
	}
	// Збільшує поточний час на задану кількість секунд.
	// Величина offset може бути додатною, від'ємною або нульовою.
	void AddSeconds(int offset) {
		// Використовуємо прийом (x % N + N) % N.
		int new_time = (time_offset_ + offset) % SECONDS_PER_DAY;
		time_offset_ = (new_time + SECONDS_PER_DAY) % SECONDS_PER_DAY;
	}
private:
	// Кількість секунд, що минули від початку доби.
	int time_offset_ = 0;
};
using namespace std::literals;
std::string MakeTwoDigitNumber(int n) {
	auto s = std::to_string(n);
	return n < 10 ? "0"s + s : s;
}
std::string ToString(Time t) {
	return MakeTwoDigitNumber(t.GetHours()) + ":"s + MakeTwoDigitNumber(t.GetMinutes()) + ":"s
		+ MakeTwoDigitNumber(t.GetSeconds());
}
int main() {
	Time t, t1, t2;
	// За замовчуванням час дорівнює 00:00:00.
	assert((t.GetHours() == 0) && (t.GetMinutes() == 0) && (t.GetSeconds() == 0));
	t.SetTime(23, 59, 40);
	t.AddSeconds(25);
	assert(ToString(t) == "00:00:05"s);
	// Якщо додати 25 секунд до 23:59:40, відбудеться
	// перехід через північ, і на годиннику буде час 00:00:05.
	t.SetTime(0, 15, 10);
	t.AddSeconds(-911); // 911 секунд = 00:15:11.
	assert(ToString(t) == "23:59:59"s);
	// Якщо відняти 911 секунд від 00:15:10
	// (910 секунд від початку доби), відбудеться перехід через
	// межу доби, і на годиннику буде 23:59:59.
	t.SetTime(23, 59, 59);
	assert(ToString(t) == "23:59:59"s);
	t.SetTime(0, 0, 0);
	assert(ToString(t) == "00:00:00"s);
	// 00:00:00 + 59 секунд = 00:00:59.
	t.AddSeconds(59);
	assert((ToString(t) == "00:00:59"s));
	// 00:00:59 + 3 секунди = 00:01:02.
	t.AddSeconds(3);
	assert((ToString(t) == "00:01:02"s));
	// 00:01:02 + 59 хвилин = 01:00:02.
	t.AddSeconds(59 * Time::SECONDS_PER_MINUTE);
	assert((ToString(t) == "01:00:02"s));
	t.SetTime(23, 59, 59);
	// 23:59:59 + 01:01:01 = 01:01:00.
	t.AddSeconds(Time::SECONDS_PER_HOUR + Time::SECONDS_PER_MINUTE + 1);
	assert((ToString(t) == "01:01:00"s));
	// 01:01:00 + (-01:01:01) = 23:59:59.
	t.AddSeconds(-(Time::SECONDS_PER_HOUR + Time::SECONDS_PER_MINUTE + 1));
	assert((ToString(t) == "23:59:59"s));
	// Коли додаємо або віднімаємо секунд більше, ніж є в добі,
	// це аналогічно додаванню остачі від ділення на N, де N - кількість секунд у добі.
	// 23:59:59 + 30:00:00 = 23:59:59 + 6:00:00 = 05:59:59.
	t.AddSeconds(30 * Time::SECONDS_PER_HOUR);
	assert((ToString(t) == "05:59:59"s));
	t1.SetTime(6, 1, 1);
	// 06:01:01 - 05:59:59 = 62 секунди.
	assert(Time::GetDistance(t, t1) == 62);
	// 05:59:59 - 06:01:01 = -62 секунди.
	assert(Time::GetDistance(t1, t) == -62);
	// Між 12:00:00 і 7:40:00 минуло 4 години 20 хвилин.
	// У секундах це 3600 * 4 + 20 * 60 = 15600.
	t1.SetTime(7, 40, 0);
	t2.SetTime(12, 0, 0);
	assert(Time::GetDistance(t1, t2) == 15600);
	// Між 12:00:00 і 7:40:00 минуло 4 години 20 хвилин,
	// або 3600 * 4 + 20 * 60 = 15600 секунд. Оскільки віднімали
	// від першого часу другий, то 15600 буде зі знаком мінус.
	t1.SetTime(7, 40, 0);
	t2.SetTime(12, 0, 0);
	assert(Time::GetDistance(t2, t1) == -15600);
	std::cout << "Program testing OK"s << std::endl;
}