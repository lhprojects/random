#include "uniform_int.h"

void uniform_int_t::init(uint32_t min, uint32_t max) {
	if(max <= min) max= min;
	_max =max; _min =min;
	for(_mask = 0;_mask < _max - _min; _mask=1+(_mask<<1)) {
	}
}

uint32_t uniform_int_t::next(Mt_19937_t &ri) {
	for(int i = 0; i < 100; ++i) {
		uint32_t rnd = ri.next() & _mask;
		if(rnd<=_max-_min) {
			return rnd + _min;
		}
	}
	return (_max-_min)/2+_max;
}

