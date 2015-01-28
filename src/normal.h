#ifndef NORMAL_H
#define NORMAL_H

#include "Mt_19937.h"
#include "uniform.h"
#include "scalar.h"

struct normal_t {
	normal_t() { init(0, 1); }
	void init(scalar_t mu, scalar_t sigma);
	scalar_t next(Mt_19937_t &ri);
	scalar_t next() { next(mt_global); }
private:
	int _is_y_valid;
	scalar_t _mu;
	scalar_t _sigma;
	scalar_t _y;
	uniform_t _unif;
};


#endif
