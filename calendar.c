#include <stdbool.h>
#include "calendar.h"

bool is_leap_year(int year) {
	if (year % 100 == 0) {
		return (year % 400 == 0);
	}
	return (year % 4 == 0);
}

dow_t calc_dow(int year, int month, int day) {
	if (month <= 2) {
		year -= 1;
		month += 12;
	}
	int const C = year / 100;
	int const Y = year % 100;

	int const score = day + (26*(month+1)/10) + Y + (Y/4) + 5*C + (C/4);
	return (score + 5) % 7 + 1;
}
