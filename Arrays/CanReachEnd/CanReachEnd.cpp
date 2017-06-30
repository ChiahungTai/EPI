// CanReachEnd.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

bool CanReachEnd(const vector<int>& max_advance_steps) {
	int so_far = 0, last_idx = max_advance_steps.size() - 1;
	for (int i = 0; i <= so_far && so_far < last_idx; ++i) {
			so_far = max(so_far, i + max_advance_steps[i]);
	}
	return so_far >= last_idx;
}

void SmallTest() {
	vector<int> max_advance_steps = { 2, 3, 1, 1, 4 };
	assert(CanReachEnd(max_advance_steps));
	max_advance_steps = { 3, 2, 1, 0, 4 };
	assert(!CanReachEnd(max_advance_steps));
	max_advance_steps = { 3, 2, 1, -10, 4 };
	assert(!CanReachEnd(max_advance_steps));
	max_advance_steps = { 2, 3, -1, -1, 4 };
	assert(CanReachEnd(max_advance_steps));
	max_advance_steps = { 2, 2, -1, -1, 100 };
	assert(!CanReachEnd(max_advance_steps));
}

int main(int argc, char** argv) {
	SmallTest();
	return 0;
	//default_random_engine gen((random_device())());
	//size_t n;
	//if (argc == 2) {
	//	n = stoul(argv[1]);
	//}
	//else {
	//	uniform_int_distribution<size_t> dis(1, 1000);
	//	n = dis(gen);
	//}
	//uniform_int_distribution<int> A_dis(1, 10);
	//vector<int> max_advance_steps;
	//generate_n(back_inserter(max_advance_steps), n, [&] { return A_dis(gen); });
	//cout << std::boolalpha << CanReachEnd(max_advance_steps) << endl;
	//return 0;
}