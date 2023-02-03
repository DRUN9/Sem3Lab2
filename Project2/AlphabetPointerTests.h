#pragma once

#include <iostream>
#include <cassert>
#include <string>

#include "AlphabetPointer.h"

using namespace std;

class unittest_AlphabetPointer {
private:
	static void test_get() {
		string str = "123 2";

		AlphabetPointer ap = AlphabetPointer(str, 3);

		assert(ap.getSize() == 2);

		assert(ap.getKeys().getSize() == 2);
		assert(ap.getValues().getSize() == 2);

		assert(ap.get("123")[0] == 2);
		assert(ap.get("2")[0] == 3);
	}

	static void test_build() {
		string str = "I live in Moscow";

		AlphabetPointer ap = AlphabetPointer();

		ap.build(str, 7);

		assert(ap.get("I")[0] == 1);
		assert(ap.get("live")[0] == 2);
		assert(ap.get("in")[0] == 2);
		assert(ap.get("Moscow")[0] == 3);
	}
public:
	static void run() {
		test_get();
		test_build();

		cout << "All AlphabetPointer tests finished successfully\n";
	}
};