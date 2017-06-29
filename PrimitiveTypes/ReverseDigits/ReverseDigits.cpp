// ReverseDigits.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <random>
#include <string>

using namespace std;

long Reverse(int x) {
	int result = 0, remaining = abs(x);
	while (remaining) {
		//result *= 10;
		//result += remaining % 10;
		result = result * 10 + remaining % 10;
		remaining = remaining / 10;
	}

	return x < 0 ? -result : result;
}


long CheckAns(int x) {
	string s = to_string(x);
	if (s.front() == '-') {
		reverse(s.begin() + 1, s.end());
	}
	else {
		reverse(s.begin(), s.end());
	}
	return stol(s);
}

int main(int argc, char** argv) {
	default_random_engine gen((random_device())());
	int n;
	if (argc == 2) {
		n = stoi(argv[1]);
		cout << "n = " << n << ", reversed n = " << Reverse(n) << endl;
		assert(CheckAns(n) == Reverse(n));
	}
	else {
		//uniform_int_distribution<int> dis(numeric_limits<int>::min(),
		//	numeric_limits<int>::max());
		uniform_int_distribution<int> dis(-100000, 100000);
		for (int times = 0; times < 1000; ++times) {
			n = dis(gen);
			cout << "n = " << n << ", reversed n = " << Reverse(n) << endl;
			assert(CheckAns(n) == Reverse(n));
		}
	}
	return 0;
}