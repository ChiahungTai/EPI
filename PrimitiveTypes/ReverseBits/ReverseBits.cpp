// ReverseBits.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <vector>
#include <iostream>
#include <cassert>
#include <bitset>

using namespace std;

vector<long> precomputed_reverse;

void PrintBits(long long n) {
	std::cout << std::bitset<64>(n) << endl;
}

void PrintBits(long n) {
	std::cout << std::bitset<32>(n) << endl;
}

long long SwapBits(long long x, int i, int j)
{
	if (((long long)x >> i & 0x1) != ((long long)x >> j & 0x1)) {
		long long bitMask = (long long)1L << i | (long long)1L << j;
		x ^= bitMask;
	}
	return x;
}

long long ReverseX(long long x, int n) {
	for (int i = 0, j = n; i < j; ++i, --j) {
		x = SwapBits(x, i, j);
	}
	return x;
}

void CreatePrecomputedTable() {
	for (int i = 0; i < (1 << 16); ++i) {
		precomputed_reverse.emplace_back(ReverseX(i, 15));
	}
}

long long ReverseBits(long long x) {
	const int kMaskSize = 16;
	const int kBitMask = 0xffff;

	return ((long long)precomputed_reverse[x & kBitMask] << (3 * kMaskSize)) |
		((long long)precomputed_reverse[(x >> kMaskSize) & kBitMask] << (2 * kMaskSize)) |
		((long long)precomputed_reverse[(x >> (2 * kMaskSize)) & kBitMask] << kMaskSize) |
		(long long)precomputed_reverse[(x >> (3 * kMaskSize)) & kBitMask];
}


int main()
{
	CreatePrecomputedTable();
	long long x = ((long long)0x1<<62 | 0x1);
	PrintBits(x);
	cout << "sizeof(x) = " << sizeof(x) << endl;
	cout << "x = " << x << ", reverse x = " << ReverseBits(x) << endl;
	PrintBits(ReverseBits(x));
	cout << ReverseX(x, 63) << endl;
	PrintBits(ReverseX(x, 63));

	assert(ReverseBits(x) == ReverseX(x, 63));
    return 0;
}

