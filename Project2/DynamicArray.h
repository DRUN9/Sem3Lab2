#pragma once

#include <stdexcept>

#define INDEX_OUT_OF_RANGE_MSG "index is out of range"
#define ZERO_SIZE_MSG "size is 0"
#define NEGATIVE_SIZE_MSG "size is negative"

using namespace std;

template <typename T> class DynamicArray {
private:
	T* data = nullptr;
	int size = 0;

public:
	DynamicArray() {
		this->size = 0;
	}

	DynamicArray(int size) {
		if (size < 0) {
			throw length_error(NEGATIVE_SIZE_MSG);
		}

		if (size == 0) {
			throw length_error(ZERO_SIZE_MSG);
		}

		this->data = new T[size];
		this->size = size;
	}

	DynamicArray(T* items, int size) {
		if (size < 0) {
			throw length_error(NEGATIVE_SIZE_MSG);
		}

		if (size == 0) {
			throw length_error(ZERO_SIZE_MSG);
		}

		this->data = new T[size];
		this->size = size;

		for (int i = 0; i < size; ++i) {
			this->data[i] = items[i];
		}
	}

	DynamicArray(const DynamicArray<T>& dynamicArray) {
		this->size = dynamicArray.getSize();
		this->data = new T[this->size];

		for (int i = 0; i < this->size; ++i) {
			this->data[i] = dynamicArray.data[i];
		}
	}

	~DynamicArray() {
		delete[] this->data;
	}

	T get(int index) const {
		if (index >= this->size || index < 0) {
			throw out_of_range(INDEX_OUT_OF_RANGE_MSG);
		}

		return this->data[index];
	}

	int getSize() const {
		return this->size;
	}

	void set(T value, int index) {
		if (index >= this->size || index < 0) {
			throw out_of_range(INDEX_OUT_OF_RANGE_MSG);
		}

		this->data[index] = value;
	}

	void resize(int newSize) {
		if (newSize < 0) {
			throw length_error(NEGATIVE_SIZE_MSG);
		}

		if (newSize == 0) {
			delete[] this->data;
			this->data = nullptr;
			this->size = 0;
			//throw length_error(ZERO_SIZE_MSG);
		}

		T* newData = new T[newSize];

		for (int i = 0; i < (this->size > newSize ? newSize : this->size); ++i) {
			newData[i] = this->data[i];
		}

		delete[] this->data;

		this->data = newData;
		this->size = newSize;
	}

	void insertAt(T item, int index) {
		if (index >= this->size || index < 0) {
			throw out_of_range(INDEX_OUT_OF_RANGE_MSG);
		}

		T* newData = new T[this->size + 1];

		for (int i = 0; i < index; ++i) {
			newData[i] = this->data[i];
		}

		newData[index] = item;

		for (int i = index; i < this->size; ++i) {
			newData[i + 1] = this->data[i];
		}

		delete[] this->data;
		this->data = newData;
		this->size++;
	}

	void removeAt(int index) {
		if (index >= this->size || index < 0) {
			throw out_of_range(INDEX_OUT_OF_RANGE_MSG);
		}

		T* newData = new T[this->size - 1];

		for (int i = 0; i < index; ++i) {
			newData[i] = this->data[i];
		}

		for (int i = index + 1; i < this->size; i++) {
			newData[i - 1] = this->data[i];
		}

		delete[] this->data;
		this->data = newData;
		this->size--;
	}

	T& operator[](int index) {
		if (index >= this->size || index < 0) {
			throw out_of_range(INDEX_OUT_OF_RANGE_MSG);
		}

		return this->data[index];
	}

	const T& operator[](int index) const {
		if (index >= this->size || index < 0) {
			throw out_of_range(INDEX_OUT_OF_RANGE_MSG);
		}

		return this->data[index];
	}

	DynamicArray<T>& operator=(const DynamicArray<T>& arr) {
		this->resize(arr.getSize());

		for (int i = 0; i < arr.getSize(); ++i) {
			this->data[i] = arr.get(i);
		}

		return *this;
	}
};