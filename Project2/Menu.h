#pragma once

#include <iostream>

#include "Sequence.h"
#include "SparseVM.h"
#include "BarChart.h"
#include "AlphabetPointer.h"

#include "SequenceTests.h"
#include "DictionaryTests.h"
#include "SparseVMTests.h"
#include "BarChartTests.h"
#include "AlphabetPointerTests.h"

using namespace std;

int dataMenu() {
	int response = -1;

	cout << "Choose data type:\n";
	cout << "1 - int\n";
	cout << "2 - double\n";

	while (response < 1 || response > 2) {
		cin >> response;

		if (response < 1 || response > 2) {
			cout << "Wrong option, try again\n";
		}
	}

	return response;
}

int optionMenu() {
	int response = -1;

	cout << "Choose the option:\n";

	cout << "1 - SparseVector\n";
	cout << "2 - SparseMatrix\n";
	cout << "3 - BarChart\n";
	cout << "4 - AlphabetPointer\n";
	cout << "5 - Run unit tests\n";
	cout << "6 - Exit\n";

	while (response < 1 || response > 6) {
		cin >> response;

		if (response < 1 || response > 6) {
			cout << "Wrong option, try again\n";
		}
	}

	return response;
}

int sparseVectorMenu() {
	cout << "Choose the SparseVector option:\n";
	int sparseVectorResponse = -1;

	cout << "1 - Get size of vector\n";
	cout << "2 - Get number of nonzero elements\n";
	cout << "3 - Get element by index\n";
	cout << "4 - Append new element\n";
	cout << "5 - Print SparseVector\n";
	cout << "6 - Back\n";

	while (sparseVectorResponse < 1 || sparseVectorResponse > 6) {
		cin >> sparseVectorResponse;

		if (sparseVectorResponse < 1 || sparseVectorResponse > 6) {
			cout << "Wrong option, try again\n";
		}
	}

	return sparseVectorResponse;
}

int sparseMatrixMenu() {
	cout << "Choose the SparseMatrix option:\n";
	int sparseMatrixResponse = -1;

	cout << "1 - Get size of matrix\n";
	cout << "2 - Get number of nonzero elements\n";
	cout << "3 - Get element by index\n";
	cout << "4 - Back\n";

	while (sparseMatrixResponse < 1 || sparseMatrixResponse > 4) {
		cin >> sparseMatrixResponse;

		if (sparseMatrixResponse < 1 || sparseMatrixResponse > 4) {
			cout << "Wrong option, try again\n";
		}
	}

	return sparseMatrixResponse;
}

int alphabetPointerMenu() {
	cout << "Choose the AlphabetPointer option:\n";
	int alphabetPointerResponse = -1;

	cout << "1 - Get the number of pages with chosen word\n";
	cout << "2 - Get all the words in string\n";
	cout << "3 - Get the number of pages for all words\n";
	cout << "4 - Back\n";

	while (alphabetPointerResponse < 1 || alphabetPointerResponse > 4) {
		cin >> alphabetPointerResponse;

		if (alphabetPointerResponse < 1 || alphabetPointerResponse > 4) {
			cout << "Wrong option, try again\n";
		}
	}

	return alphabetPointerResponse;
}

template<typename T> void runOptions(int optionResponse, double (*getVal)(T), bool (*isNull)(T), T null) {
	if (optionResponse == 1) {
		int len;
		cout << "Enter the length of vector\n";

		cin >> len;

		ArraySequence<T> seq = ArraySequence<T>();

		cout << "Enter the elements of vector\n";

		for (int i = 0; i < len; ++i) {
			T n;
			cin >> n;
			seq.append(n);
		}

		SparseVector<T> sparseVector = SparseVector<T>(seq, isNull);
		int sparseVectorResponse = -1;

		while (sparseVectorResponse != 6) {
			int sparseVectorResponse = sparseVectorMenu();

			if (sparseVectorResponse == 1) {
				cout << "Size of vector equals " << sparseVector.getSize() << '\n';
			}
			else if (sparseVectorResponse == 2) {
				cout << "Number of nonzero elements equals " << sparseVector.getNotNullElemsNum() << '\n';
			}
			else if (sparseVectorResponse == 3) {
				cout << "Enter the index of the element\n";

				int index = -1;

				while (index < 0 || index >= sparseVector.getSize()) {
					cin >> index;

					if (index < 0 || index >= sparseVector.getSize()) {
						cout << "Wrong option, try again\n";
					}
				}

				cout << "Element with index " << index << " equals " << sparseVector.get(index, null) << '\n';
			}
			else if (sparseVectorResponse == 4) {
				int n;

				cout << "Enter the new element: ";
				cin >> n;

				sparseVector.append(n, isNull);
			}
			else if (sparseVectorResponse == 5) {
				cout << "SparseVector:\n";

				ArraySequence<int> indices = sparseVector.getNotNullElemsIndices();
				for (int i = 0; i < indices.getSize(); ++i) {
					cout << '[' << indices[i] << "]: " << sparseVector.get(indices[i], null) << '\n';
				}
				cout << '\n';
			}
			else if (sparseVectorResponse == 6) {
				return;
			}
		}
	}
	else if (optionResponse == 2) {
		int len;
		cout << "Enter the length of matrix(width equals length)\n";

		cin >> len;

		ArraySequence<ArraySequence<T>> m = ArraySequence<ArraySequence<T>>();

		cout << "Enter the elements of matrix\n";

		for (int i = 0; i < len; ++i) {
			ArraySequence<T> arr = ArraySequence<T>();

			m.append(arr);
			for (int j = 0; j < len; ++j) {
				T n;
				cin >> n;
				m[i].append(n);
			}
		}

		SparseMatrix<T> matrix = SparseMatrix<T>(m, isNull);
		int sparseMatrixResponse = -1;

		while (sparseMatrixResponse != 4) {
			sparseMatrixResponse = sparseMatrixMenu();

			if (sparseMatrixResponse == 1) {
				cout << "Size of matrix equals " << matrix.getSize();
			}
			else if (sparseMatrixResponse == 2) {
				cout << "Number of nonzero elements equals " << matrix.getNotNullElemsNum() << '\n';
			}
			else if (sparseMatrixResponse == 3) {
				int index1 = -1;
				int index2 = -1;

				cout << "Enter the first index of matrix:\n";

				while (index1 < 0 || index1 >= matrix.getSize()) {
					cin >> index1;

					if (index1 < 0 || index1 >= matrix.getSize()) {
						cout << "Wrong option, try again\n";
					}
				}

				cout << "Enter the second index of matrix:\n";

				while (index2 < 0 || index2 >= matrix.getSize()) {
					cin >> index2;

					if (index2 < 0 || index2 >= matrix.getSize()) {
						cout << "Wrong option, try again\n";
					}
				}

				cout << "Element with indices " << index1 << ' ' << index2 << " equals " << matrix.get(index1, index2, null) << '\n';
			}
			else if (sparseMatrixResponse == 4) {
				return;
			}
		}
	}
	else if (optionResponse == 3) {
		ArraySequence<T> seq = ArraySequence<T>();

		int len;
		cout << "Enter the length of sequence:\n";
		cin >> len;

		cout << "Enter the elements of sequence:\n";
		for (int i = 0; i < len; ++i) {
			T n;
			cin >> n;
			seq.append(n);
		}

		double minVal;
		cout << "Enter the minimum value of range:\n";
		cin >> minVal;

		double maxVal;
		cout << "enter the maximum value of range:\n";
		cin >> maxVal;

		double partition;
		cout << "Enter the partition coefficient:\n";
		cin >> partition;

		BarChart<T> barChart = BarChart<T>(seq, minVal, maxVal, partition, getVal);

		int barChartResponse = -1;

		while (barChartResponse != 3) {
			cout << "Choose the option\n";

			cout << "1 - Get one partition\n";
			cout << "2 - Get all partitions\n";
			cout << "3 - Back\n";

			cin >> barChartResponse;

			if (barChartResponse == 1) {
				double p1, p2;
				cout << "Enter the limits of range:\n";
				cin >> p1 >> p2;

				ArraySequence<T> rangeElems = barChart.get(p1, p2);

				cout << "Elements in range:\n";
				for (int i = 0; i < rangeElems.getSize(); ++i) {
					cout << rangeElems[i] << '\n';
				}
			}
			else if (barChartResponse == 2) {
				cout << "All partitions\n";

				ArraySequence<MyPair<double, double>> partitions = barChart.getAllKeys();
				ArraySequence<ArraySequence<T>> values = barChart.getAllValues();

				for (int i = 0; i < partitions.getSize(); ++i) {
					cout << "[ " << partitions[i].getFirst() << ' ' << partitions[i].getSecond() << " ]: ";

					for (int j = 0; j < values[i].getSize(); ++j) {
						cout << values[i][j] << ' ';
					}
					cout << '\n';
				}
			}
			else if (barChartResponse == 3) {
				return;
			}
		}
	}
	else if (optionResponse == 4) {
		string s;
		cout << "Enter the string:\n";
		getline(cin, s);
		getline(cin, s);

		int pageSize;
		cout << "Enter the size of page(must be equal of more than the maximum length of one word):\n";
		cin >> pageSize;

		AlphabetPointer ap = AlphabetPointer(s, pageSize);
		int alphabetPointerResponse = -1;

		while (alphabetPointerResponse != 4) {
			alphabetPointerResponse = alphabetPointerMenu();

			if (alphabetPointerResponse == 1) {
				string word;
				cout << "Enter the word:\n";

				cin >> word;
				if (!ap.containsWord(word)) {
					cout << "No such word in string, try again\n";

					cin >> word;
				}

				ArraySequence<int> pages = ap.get(word);

				cout << "Word \"" << word << "\" is on pages ";
				for (int i = 0; i < pages.getSize(); ++i) {
					cout << pages[i];

					if (i != pages.getSize() - 1) {
						cout << ", ";
					}
					else {
						cout << '\n';
					}
				}
			}
			else if (alphabetPointerResponse == 2) {
				ArraySequence<string> words = ap.getKeys();

				cout << "The string contain of words:\n";
				for (int i = 0; i < words.getSize(); ++i) {
					cout << words[i] << '\n';
				}
			}
			else if (alphabetPointerResponse == 3) {
				cout << "All words\n";

				ArraySequence<string> words = ap.getKeys();
				ArraySequence<ArraySequence<int>> vals = ap.getValues();

				for (int i = 0; i < words.getSize(); ++i) {
					ArraySequence<int> pages = vals[i];

					cout << '\"' << words[i] << "\": ";
					for (int j = 0; j < pages.getSize(); ++j) {
						cout << pages[j] << ' ';
					}
					cout << '\n';
				}
			}
			else if (alphabetPointerResponse == 4) {
				return;
			}
		}
	}
	else if (optionResponse == 5) {
		unittest_DynamicArray::run();
		unittest_LinkedList::run();
		unittest_ArraySequence::run();
		unittest_ListSequence::run();
		unittest_Dictionary::run();
		unittest_SparseVector::run();
		unittest_SparseMatrix::run();
		unittest_BarChart::run();
		unittest_AlphabetPointer::run();

		cout << '\n';
	}
}