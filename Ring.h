
#pragma once

#include <cassert>

template<typename type>

class RingArray {
public:
	RingArray(size_t init_capacity) {
		size = 0;
		index = 0;
		capacity = init_capacity;
		data = new type[init_capacity];
		if (!data) {
			std::cerr << "Ring Array Heap Allocation Failed\n";
			assert(false);
		}
	}

	~RingArray() {
		delete[] data;
	}

	void push(const type& element) {
		if (size >= capacity) {
			std::cerr << "Attempted to Exceed Capacity of Ring Array\n";
			assert(false);
		}
		data[(index + size) % capacity] = element;
	}

	void clear() {
		size = 0;
	}

private:
	size_t size;
	size_t index;
	size_t capacity;
	type* data = nullptr;
};

