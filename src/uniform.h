#ifndef UNIFORM_H
#define UNIFORM_H

#include "Mt_19937.h"
#include "scalar.h"

struct uniform_t {
	uniform_t() { init(0, 1); }
	void init() { init(0, 1); }
	void init_rightopen() { init_rightopen(0, 1); }

	void init(scalar_t min, scalar_t max) {
		_min =min; _max = max;
		if(_max < _min) _max = _min;
		_delta = (_max-_min)/((uint32_t)(-1));
		//_delta may be very small but there is no lossing of accuracy
		//double havs very large range of about 2^1024 so there is
		//is no problem of overflow
	}
	void init_rightopen(scalar_t min, scalar_t max) {
		_min =min; _max = max;
		if(_max < _min) _max = _min;
		_delta = (_max-_min)/((uint32_t)(-1)+1.0);
	}

	scalar_t next(Mt_19937_t &ri) {
		scalar_t x = _min + _delta* ri.next();
		if(x > _max) x = _max;
		return x;
	}
	scalar_t next() { return next(mt_global); }
private:
	scalar_t _delta;
	scalar_t _min;
	scalar_t _max;
};


#endif

