// Parity.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <random>
#include <iostream>
#include <bitset>
#include <cassert>
#include <array>


using namespace std;

short CountBits(unsigned int x) {
	short num_bits = 0;
	while (x) {
		num_bits += (x & 1);
		x >>= 1;
	}
	return num_bits;
}

namespace Parity1 {

short Parity(unsigned long x) {
	short result = 0;
	while (x) {
		result ^= (x & 1);
		x >>= 1;
	}
	return result;
}

} // Parity1

namespace Parity2 {

short Parity(unsigned long long x) {
	short result = 0;
	while (x) {
		result ^= 1;
		x &= (x - 1);
	}
	return result;
}

} // Parity2

namespace Parity3 {
	array<short, 1 << 16> BuildTable() {
		array<short, 1 << 16> result;
		for (int i = 0; i < (1 << 16); ++i) {
			result[i] = Parity1::Parity(i);
		}
		return result;
	}
	static array<short, 1 << 16> precomputed_parity = BuildTable();

	short Parity(unsigned long long x) {
		const int kMaskSize = 16;
		const int kBitMask = 0xFFFF;
		return precomputed_parity[x >> (kMaskSize * 3)] ^
			precomputed_parity[(x >> (kMaskSize *2)) & kBitMask] ^
			precomputed_parity[(x >> (kMaskSize)) & kBitMask] ^
			precomputed_parity[x & kBitMask];
	}
}  // namespace Parity3

namespace Parity4 {

	// @include
	short Parity(unsigned long long x) {
		x ^= x >> 32;
		x ^= x >> 16;
		x ^= x >> 8;
		x ^= x >> 4;
		x ^= x >> 2;
		x ^= x >> 1;
		return x & 0x01;
	}
	// @exclude

}  // namespace Parity4

int main()
{
	// count bits
#if 0
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times) {
		uniform_int_distribution<int> dis(0, numeric_limits<int>::max());
		int x = dis(gen);
		cout << "x = " << x << ", = " << CountBits(x) << endl;
		bitset<32> checker(x);
		assert(CountBits(x) == checker.count());
	}
#endif
	// Parity
	cout << Parity2::Parity((unsigned long long)1<<48) <<endl;
	cout << Parity4::Parity((unsigned long long)1<<48 | 0x101) << endl;

    return 0;
}

