// ClosetIntSameBitCount.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <cassert>
#include <bitset>

using namespace std;

unsigned long long ClosestIntSameBitCount(unsigned long long x) {
	//cout << sizeof(x) << endl;
	//cout << bitset<64>(x) << endl;
	const static int kNumUnsignedBits = 64;
	for (int i = 0; i < kNumUnsignedBits -1; ++i) {
		if (((unsigned long long) x >> i & 0x1) != ((unsigned long long) x >> i + 1 & 0x1)) {
			x ^= (unsigned long long) 1UL << i | (unsigned long long)  1UL << (i + 1);
			//cout << bitset<64>(x) << endl;
			return x;
		}
	}
	// Throw error if all bits of x are 0 or 1.
	throw invalid_argument("All bits are 0 or 1");
}


void SmallTest() {
	assert(ClosestIntSameBitCount(6) == 5);
	assert(ClosestIntSameBitCount(7) == 11);
	assert(ClosestIntSameBitCount(2) == 1);
	assert(ClosestIntSameBitCount(32) == 16);
	
	//unsigned long long max2 = numeric_limits<unsigned long long>::max() - 2;
	//cout << "numeric_limits<unsigned long long>::max() - 2 = " << bitset<64>(max2) << endl;
	//unsigned long long ans = ClosestIntSameBitCount(numeric_limits<unsigned long long>::max() - 1);
	//cout << "ClosestIntSameBitCount =" << bitset<64>(ans) << endl;
	assert(ClosestIntSameBitCount(numeric_limits<unsigned long long>::max() - 1) ==
		numeric_limits<unsigned long long>::max() - 2);

	try {
		ClosestIntSameBitCount(numeric_limits<unsigned long long>::max());
		assert(false);
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	try {
		ClosestIntSameBitCount(0);
		assert(false);
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
}

int main()
{
	SmallTest();
    return 0;
}

