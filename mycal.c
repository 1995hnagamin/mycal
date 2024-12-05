#include <stdbool.h>
#include <stdio.h>
#include "calendar.h"

int main(void) {
	puts("     February 2015");
	puts(" Su Mo Tu We Th Fr Sa");
	for (int week = 0; week < 4; ++week) {
		for (int i = 1; i <= 7; ++i) {
			int const day = week * 7 + i;
			printf(" %2d", day);
		}
		printf("\n");
	}
	return 0;
}
