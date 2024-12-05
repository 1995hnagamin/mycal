#include <stdbool.h>
#include <stdio.h>
#include "calendar.h"

int main(void) {
	puts("Hello, World!");
	dow_t dow = calc_dow(2024, 12, 5);
	printf("%d\n", dow);
	return 0;
}
