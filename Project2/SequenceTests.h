#pragma once

#include <cassert>
#include <iostream>

#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sequence.h"

class unittest_DynamicArray {
private:
	static void test_get() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		DynamicArray<int> dyn_test = DynamicArray<int>(testn, 5);

		assert(dyn_test.get(0) == 0);
		assert(dyn_test.get(3) == 3);
		assert(dyn_test.get(4) == 4);

		assert(dyn_test.getSize() == 5);

		delete[] testn;
	}

	static void test_set() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		DynamicArray<int> dyn_test = DynamicArray<int>(testn, 5);

		dyn_test.set(100, 0);

		assert(dyn_test.get(0) == 100);
		assert(dyn_test.get(1) == 1);

		delete[] testn;
	}

	static void test_resize() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		DynamicArray<int> dyn_test = DynamicArray<int>(testn, 5);

		dyn_test.resize(3);

		assert(dyn_test.getSize() == 3);
		assert(dyn_test.get(0) == 0);
		assert(dyn_test.get(1) == 1);
		assert(dyn_test.get(2) == 2);

		delete[] testn;
	}

	static void test_remove() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		DynamicArray<int> dyn_test = DynamicArray<int>(testn, 5);

		dyn_test.removeAt(3);

		assert(dyn_test.getSize() == 4);
		assert(dyn_test.get(0) == 0);
		assert(dyn_test.get(1) == 1);
		assert(dyn_test.get(2) == 2);
		assert(dyn_test.get(3) == 4);

		delete[] testn;
	}

	static void test_insert() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		DynamicArray<int> dyn_test = DynamicArray<int>(testn, 5);

		dyn_test.insertAt(100, 3);

		assert(dyn_test.getSize() == 6);
		assert(dyn_test.get(0) == 0);
		assert(dyn_test.get(1) == 1);
		assert(dyn_test.get(2) == 2);
		assert(dyn_test.get(3) == 100);
		assert(dyn_test.get(4) == 3);
		assert(dyn_test.get(5) == 4);
	}

	static void test_index() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		DynamicArray<int> dyn_test = DynamicArray<int>(testn, 5);

		assert(dyn_test[0] == 0);
		assert(dyn_test[1] == 1);
		assert(dyn_test[2] == 2);
		assert(dyn_test[3] == 3);
		assert(dyn_test[4] == 4);

		dyn_test[0] = 10;

		assert(dyn_test[0] == 10);
		assert(dyn_test[1] == 1);
		assert(dyn_test[2] == 2);
		assert(dyn_test[3] == 3);
		assert(dyn_test[4] == 4);

		delete[] testn;
	}

	static void test_assign() {
		int* testn1 = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn1[i] = i;
		}

		int* testn2 = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn2[i] = i + 5;
		}

		DynamicArray<int> dyn_test1 = DynamicArray<int>(testn1, 5);
		DynamicArray<int> dyn_test2 = DynamicArray<int>(testn2, 5);

		for (int i = 0; i < 5; ++i) {
			assert(dyn_test1[i] == i);
			assert(dyn_test2[i] == i + 5);
		}

		dyn_test2 = dyn_test1;

		for (int i = 0; i < 5; ++i) {
			assert(dyn_test1[i] == i);
			assert(dyn_test2[i] == i);
		}

		dyn_test1[0] = 10;

		assert(dyn_test1[0] == 10);
		assert(dyn_test2[0] == 0);

	}
public:
	static void run() {
		test_get();
		test_set();
		test_resize();
		test_remove();
		test_insert();
		test_index();
		test_assign();

		cout << "All DynamicArray tests finished successfully\n";
	}
};


class unittest_LinkedList {
private:
	static void test_get() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		LinkedList<int> list = LinkedList<int>(testn, 5);
		LinkedList<int> sublist = list.getSublist(0, 2);

		assert(list.getFirst() == 0);
		assert(list.getLast() == 4);
		assert(list.get(2) == 2);
		assert(list.getLength() == 5);

		assert(sublist.getLength() == 2);
		assert(sublist.get(0) == 0);
		assert(sublist.get(1) == 1);

		delete[] testn;
	}

	static void test_insert() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		LinkedList<int> list = LinkedList<int>(testn, 5);

		list.insertAt(100, 3);

		assert(list.getLength() == 6);
		assert(list.get(2) == 2);
		assert(list.get(3) == 100);
		assert(list.get(4) == 3);

		list.append(10);

		assert(list.getLength() == 7);
		assert(list.get(5) == 4);
		assert(list.get(6) == 10);

		list.prepend(1000);

		assert(list.getLength() == 8);
		assert(list.get(0) == 1000);
		assert(list.get(1) == 0);

		delete[] testn;
	}

	static void test_remove() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		LinkedList<int> list = LinkedList<int>(testn, 5);

		list.removeAt(4);

		assert(list.getLength() == 4);
		assert(list.get(3) == 3);

		delete[] testn;
	}

	static void test_concat() {
		int* testn1 = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn1[i] = i;
		}

		int* testn2 = new int[5];
		for (int i = 5; i < 10; ++i) {
			testn2[i - 5] = i;
		}

		LinkedList<int> list1 = LinkedList<int>(testn1, 5);
		LinkedList<int> list2 = LinkedList<int>(testn2, 5);

		list1.concat(list2);

		assert(list1.getLength() == 10);
		assert(list1.get(0) == 0);
		assert(list1.get(4) == 4);
		assert(list1.get(5) == 5);
		assert(list1.get(9) == 9);

		delete[] testn1;
		delete[] testn2;

	}

	static void test_index() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		LinkedList<int> list = LinkedList<int>(testn, 5);

		assert(list[0] == 0);
		assert(list[1] == 1);
		assert(list[2] == 2);
		assert(list[3] == 3);
		assert(list[4] == 4);

		list[0] = 10;
		list[1] = list[0];
		list[2] = 12;

		assert(list[0] == 10);
		assert(list[1] == 10);
		assert(list[2] == 12);
		assert(list[3] == 3);
		assert(list[4] == 4);

		delete[] testn;
	}

	static void test_assign() {
		int* testn1 = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn1[i] = i;
		}

		int* testn2 = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn2[i] = i + 5;
		}

		LinkedList<int> list1 = LinkedList<int>(testn1, 5);
		LinkedList<int> list2 = LinkedList<int>(testn2, 5);

		for (int i = 0; i < 5; ++i) {
			assert(list1[i] == i);
			assert(list2[i] == i + 5);
		}

		list2 = list1;

		assert(list2.getLength() == list1.getLength());

		for (int i = 0; i < 5; ++i) {
			assert(list1[i] == i);
			assert(list2[i] == i);
		}

		list1[0] = 10;

		assert(list1[0] == 10);
		assert(list2[0] == 0);

		delete[] testn1;
		delete[] testn2;
	}

public:
	static void run() {
		test_get();
		test_insert();
		test_remove();
		test_concat();
		test_index();
		test_assign();

		cout << "All LinkedList tests finished successfully\n";
	}
};


class unittest_ArraySequence {
private:
	static void test_get() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		ArraySequence<int> seq = ArraySequence<int>(testn, 5);

		ArraySequence<int> subseq = seq.getSubSequence(0, 2);

		assert(seq.get(2) == 2);
		assert(seq.getFirst() == 0);
		assert(seq.getLast() == 4);
		assert(seq.getSize() == 5);

		assert(subseq.get(0) == 0);
		assert(subseq.get(1) == 1);
		assert(subseq.getSize() == 2);

		delete[] testn;
	}

	static void test_concat() {
		int* testn1 = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn1[i] = i;
		}

		int* testn2 = new int[5];
		for (int i = 5; i < 10; ++i) {
			testn2[i - 5] = i;
		}

		ArraySequence<int> seq1 = ArraySequence<int>(testn1, 5);
		ArraySequence<int> seq2 = ArraySequence<int>(testn2, 5);
		seq1.concat(seq2);

		assert(seq1.getSize() == 10);
		assert(seq1[0] == 0);
		assert(seq1[4] == 4);
		assert(seq1[5] == 5);
		assert(seq1[9] == 9);

		delete[] testn1;
		delete[] testn2;
	}

	static void test_insert() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		ArraySequence<int> seq = ArraySequence<int>(testn, 5);

		seq.append(100);

		assert(seq.getSize() == 6);
		assert(seq[5] == 100);

		seq.prepend(10);

		assert(seq.getSize() == 7);
		assert(seq[0] == 10);

		seq.insertAt(1000, 2);

		assert(seq.getSize() == 8);
		assert(seq[2] == 1000);

		delete[] testn;
	}

	static void test_remove() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		ArraySequence<int> seq = ArraySequence<int>(testn, 5);

		seq.removeAt(0);

		assert(seq.getSize() == 4);
		assert(seq[0] == 1);

		delete[] testn;
	}

	static void test_index() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		ArraySequence<int> seq = ArraySequence<int>(testn, 5);

		for (int i = 0; i < seq.getSize(); ++i) {
			assert(seq[i] == i);
		}

		seq[0] = 10;

		assert(seq.getSize() == 5);
		assert(seq[0] == 10);
	}

	static void test_assign() {
		int* testn1 = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn1[i] = i;
		}

		int* testn2 = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn2[i] = i + 5;
		}

		ArraySequence<int> seq1 = ArraySequence<int>(testn1, 5);
		ArraySequence<int> seq2 = ArraySequence<int>(testn2, 5);

		for (int i = 0; i < 5; ++i) {
			assert(seq1[i] == i);
			assert(seq2[i] == i + 5);
		}

		seq2 = seq1;

		for (int i = 0; i < 5; ++i) {
			assert(seq1[i] == i);
			assert(seq2[i] == i);
		}

		seq1[0] = 10;

		assert(seq1[0] == 10);
		assert(seq2[0] == 0);
	}
public:
	static void run() {
		test_get();
		test_concat();
		test_insert();
		test_remove();
		test_index();
		test_assign();

		cout << "All ArraySequence tests finished successfully\n";
	}
};


class unittest_ListSequence {
private:
	static void test_get() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		ListSequence<int> seq = ListSequence<int>(testn, 5);

		ListSequence<int> subseq = seq.getSubSequence(0, 2);

		assert(seq.get(2) == 2);
		assert(seq.getFirst() == 0);
		assert(seq.getLast() == 4);
		assert(seq.getSize() == 5);

		assert(subseq.get(0) == 0);
		assert(subseq.get(1) == 1);
		assert(subseq.getSize() == 2);

		delete[] testn;
	}

	static void test_concat() {
		int* testn1 = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn1[i] = i;
		}

		int* testn2 = new int[5];
		for (int i = 5; i < 10; ++i) {
			testn2[i - 5] = i;
		}

		ListSequence<int> seq1 = ListSequence<int>(testn1, 5);
		ListSequence<int>seq2 = ListSequence<int>(testn2, 5);

		seq1.concat(seq2);

		assert(seq1.getSize() == 10);
		assert(seq1[0] == 0);
		assert(seq1[4] == 4);
		assert(seq1[5] == 5);
		assert(seq1[9] == 9);

		delete[] testn1;
		delete[] testn2;
	}

	static void test_insert() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		ListSequence<int> seq = ListSequence<int>(testn, 5);

		seq.append(100);

		assert(seq.getSize() == 6);
		assert(seq[5] == 100);

		seq.prepend(10);

		assert(seq.getSize() == 7);
		assert(seq[0] == 10);

		seq.insertAt(1000, 2);

		assert(seq.getSize() == 8);
		assert(seq[2] == 1000);

		delete[] testn;
	}

	static void test_remove() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		ListSequence<int> seq = ListSequence<int>(testn, 5);

		seq.removeAt(0);

		assert(seq.getSize() == 4);
		assert(seq[0] == 1);

		delete[] testn;
	}

	static void test_index() {
		int* testn = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn[i] = i;
		}

		ListSequence<int> seq = ListSequence<int>(testn, 5);

		for (int i = 0; i < 5; ++i) {
			assert(seq[i] == i);
		}

		seq[0] = 10;

		assert(seq.getSize() == 5);
		assert(seq[0] == 10);

		delete[] testn;
	}

	static void test_assign() {
		int* testn1 = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn1[i] = i;
		}

		int* testn2 = new int[5];
		for (int i = 0; i < 5; ++i) {
			testn2[i] = i + 5;
		}

		ListSequence<int> seq1 = ListSequence<int>(testn1, 5);
		ListSequence<int> seq2 = ListSequence<int>(testn2, 5);

		for (int i = 0; i < 5; ++i) {
			assert(seq1[i] == i);
			assert(seq2[i] == i + 5);
		}

		seq2 = seq1;

		for (int i = 0; i < 5; ++i) {
			assert(seq1[i] == i);
			assert(seq2[i] == i);
		}

		seq1[0] = 10;

		assert(seq1[0] == 10);
		assert(seq2[0] == 0);
	}
public:
	static void run() {
		test_get();
		test_concat();
		test_insert();
		test_remove();
		test_index();
		test_assign();

		cout << "All ListSequence tests finished successfully\n";
	}
};