#pragma once

#include <stdexcept>

#include "DynamicArray.h"
#include "LinkedList.h"

using namespace std;

template <typename T> class Sequence {
public:
	virtual T getFirst() const = 0;
	virtual T getLast() const = 0;
	virtual T get(int index) const = 0;
	virtual int getSize() const = 0;
	virtual Sequence<T>& getSubSequence(int startIndex, int endIndex) const = 0;

	virtual void append(T item) = 0;
	virtual void prepend(T item) = 0;
	virtual void insertAt(T item, int index) = 0;
	virtual void removeAt(int index) = 0;
	virtual void set(T item, int index) = 0;
	virtual void concat(Sequence<T>& seq) = 0;

	virtual T& operator[] (int index) = 0;
	//virtual const T& operator[] (int index) const = 0;
};

template <typename T> class ArraySequence : public Sequence<T> {
private:
	DynamicArray<T> arr;
public:
	ArraySequence() {
		this->arr = DynamicArray<T>();
	}

	ArraySequence(int size) {
		this->arr = DynamicArray<T>(size);
	}

	ArraySequence(T* items, int size) {
		this->arr = DynamicArray<T>(items, size);
	}

	ArraySequence(DynamicArray<T>& arr) {
		if (arr.getSize() == 0) {
			this->arr = DynamicArray<T>();
		}

		else {
			this->arr = arr;
		}
	}

	ArraySequence(const Sequence<T>& arr_seq) {
		if (arr_seq.getSize() == 0) {
			this->arr = DynamicArray<T>();
		}

		else {
			this->arr = DynamicArray<T>(arr_seq.getSize());

			for (int i = 0; i < this->arr.getSize(); ++i) {
				this->arr[i] = arr_seq.get(i);
			}
		}
	}

	~ArraySequence() {}

	T getFirst() const override {
		return this->arr.get(0);
	}

	T getLast() const override {
		return this->arr.get(this->arr.getSize() - 1);
	}

	T get(int index) const override {
		return this->arr.get(index);
	}

	int getSize() const override {
		return this->arr.getSize();
	}

	ArraySequence<T>& getSubSequence(int startIndex, int endIndex) const override {
		if (startIndex >= this->arr.getSize() || endIndex > this->arr.getSize() || startIndex < 0 || endIndex < 0) {
			throw out_of_range(INDEX_OUT_OF_RANGE_MSG);
		}
		if (startIndex >= endIndex) {
			throw logic_error("startIndex must be less than endIndex");
		}

		int n = endIndex - startIndex;
		T* subArray = new T[n];

		for (int i = 0; i < n; ++i) {
			subArray[i] = this->arr.get(i + startIndex);
		}

		ArraySequence<T>* subSequence = new ArraySequence<T>(subArray, endIndex - startIndex);

		return *subSequence;
	}

	void set(T item, int index) override {
		this->arr.set(item, index);
	}

	void append(T item) override {
		this->arr.resize(this->arr.getSize() + 1);
		this->arr.set(item, this->arr.getSize() - 1);
	}

	void prepend(T item) override {
		this->arr.resize(this->arr.getSize() + 1);
		T tmp1 = this->arr.get(0);
		T tmp2;
		for (int i = 0; i < this->arr.getSize() - 1; ++i) {
			tmp2 = tmp1;
			tmp1 = this->arr.get(i + 1);
			this->arr.set(tmp2, i + 1);
		}
		this->arr.set(item, 0);
	}

	void insertAt(T item, int index) override {
		this->arr.insertAt(item, index);
	}

	void removeAt(int index) override {
		this->arr.removeAt(index);
	}

	void concat(Sequence<T>& seq) override {
		for (int i = 0; i < seq.getSize(); ++i) {
			this->append(seq.get(i));
		}
	}

	T& operator[](int index) override {
		return this->arr[index];
	}

	/*const T& operator[](int index) const override {
		return this->arr[index];
	}*/

	ArraySequence<T>& operator= (const ArraySequence<T>& arr_seq) {
		this->arr = arr_seq.arr;

		return *this;
	}
};

template <typename T> class ListSequence : public Sequence<T> {
private:
	LinkedList<T> list;
public:
	ListSequence() {
		this->list = LinkedList<T>();
	}

	ListSequence(T* items, int size) {
		this->list = LinkedList<T>(items, size);
	}

	ListSequence(LinkedList<T>& list) {
		this->list = list;
	}

	ListSequence(const ListSequence<T>& list_seq) {
		this->list = list_seq.list;
	}

	~ListSequence() {}

	T getFirst() const override {
		return this->list.getFirst();
	}

	T getLast() const override {
		return this->list.getLast();
	}

	T get(int index) const override {
		return this->list.get(index);
	}

	int getSize() const override {
		return this->list.getLength();
	}

	void append(T item) override {
		this->list.append(item);
	}

	void set(T item, int index) override {
		this->list.set(item, index);
	}

	void prepend(T item) override {
		this->list.prepend(item);
	}

	void insertAt(T item, int index) override {
		this->list.insertAt(item, index);
	}

	void removeAt(int index) override {
		this->list.removeAt(index);
	}

	ListSequence<T>& getSubSequence(int startIndex, int endIndex) const override {
		LinkedList<T> sublist = this->list.getSublist(startIndex, endIndex);
		ListSequence<T>* subseq = new ListSequence<T>(sublist);
		return *subseq;
	}

	void concat(Sequence<T>& seq) override {
		for (int i = 0; i < seq.getSize(); ++i) {
			this->list.append(seq.get(i));
		}
	}

	T& operator[](int index) override {
		return this->list[index];
	}

	/*const T& operator[](int index) const override {
		return this->list[index];
	}*/

	ListSequence<T>& operator=(const ListSequence<T>& list_seq) {
		this->list = list_seq.list;

		return *this;
	}
};