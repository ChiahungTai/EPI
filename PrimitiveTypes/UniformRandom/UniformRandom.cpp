// UniformRandom.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <cassert>
#include <cmath>
#include <iostream>
#include <random>

using namespace std;

int ZeroOneRandom() {
	default_random_engine gen((random_device())());
	uniform_int_distribution<int> dis(0,1);
	return dis(gen);
}

int UniformRandom(int lower_bound, int upper_bound) {
	int num_of_outcomes = upper_bound - lower_bound + 1;
	int result;
	int numBits = log2(num_of_outcomes);
	printf("lower_bound=%d, upper_bound=%d, num_of_outcomes=%d\n", lower_bound, upper_bound, num_of_outcomes);
	cout << "numBits = " << numBits << endl;
	do {
		result = 0;
//		for (int i = 0; (1 << i) < num_of_outcomes; ++i) {
		for (int i = 0; i < numBits; ++i) {
			result = result << 1 | ZeroOneRandom();
		}
	} while (result >= num_of_outcomes);
	return result + lower_bound;
}

int main(int argc, char* argv[]) {
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times) {
		int a, b;
		if (argc == 3) {
			a = atoi(argv[1]), b = atoi(argv[2]);
		}
		else {
			uniform_int_distribution<int> a_dis(0, 99);
			a = a_dis(gen);
			uniform_int_distribution<int> b_dis(a + 1, a + 100);
			b = b_dis(gen);
		}
		int x = UniformRandom(a, b);
		cout << "a = " << a << " b = " << b << endl;
		cout << "random result = " << x << endl;
		assert(x >= a && x <= b);
	}
	return 0;
}