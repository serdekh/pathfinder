#include "../inc/libmx.h"

int mx_sqrt(int x) {

	if (x <= 0)
		return 0;

	int xdup = x;
	unsigned div = 1;
	unsigned result = 0;

	while (x > 0) {
		x -= div, div += 2;
		result += x < 0 ? 0 : 1;
	}

	if (result * result == (unsigned)xdup) 
		return result;
	else
		return 0;
}

