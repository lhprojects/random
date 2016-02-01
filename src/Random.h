#ifndef RANDOM_H
#define RANDOM_H

#include "Mt_19937.h"
#include"Mt_19937.inl.h"

template<class Scalar>
class Random
{
public:
	Random(Mt_19937 * backend = &Mt_19937_global);
	uint32_t RandomUInt32();
	uint64_t RandomUInt64();
	int32_t RandomInt32();
	int64_t RandomInt64();
	Scalar Uniform(Scalar min = 0.0, Scalar max = 1.0);
	Scalar Gauss(Scalar mu = 0.0, Scalar sigma = 1.0);

private:
	Mt_19937 * fBackend;
	Scalar fGaussTmp;
	int fIsGaussTmpValid;

};
#include "Random.inl.h"

#endif

