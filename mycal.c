#include <stdbool.h>
#include <stdio.h>
#include "calendar.h"

char const *formatted_month_names[] = {
	"     December",
	"     January",
	"     February",
	"      March",
	"      April",
	"       May",
	"       June",
	"       July",
	"      August",
	"    September",
	"     October",
	"     November",
	"     December",
};

char const *day_cells[] = {
	"  ", "  ", "  ", "  ", "  ", "  ",
	" 1", " 2", " 3", " 4", " 5", " 6", " 7",
	" 8", " 9", "10", "11", "12", "13", "14",
	"15", "16", "17", "18", "19", "20", "21",
	"22", "23", "24", "25", "26", "27", "28",
	"29", "30", "31",
};

int main(void) {
	int const year = 2015;
	int const month = 2;
	dow_t first_dow = calc_dow(year, month, 1);
	int cell_offset = 13 - first_dow;
	char const *(*cells)[7] =
		(char const *(*)[7])(day_cells + cell_offset);

	printf("%s %d\n", formatted_month_names[month], year);
	puts(" Su Mo Tu We Th Fr Sa");
	for (int week = 0; week < 4; ++week) {
		for (int i = 0; i < 7; ++i) {
			printf(" %s", cells[week][i]);
		}
		printf("\n");
	}
	return 0;
}
