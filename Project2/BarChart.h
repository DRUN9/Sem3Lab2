#pragma once

#include "Dictionary.h"
#include "Sequence.h"
#include "MyPair.h"

template<typename T> class BarChart {
private:
	Dictionary<MyPair<double, double>, T> dict;
public:
	BarChart() {}

	BarChart(Sequence<T>& seq, double minVal, double maxVal, double partition, double (*getVal)(T)) {
		this->build(seq, minVal, maxVal, partition, getVal);
	}

	ArraySequence<T> get(double minVal, double maxVal) {
		return this->dict.get(MyPair<double, double>(minVal, maxVal));
	}

	ArraySequence<MyPair<double, double>> getAllKeys() {
		return this->dict.getKeys();
	}

	ArraySequence<ArraySequence<T>> getAllValues() {
		return this->dict.getValues();
	}

	void build(Sequence<T>& seq, double minVal, double maxVal, double partition, double (*getVal)(T)) {
		while (maxVal - minVal >= partition) {
			for (int i = 0; i < seq.getSize(); ++i) {
				if (getVal(seq[i]) >= minVal && getVal(seq[i]) <= (minVal + partition)) {
					this->dict.add(MyPair<double, double>(minVal, minVal + partition), seq[i]);
				}
			}

			minVal += partition;
		}
	}
};