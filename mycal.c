#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "calendar.h"
#include "util.h"

char const *formatted_month_names[] = {
	"    December",
	"    January",
	"    February",
	"     March",
	"     April",
	"      May",
	"      June",
	"      July",
	"     August",
	"   September",
	"    October",
	"    November",
	"    December",
};

char const *day_cells[] = {
	"  ", "  ", "  ", "  ", "  ", "  ",
	" 1", " 2", " 3", " 4", " 5", " 6", " 7",
	" 8", " 9", "10", "11", "12", "13", "14",
	"15", "16", "17", "18", "19", "20", "21",
	"22", "23", "24", "25", "26", "27", "28",
	"29", "30", "31",
};

typedef char const *(*cell_array_t)[7];

cell_array_t get_cell_array(int year, int month) {
	dow_t const first_dow = calc_dow(year, month, 1);
	int const cell_offset = (13 - first_dow) % 7;
	return (cell_array_t)(day_cells + cell_offset);
}

void show_calendar(int year, int month){
	printf("%s %d\n", formatted_month_names[month], year);
	printf("Su Mo Tu We Th Fr Sa\n");

	cell_array_t cells = get_cell_array(year, month);
	char const **cell_end = day_cells + 6 + nday_in_month(year, month);
	for (int week = 0; week < 6; ++week) {
		int const i_end = min_i(7, cell_end - &cells[week][0]);
		for (int i = 0; i < i_end; ++i) {
			printf("%s%s", i > 0 ? " " : "", cells[week][i]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <month> <year>\n", argv[0]);
		return 1;
	}
	int const month = atoi(argv[1]);
	int const year = atoi(argv[2]);
	show_calendar(year, month);
	return 0;
}
