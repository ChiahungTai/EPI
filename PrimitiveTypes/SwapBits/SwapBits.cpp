// SwapBits.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <cassert>

using namespace std;

long long SwapBits(long long x, int i, int j)
{
	if (((x >> i) & 1) != ((x >> j) &1) ) {
		unsigned long long bitMask = (1L << i) | (1L << j);
		x ^= bitMask;
	}
	return x;
}


int main()
{
	assert(SwapBits(47, 1, 4) == 61);
	assert(SwapBits(28, 0, 2) == 25);
    return 0;
}

