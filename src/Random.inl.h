
#include "Random.h"

template<class Scalar>
Random<Scalar>::Random(Mt_19937 *backend) {
	fBackend = backend;
}

template<class Scalar>
uint32_t Random<Scalar>::RandomUInt32() {
	return fBackend->Next();
}

template<class Scalar>
uint64_t Random<Scalar>::RandomUInt64() {
	return fBackend->Next() + ((uint64_t)fBackend->Next() << 32);
}

template<class Scalar>
int32_t Random<Scalar>::RandomInt32() {
	return (int32_t)fBackend->Next();
}

template<class Scalar>
int64_t Random<Scalar>::RandomInt64() {
	return (int64_t)RandomUInt64();
}

template<class Scalar>
Scalar Random<Scalar>::Uniform(Scalar min, Scalar max) {
	Scalar delta = (max - min) / Scalar((uint32_t)(-1));
	Scalar x = min + delta* RandomUInt32();
	if (x > max) x = max;
	return x;
}

template<class Scalar>
Scalar Random<Scalar>::Gauss(Scalar mu, Scalar sigma) {
	if (fIsGaussTmpValid) {
		fIsGaussTmpValid = 0;
		return fGaussTmp*sigma + mu;
	}
	Scalar s, x, y;
	do {
		x = 2 * Uniform() - 1;
		y = 2 * Uniform() - 1;
		s = x*x + y*y;
	} while (s >= 1.0 || s <= 1E-60);
	s = sqrt(-2 * log(s) / s);
	x = x*s;
	y = y*s;
	fIsGaussTmpValid = 1;
	fGaussTmp = y;
	return x*fGaussTmp + mu;
}

