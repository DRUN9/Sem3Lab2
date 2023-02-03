#pragma once

#include <stdexcept>

#define INDEX_OUT_OF_RANGE_MSG "index is out of range"
#define ZERO_SIZE_MSG "size is 0"
#define NEGATIVE_SIZE_MSG "size is negative"

using namespace std;

template <typename T> class LinkedList {
private:
	struct ListElem {
		T item;
		ListElem* next = nullptr;
	};

	ListElem* head = nullptr;
	int size = 0;

public:
	LinkedList() {
		this->size = 0;
	}

	LinkedList(T* items, int count) {
		if (count < 0) {
			throw length_error(NEGATIVE_SIZE_MSG);
		}

		if (count == 0) {
			throw length_error(ZERO_SIZE_MSG);
		}

		ListElem** ptr = &(this->head);

		for (int i = 0; i < count; ++i) {
			*ptr = new ListElem;
			(*ptr)->item = items[i];
			ptr = &((*ptr)->next);
		}

		this->size = count;
	}

	LinkedList(const LinkedList<T>& list) {
		ListElem* ptr = list.head;
		ListElem** newPtr = &(this->head);

		for (int i = 0; i < list.size; ++i, ptr = ptr->next) {
			*newPtr = new ListElem;
			(*newPtr)->item = ptr->item;
			newPtr = &((*newPtr)->next);
		}

		this->size = list.size;
	}

	~LinkedList() {
		ListElem* ptr = this->head;
		ListElem* next;

		while (ptr != nullptr) {
			next = ptr->next;
			delete ptr;
			ptr = next;
		}

		this->size = 0;
	}

	T get(int index) const {
		if (index >= this->size || index < 0) {
			throw out_of_range(INDEX_OUT_OF_RANGE_MSG);
		}

		ListElem* ptr;

		int i = 0;
		ptr = this->head;

		while (i < index) {
			++i;
			ptr = ptr->next;
		}

		return ptr->item;
	}

	T getFirst() const {
		return this->get(0);
	}

	T getLast() const {
		return this->get(this->getLength() - 1);
	}

	LinkedList<T>& getSublist(int startIndex, int endIndex) const {
		if (startIndex >= this->size || endIndex >= this->size || startIndex < 0 || endIndex < 0) {
			throw out_of_range(INDEX_OUT_OF_RANGE_MSG);
		}

		if (startIndex >= endIndex) {
			throw logic_error("startIndex must be less than endIndex");
		}

		LinkedList<T>* newList = new LinkedList<T>();

		for (int i = startIndex; i < endIndex; ++i) {
			newList->append(this->get(i));
		}

		return *newList;
	}

	int getLength() const {
		return this->size;
	}

	void append(T item) {
		ListElem** ptr = &(this->head);

		while (*ptr != nullptr) {
			ptr = &((*ptr)->next);
		}

		(*ptr) = new ListElem;
		(*ptr)->item = item;

		this->size++;
	}

	void prepend(T item) {
		ListElem* ptr = new ListElem{ item, this->head };
		this->head = ptr;

		this->size++;
	}

	void set(T item, int index) {
		if (index >= this->size || index < 0) {
			throw out_of_range(INDEX_OUT_OF_RANGE_MSG);
		}

		ListElem preHead;
		preHead.next = this->head;
		ListElem* ptr;

		int i = 0;
		ptr = &preHead;

		while (i < index) {
			++i;
			ptr = ptr->next;
		}

		ptr->next = new ListElem{ item, ptr->next->next };
		this->head = preHead.next;
	}

	void insertAt(T item, int index) {
		if (index >= this->size || index < 0) {
			throw out_of_range(INDEX_OUT_OF_RANGE_MSG);
		}

		ListElem preHead;
		preHead.next = this->head;
		ListElem* ptr;

		int i = 0;
		ptr = &preHead;

		while (i < index) {
			++i;
			ptr = ptr->next;
		}

		ptr->next = new ListElem{ item, ptr->next };
		this->head = preHead.next;

		this->size++;
	}

	void removeAt(int index) {
		if (index >= this->size || index < 0) {
			throw out_of_range(INDEX_OUT_OF_RANGE_MSG);
		}

		ListElem preHead;
		preHead.next = (ListElem*)this->head;
		ListElem* ptr;

		int i = 0;
		ptr = &preHead;

		while (i < index) {
			++i;
			ptr = ptr->next;
		}

		ptr->next = ptr->next->next;

		this->head = preHead.next;
		this->size--;
	}

	void concat(LinkedList<T>& list) {
		for (int i = 0; i < list.getLength(); ++i) {
			this->append(list.get(i));
		}
	}

	T& operator[](int index) {
		if (index >= this->size || index < 0) {
			throw out_of_range(INDEX_OUT_OF_RANGE_MSG);
		}

		ListElem* ptr;

		int i = 0;
		ptr = this->head;

		while (i < index) {
			++i;
			ptr = ptr->next;
		}

		return ptr->item;
	}

	LinkedList<T>& operator=(const LinkedList<T>& list) {
		ListElem* ptr = list.head;
		ListElem** newPtr = &(this->head);

		for (int i = 0; i < list.size; ++i, ptr = ptr->next) {
			*newPtr = new ListElem;
			(*newPtr)->item = ptr->item;
			newPtr = &((*newPtr)->next);
		}

		this->size = list.size;

		return *this;
	}
};