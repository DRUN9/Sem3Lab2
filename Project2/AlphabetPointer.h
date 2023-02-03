#pragma once

#include <string>
#include <iostream>

#include "Dictionary.h"

using namespace std;

int cmp(string s1, string s2) {
	if (s1.length() > s2.length()) {
		return 1;
	}
	else if (s1.length() == s2.length()) {
		return 0;
	}
	else {
		return -1;
	}
}

class AlphabetPointer {
private:
	Dictionary<string, int> dict;
public:
	AlphabetPointer() {}

	AlphabetPointer(string str, int size) {
		this->build(str, size);
	}

	int getSize() {
		return this->dict.getSize();
	}

	bool containsWord(string word) {
		return this->dict.containsKey(word);
	}

	ArraySequence<int> get(string key) {
		return this->dict.get(key);
	}

	ArraySequence<string> getKeys() {
		return this->dict.getKeys();
	}

	ArraySequence<ArraySequence<int>> getValues() {
		return this->dict.getValues();
	}

	void build(string str, int size) {
		ArraySequence<string> words = ArraySequence<string>();

		string token;
		string delimeter = " ";
		int pos = 0;

		while ((pos = str.find(delimeter)) != string::npos) {
			token = str.substr(0, pos);
			words.append(token);
			str.erase(0, pos + delimeter.length());
		}
		words.append(str);

		int pageNumber = 1;

		int leftSize = size / 2;
		for (int i = 0; i < words.getSize(); ++i) {
			bool isUsed = false;

			while (!isUsed) {
				if ((leftSize == size && pageNumber != 1 && pageNumber % 10 != 0) || (leftSize == size / 2 && pageNumber == 1) || (leftSize == 3 * size / 4 && pageNumber % 10 == 0)) {
					if (words[i].length() <= leftSize) {
						this->dict.add(words[i], pageNumber);
						isUsed = true;
						leftSize -= words[i].length();
					}
					else {
						pageNumber++;
						if (pageNumber % 10 == 0) {
							leftSize = 3 * size / 4;
						}
						else {
							leftSize = size;
						}
					}
				}
				else {
					if (words[i].length() + 1 <= leftSize) {
						this->dict.add(words[i], pageNumber);
						isUsed = true;
						leftSize -= words[i].length() + 1;
					}
					else {
						pageNumber++;
						if (pageNumber % 10 == 0) {
							leftSize = 3 * size / 4;
						}
						else {
							leftSize = size;
						}
					}
				}
			}
		}
	}
};