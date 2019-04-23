#ifndef MT_19937_H
#define MT_19937_H

#include <stdint.h>

struct Mt_19937 {
#define MT_MAGIC_SEED 5489
	Mt_19937() { Init(); }
	void Init(uint32_t seed = MT_MAGIC_SEED);
	uint32_t Next();
private:
	int _index;
	uint32_t _Mtstates[624];
};

Mt_19937 &Global_Mt_19937();

#include"Mt_19937.inl.h"


#endif
