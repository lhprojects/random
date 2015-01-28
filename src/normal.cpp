
#include "normal.h"
#include <math.h>

void normal_t::init(scalar_t mu, scalar_t sigma) {
	_is_y_valid = 0;
	_y = 0;
	_mu = mu;
	_sigma = sigma;
	_unif.init_rightopen(0, 1);
}

scalar_t normal_t::next(Mt_19937_t &ri) {
	if(_is_y_valid) {
		_is_y_valid = 0;
		return _y*_sigma+_mu;
	}
	scalar_t s, x, y;
	do {
		x = 2*_unif.next(ri)-1;
		y = 2*_unif.next(ri)-1;
		s = x*x + y*y;
	} while(s >= 1.0 || s <= 1E-30);
	s = sqrt(-2*log(s)/s);
	x = x*s;
	y = y*s;
	_is_y_valid = 1;
	_y = y;
	return x*_sigma+_mu;
}


