#pragma once

#include <stdexcept>
#include "Sequence.h"

using namespace std;

template<typename K, typename V> class Dictionary {
private:
	ArraySequence<K> keys;
	ArraySequence<ArraySequence<V>> values;
public:
	Dictionary() {}

	Dictionary(const Dictionary<K, V>& dict) {
		this->keys = dict.keys;
		this->values = dict.values;
	}

	int getSize() {
		return this->keys.getSize();
	}

	ArraySequence<V>& get(K key) {
		for (int i = 0; i < this->keys.getSize(); ++i) {
			if (key == this->keys[i]) {
				return this->values[i];
			}
		}

		throw invalid_argument("no such key in Dictionary");
	}

	ArraySequence<K> getKeys() {
		return this->keys;
	}

	ArraySequence<ArraySequence<V>> getValues() {
		return this->values;
	}

	bool containsKey(K key) {
		for (int i = 0; i < this->keys.getSize(); ++i) {
			if (key == this->keys[i]) {
				return true;
			}
		}

		return false;
	}

	void add(K key, V value) {
		for (int i = 0; i < this->keys.getSize(); ++i) {
			if (key == this->keys[i]) {
				this->values[i].append(value);

				return;
			}
		}

		this->keys.append(key);

		ArraySequence<V> newKeyValue = ArraySequence<V>();
		newKeyValue.append(value);
		this->values.append(newKeyValue);
	}

	void remove(K key) {
		if (!this->containsKey(key)) {
			throw invalid_argument("no such key in Dictionary");
		}

		int index = -1;
		for (int i = 0; i < this->keys.getSize(); ++i) {
			if (key == this->keys[i]) {
				index = i;
				break;
			}
		}

		this->keys.removeAt(index);
		this->values.removeAt(index);
	}
};