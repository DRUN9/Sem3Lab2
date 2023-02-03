#pragma once

#include "Dictionary.h"
#include "Sequence.h"
#include "MyPair.h"



template<typename T> class SparseVector {
private:
	Dictionary<int, T> dict;
	int size;
public:
	SparseVector() {}

	SparseVector(Sequence<T>& seq, bool (*isNull)(T)) {
		this->size = seq.getSize();

		for (int i = 0; i < seq.getSize(); ++i) {
			if (!isNull(seq[i])) {
				this->dict.add(i, seq[i]);
			}
		}
	}

	int getSize() {
		return this->size;
	}

	int getNotNullElemsNum() {
		return this->dict.getSize();
	}

	T get(int index, T null) {
		if (this->dict.containsKey(index)) {
			return this->dict.get(index)[0];
		}

		return null;
	}

	ArraySequence<int> getNotNullElemsIndices() {
		return this->dict.getKeys();
	}

	void append(T item, bool (*isNull)(T)) {
		this->size++;

		if (!isNull(item)) {
			this->dict.add(this->size - 1, item);
		}
	}
};

template<typename T> class SparseMatrix {
private:
	Dictionary<MyPair<int, int>, T> dict;
	int size;
public:
	SparseMatrix() {}

	SparseMatrix(ArraySequence<ArraySequence<T>>& seq, bool(*isNull)(T)) {
		this->size = seq.getSize();

		for (int i = 0; i < seq.getSize(); ++i) {
			for (int j = 0; j < seq[i].getSize(); ++j) {
				if (!isNull(seq[i][j])) {
					this->dict.add(MyPair<int, int>(i, j), seq[i][j]);
				}
			}
		}
	}

	int getSize() {
		return this->size;
	}

	int getNotNullElemsNum() {
		return this->dict.getSize();
	}

	T get(int index1, int index2, T null) {
		if (this->dict.containsKey(MyPair<int, int>(index1, index2))) {
			return this->dict.get(MyPair<int, int>(index1, index2))[0];
		}

		return null;
	}
};

