#ifndef MT_19937_H
#define MT_19937_H

#include <stdint.h>
struct Mt_19937_t {
#define MT_MAGIC_SEED 5489
	Mt_19937_t() { init(MT_MAGIC_SEED); }
	void init() { init(MT_MAGIC_SEED); }
	void init(uint32_t seed);
	uint32_t next();
private:
	int _index;
	uint32_t _Mtstates[624];
};

extern Mt_19937_t mt_global;


#endif
