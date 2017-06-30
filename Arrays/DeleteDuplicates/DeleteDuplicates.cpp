// DeleteDuplicates.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

int DeleteDuplicates(vector<int>* A_ptr) {
	vector<int>& A = *A_ptr;
	if (A.empty()) {
		return 0;
	}

	int w_idx = 1;
	for (int i = 1; i < A.size(); ++i) {
		if (A[i] != A[w_idx - 1]) {
//			cout << "A[w_idx] = " << A[w_idx] << "A[i] = " << A[i] << endl;
			A[w_idx++] = A[i];
		}
	}
	return w_idx;
}

void CheckAns(const vector<int>& A, size_t n) {
	for (size_t i = 1; i < n; ++i) {
		assert(A[i - 1] != A[i]);
	}
}

void SmallTest() {
	vector<int> A = { 2, 3, 5, 5, 7, 11, 11, 11, 13 };
	assert(6 == DeleteDuplicates(&A));
}

int main(int argc, char** argv) {
	SmallTest();
	return 0;
	default_random_engine gen((random_device())());
	size_t n;
	if (argc == 2) {
		n = stoul(argv[1]);
	}
	else {
		uniform_int_distribution<size_t> dis_n(0, 10000);
		n = dis_n(gen);
	}
	for (int times = 0; times < 1000; ++times) {
		uniform_int_distribution<int> A_dis(-1000, 1000);
		vector<int> A;
		generate_n(back_inserter(A), n, [&] { return A_dis(gen); });
		sort(A.begin(), A.end());
		auto B(A);
		auto iter = unique(B.begin(), B.end());
		auto size = DeleteDuplicates(&A);
		assert(size == distance(B.begin(), iter));
		CheckAns(A, size);
		cout << size << endl;
	}
	return 0;
}