#include "Menu.h"

using namespace std;

template<typename K, typename V> ostream& operator<<(ostream& out, Dictionary<K, V>& dict) {
	ArraySequence<K> keys = dict.getKeys();

	for (int i = 0; i < keys.getSize(); ++i) {
		out << keys[i] << " : ";

		ArraySequence<V> value = dict.get(keys[i]);

		for (int j = 0; j < value.getSize(); ++j) {
			out << value[j] << ' ';
		}

		if (i != keys.getSize() - 1) {
			out << '\n';
		}
	}
}

double getValue(int n) {
	return n;
}

bool isnull(int n) {
	return n == 0;
}

double getValue(double n) {
	return n;
}

bool isnull(double n) {
	return n == 0;
}

int main() {
	int dataResponse = dataMenu();

	if (dataResponse == 1) {
		while (true) {
			int optionResponse = optionMenu();

			if (optionResponse != 6) {
				runOptions<int>(optionResponse, getValue, isnull, 0);
			}
			else {
				return 0;
			}
		}
	}
	else if (dataResponse == 2) {
		while (true) {
			int optionResponse = optionMenu();

			if (optionResponse != 6) {
				runOptions<double>(optionResponse, getValue, isnull, 0);
			}
			else {
				return 0;
			}
		}
	}

	return 0;
}