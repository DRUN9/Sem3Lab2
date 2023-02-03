#pragma once

#include <iostream>
#include <cassert>

#include "SparseVM.h"

using namespace std;

bool isNull(int n) {
	return n == 0;
}

class unittest_SparseVector {
private:
	static void test_get() {
		ArraySequence<int> nums = ArraySequence<int>();

		for (int i = 0; i < 10; ++i) {
			if (i == 0 || i == 7) {
				nums.append(100);
			}
			else {
				nums.append(0);
			}
		}

		SparseVector<int> v = SparseVector<int>(nums, isNull);

		assert(v.getSize() == 10);
		assert(v.getNotNullElemsNum() == 2);

		for (int i = 0; i < 10; ++i) {
			if (i == 0 || i == 7) {
				assert(v.get(i, 0) != 0);
			}
			else {
				assert(v.get(i, 0) == 0);
			}
		}
	}
public:
	static void run() {
		test_get();

		cout << "All SparseVector tests finished successfully\n";
	}
};

class unittest_SparseMatrix {
private:
	static void test_get() {
		ArraySequence<ArraySequence<int>> nums = ArraySequence<ArraySequence<int>>();

		for (int i = 0; i < 10; ++i) {
			ArraySequence<int> n = ArraySequence<int>();

			nums.append(n);
			for (int j = 0; j < 10; ++j) {
				if (i == j) {
					nums[i].append(100);
				}
				else {
					nums[i].append(0);
				}
			}
		}

		SparseMatrix<int> m = SparseMatrix<int>(nums, isNull);

		assert(m.getSize() == 10);
		assert(m.getNotNullElemsNum() == 10);

		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (i == j) {
					assert(m.get(i, j, 0) == 100);
				}
				else {
					assert(m.get(i, j, 0) == 0);
				}
			}
		}
	}
public:
	static void run() {
		test_get();

		cout << "All SparseMatrix tests finished successfully\n";
	}
};