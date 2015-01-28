#ifndef UNIFORM_INT_H
#define UNIFORM_INT_H

#include "Mt_19937.h"

struct uniform_int_t {
	uniform_int_t() { init(0,0); }
	void init(uint32_t min, uint32_t max);
	uint32_t next() { return next(mt_global); }
	uint32_t next(Mt_19937_t &mt);
private:
	uint32_t _mask;
	uint32_t _min;
	uint32_t _max;
};

#endif


