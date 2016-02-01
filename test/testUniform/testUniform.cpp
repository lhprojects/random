#include "../../src/Random.h"
#include <stdio.h>
#include <math.h>

int main() {
	int n =1000000000;
	int t = 0;
	printf("samples: %d\n", n);

	Random<double> rd;
	for(int i = 0; i < n; ++i) {
		double x = rd.Uniform();
		double y = rd.Uniform();
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


