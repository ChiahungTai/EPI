// IntersectRectangle.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <string>

using namespace std;

struct Rectangle;
bool IsIntersect(const Rectangle&, const Rectangle&);

struct Rectangle {
	int x, y, width, height;

	void print(string s) const {
		cout << s << this->x << ' ' << this->y << ' ' << this->width << ' ' << this->height << endl;
	}
};

Rectangle IntersectRectangle(const Rectangle& R1, const Rectangle& R2) {
	if (!IsIntersect(R1, R2)) {
		return {0,0,-1, -1};
	}
	return {max(R1.x, R2.x), max(R1.y, R2.y),
			min(R1.x+R1.width, R2.x+R2.width) - max(R1.x, R2.x),
			min(R1.y + R1.height, R2.y + R2.height) - max(R1.y, R2.y) };

}

bool IsIntersect(const Rectangle& R1, const Rectangle& R2) {
	return R1.x <= R2.x + R2.width && R2.x <= R1.x + R1.width &&
		R1.y <= R2.y + R2.height && R2.y <= R2.y + R2.height;
}

void SmallTest() {
	Rectangle R1 = { 0, 0, 2, 2 }, R2 = { 1, 1, 3, 3 };
	auto result = IntersectRectangle(R1, R2);
	assert(result.x == 1 && result.y == 1 && result.width == 1 &&
		result.height == 1);
	R1 = { 0, 0, 1, 1 }, R2 = { 1, 1, 3, 3 };
	result = IntersectRectangle(R1, R2);
	assert(result.x == 1 && result.y == 1 && result.width == 0 &&
		result.height == 0);
	R1 = { 0, 0, 1, 1 }, R2 = { 2, 2, 3, 3 };
	result = IntersectRectangle(R1, R2);
	assert(result.x == 0 && result.y == 0 && result.width == -1 &&
		result.height == -1);
}

int main(int argc, char* argv[]) {
	SmallTest();
	return 0;
}