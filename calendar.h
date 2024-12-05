#ifndef CALENDAR_H
#define CALENDAR_H

bool is_leap_year(int year);

/* ISO 8601 day of week */
enum dow {
	SUNDAY = 1,
	MONDAY = 2,
	TUESDAY = 3,
	WEDNESDAY = 4,
	THURSDAY = 5,
	FRIDAY = 6,
	SATURDAY = 7,
};
typedef enum dow dow_t;

dow_t calc_dow(int year, int month, int day);

#endif
