

#include "../../src/Random.h"
#include <stdio.h>
#include <random>

int main() {
	std::mt19937 mtstd;
    Mt_19937 mt;
    for(int i= 0;i >= 0;++i) {
        if(mtstd() != mt.Next()) {
            printf("Falt at %d", i);
            exit(1);
        }
		if(i % 100000000 == 0)
		printf("The first %d numbers are same\n", i);
	}

	return 0;
}





