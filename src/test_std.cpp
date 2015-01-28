
#include <random>
#include <stdio.h>
#include "random.h"

int main() {

	std::mt19937 stdmt;
	Mt_19937_t mt;
	int n = 1000000000;
	for(int i=0; i < n; ++i) {
		if(stdmt() != mt.next()) {
			printf("Failed!\n");
			exit(0);
		}
	}
	printf("Succeed!\n");
	return 0;
}

