

#include <stdio.h>
#include "random.h"
#include <random>
int main() {
	std::mt19937 mtstd;
    Mt_19937_t mt;
    for(int i= 0;i<10000000;++i) {
        if(mtstd() != mt.next()) {
            printf("Falt at %d", i);
            exit(1);
        }
    }

	uniform_int_t ui;
	ui.init(0,10);
	int c[5] = { };
	for(int i=0; i <1000000;++i) {
		switch (ui.next())
		{
		case 0: c[0]++;break;
		case 1: c[1]++;break;
		case 2: c[2]++;break;
		case 3: c[3]++;break;
		case 4: c[4]++;break;
		default:
			break;
		}
	}
	for(int i = 0; i < 5;++i) printf("%d\n", c[i]);
    


}





