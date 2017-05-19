#include "../../src/Random.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

template<class T>
void testUnifom(T const &rnd) {

	uint64_t const n = 1ULL * 1 * 1000 * 1000 * 1000;
	double sum = 0;
	double sum2 = 0;
	double sum3 = 0;
	double sum4 = 0;
	double sum5 = 0;
	double sum6 = 0;
	for (uint64_t i = 0; i < n; ++i) {
		double r = rnd();

		sum += r;
		sum2 += r*r;
		sum3 += r*r*r;
		sum4 += r*r*r*r;
		sum5 += r*r*r*r*r;
		sum6 += r*r*r*r*r*r;

	}
	printf("avg1: %f %f\n", sum / n, 0.5);
	printf("avg2: %f %f\n", sum2 / n, 1.0 / 3);
	printf("avg3: %f %f\n", sum3 / n, 1.0 / 4);
	printf("avg4: %f %f\n", sum4 / n, 1.0 / 5);
	printf("avg5: %f %f\n", sum5 / n, 1.0 / 6);
	printf("avg6: %f %f\n", sum6 / n, 1.0 / 7);

}

template<class T>
void testCorrelation(T const &rnd) {

	uint64_t const n = 1ULL * 1 * 1000 * 1000 * 1000;
	double sum1 = 0;
	double sum2 = 0;
	double sum3 = 0;
	double sum4 = 0;
	double sum5 = 0;

	for (uint64_t i = 0; i < n; ++i) {
		double r1 = rnd();
		double r2 = rnd();

		sum1 += r1*r2;
		sum2 += r1*r1*r2;
		sum3 += r1*r2*r2;
		sum4 += r1*r2*r2*r2;
		sum5 += r1*r1*r2*r2;

	}
	printf("avg11: %f %f\n", sum1 / n, 1.0 / 2 / 2);
	printf("avg21: %f %f\n", sum2 / n, 1.0 / 2 / 3);
	printf("avg12: %f %f\n", sum3 / n, 1.0 / 2 / 3);
	printf("avg13: %f %f\n", sum4 / n, 1.0 / 2 / 4);
	printf("avg22: %f %f\n", sum5 / n, 1.0 / 3 / 3);

}


template<class T>
void testPi(T const &rnd) {

	int t = 0;
	int n = 10000000;
	double ir2 = 0.50*0.50;
	double or2 = 0.60*0.60;

	for (int i = 0; i < n; ++i) {
		double x = rnd();
		double y = rnd();
		if (x*x + y*y < or2 && x*x + y*y >= ir2) {
			++t;
		}
		if (i % (n / 100) == 0 && i != 0) {
			printf("Pi: %f\n", 4.0*t / i);
		}
	}
	printf("Pi: %f\n", 4.0*t / n);

}


int main() {

	Random<double> rnd;
	srand(0);
	unsigned count = 0;

	testPi([&]() { return rnd.Uniform(); });

	testUnifom([&]() { return rnd.Uniform(); });
	testUnifom([](){ return (rand() % RAND_MAX + 0.5) / RAND_MAX; });
	testUnifom([&]() { return ((count += 111) % RAND_MAX + 0.5) / RAND_MAX; });

	testCorrelation([&]() { return rnd.Uniform(); });
	testCorrelation([&]() { return (rand() % RAND_MAX + 0.5) / RAND_MAX; });
	testCorrelation([&]() { return ((count += 111) % RAND_MAX + 0.5) / RAND_MAX; });

	return 0;
}


