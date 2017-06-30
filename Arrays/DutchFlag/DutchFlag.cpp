// DutchFlag.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

typedef enum {RED, WHITE, BLUE} Color;

void DutchFlagPartition(int pivot_index, vector<Color>* A_ptr) {
	vector<Color>& A = *A_ptr;
	Color pivot = A[pivot_index];

	int smaller = 0, equal = 0, larger = A.size();
	while (equal < larger) {
		if (A[equal] < pivot) {
			swap(A[smaller++], A[equal++]);
		}
		else if (A[equal] == pivot) {
			equal++;
		} else {
			swap(A[equal], A[--larger]);
		}
	}
}

vector<Color> RandVector(int len) {
	default_random_engine gen((random_device())());
	vector<Color> ret;
	while (len--) {
		uniform_int_distribution<int> dis(0, 2);
		ret.push_back(static_cast<Color>(dis(gen)));
	}
	return ret;
}

int main(int argc, char* argv[]) {
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times) {
		int n;
		if (argc == 2) {
			n = atoi(argv[1]);
		}
		else {
			uniform_int_distribution<int> dis(1, 100);
			n = dis(gen);
		}
		vector<Color> A(RandVector(n));
		uniform_int_distribution<int> dis(0, A.size() - 1);
		int pivot_index = dis(gen);
		Color pivot = A[pivot_index];
		DutchFlagPartition(pivot_index, &A);
		int i = 0;
		while (i < A.size() && A[i] < pivot) {
			cout << A[i] << ' ';
			++i;
		}
		while (i < A.size() && A[i] == pivot) {
			cout << A[i] << ' ';
			++i;
		}
		while (i < A.size() && A[i] > pivot) {
			cout << A[i] << ' ';
			++i;
		}
		cout << endl;
		assert(i == A.size());
	}
	return 0;
}