//must be included in "Mt_19937.h"

void Mt_19937::Init(uint32_t seed) {
	_Mtstates[0] = seed;
	for(int i = 1; i < 624; ++i) {
		_Mtstates[i] = uint32_t(0x6c078965)*(
			_Mtstates[i-1]^(_Mtstates[i-1]>>30))+i;
	}
	_index = 0;
}

uint32_t Mt_19937::Next() {

	if(_index == 0) {
		for(int i = 0; i < 624; ++i) {
			int i1 = i+1;
			if(i1 >= 624) i1-=624;
			int i397 = i + 397;
			if(i397>=624) i397 -= 624;
			uint32_t y = (_Mtstates[i] & 0x80000000)
				+ (_Mtstates[i1] & 0x7fffffff);
			_Mtstates[i] = _Mtstates[i397] ^ (y >> 1);
			if((y & 1) != 0) {
				_Mtstates[i] = _Mtstates[i] ^ 0x9908b0df;
			}
		}
	}
	uint32_t y = _Mtstates[_index];
	y ^= (y >> 11);
	y ^= (y <<  7) & 0x9d2c5680;
	y ^= (y << 15) & 0xefc60000;
	y ^= (y >> 18);
	//_index = (_index+1) % 624;
	_index = (_index+1 >=624) ? 0 : _index+1;
	return y;
}

inline Mt_19937 &Global_Mt_19937() {
	static Mt_19937 mt_19937;
	return mt_19937;
}
