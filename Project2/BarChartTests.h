#pragma once

#include <iostream>
#include <cassert>

#include "BarChart.h"

double getVal(int n) {
	return n;
}

class unittest_BarChart {
private:
	static void test_get() {
		ArraySequence<int> nums = ArraySequence<int>();

		for (int i = 0; i < 100; ++i) {
			nums.append(i + 1);
		}

		BarChart<int> barChart = BarChart<int>(nums, 0, 100, 5, getVal);

		for (int i = 0; i < 100; i += 5) {
			ArraySequence<int> n = barChart.get(i, i + 5);

			for (int j = 0; j < n.getSize(); ++j) {
				assert(n[j] >= i && n[j] <= i + 5);
			}
		}
	}
public:
	static void run() {
		test_get();

		cout << "All BarChart tests finished successfully\n";
	}
};