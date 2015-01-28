#include "random.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n =1000000000;
	int t = 0;
	printf("samples: %d\n", n);

	uniform_t u;
	u.init(0, 1);
	for(int i = 0; i < n; ++i) {
		scalar_t x = u.next();
		scalar_t y = u.next();
		if(x*x+y*y < 1) {
			++t;
		}
		if(i%(n/100)==0 && i != 0) {
			printf("Pi: %f\n", 4.0*t/i);
		}
	}
	printf("Pi: %f\n", 4.0*t/n);
	return 0;
}


