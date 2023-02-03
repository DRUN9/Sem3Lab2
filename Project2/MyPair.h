#pragma once

using namespace std;

template <typename T1, typename T2> class MyPair {
private:
	T1 first;
	T2 second;
public:
	MyPair() {}

	MyPair(T1 first, T2 second) {
		this->first = first;
		this->second = second;
	}

	int getFirst() {
		return this->first;
	}

	int getSecond() {
		return this->second;
	}

	bool operator==(MyPair<T1, T2> myPair) {
		return this->first == myPair.first && this->second == myPair.second;
	}
};

template<typename T1, typename T2> ostream& operator<<(ostream& out, MyPair<T1, T2>& myPair) {
	out << "( " << myPair.first() << ' ' << myPair.second() << " )";
}