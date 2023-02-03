#pragma once

#include <cassert>
#include <iostream>

#include "Dictionary.h"

using namespace std;

class unittest_Dictionary {
private:
	static void test_get() {
		Dictionary<int, int> dict = Dictionary<int, int>();

		for (int i = 0; i < 5; ++i) {
			dict.add(i, i + 10);
		}

		assert(dict.getSize() == 5);

		for (int i = 0; i < 5; ++i) {
			assert(dict.get(i)[0] == i + 10);
		}

		ArraySequence<int> keys = dict.getKeys();
		for (int i = 0; i < keys.getSize(); ++i) {
			assert(keys[i] == i);
		}

		ArraySequence<ArraySequence<int>> values = dict.getValues();
		for (int i = 0; i < values.getSize(); ++i) {
			assert(values[i].getSize() == 1);
			assert(values[i][0] == i + 10);
		}
	}

	static void test_containsKey() {
		Dictionary<int, int> dict = Dictionary<int, int>();

		for (int i = 0; i < 5; ++i) {
			dict.add(i, i + 10);
		}

		for (int i = 0; i < 5; ++i) {
			assert(dict.containsKey(i));
		}

		assert(!dict.containsKey(100));
	}

	static void test_add() {
		Dictionary<int, int> dict = Dictionary<int, int>();

		dict.add(0, 10);
		assert(!dict.containsKey(1));

		dict.add(1, 100);
		assert(dict.containsKey(1));
	}

	static void test_remove() {
		Dictionary<int, int> dict = Dictionary<int, int>();

		dict.add(0, 10);
		assert(dict.containsKey(0));
		assert(dict.getSize() == 1);

		dict.remove(0);
		assert(!dict.containsKey(0));
		assert(dict.getSize() == 0);
	}
public:
	static void run() {
		test_get();
		test_containsKey();
		test_add();
		test_remove();

		cout << "All Dictionary tests finished successfully\n";
	}
};