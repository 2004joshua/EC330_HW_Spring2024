#ifndef HEAP_SEARCH_H
#define HEAP_SEARCH_H

#include <iostream>
#include <functional>
#include <vector>

template <typename T>
void swap(T *x, T *y) {
	T temp = *x;
	*x = *y;
	*y = temp;
}

// You can customize your min heap with different types of elements and their comparator
template <typename T, typename Compare = std::less<T> > 
class MinHeap {
	T *arr;  // pointer to the array representation
	int size;   // current number of items
	int capacity;  // maximum number of items the heap can store
	Compare compare; // comparator
public:
	MinHeap(int cap, Compare comparator = Compare()) {
		size = 0;
		capacity = cap;
		arr = new T[cap];
		compare = comparator;
	}
	MinHeap(const std::vector<T> &items, int cap, Compare comparator = Compare()) {
		size = items.size();
		capacity = cap;
		compare = comparator;
		if (size >= capacity)
        	throw std::overflow_error("Heap capacity exceeded");
        arr = new T[cap];
		for (int i = 0; i < size; i++) {
            arr[i] = items[i];
        }
        // Heapify the array to build the min heap
        for (int i = (size - 2) / 2; i >= 0; --i) {
            heapify(i);
        }

	}
	int get_size() {
		return size;
	}
	int get_capacity() {
		return capacity;
	}
	T* get_array() {
		return arr;
	}
	int parent(int i) {return (i-1)/2;}
	int left_child(int i) {return (2*i+1);}
	int right_child(int i) {return (2*i+2);}
	T get_min() {return arr[0];}
    T extract_min() {
        if (size <= 0)
            throw std::out_of_range("Heap is empty");

        T root = arr[0];
        arr[0] = arr[size - 1]; // swap root with the last element and remove it
        size--;

        // Heapify (bubble down) to maintain the min heap property
        heapify(0);

        return root;
    }
	void insert(T item) {
		if (size >= capacity)
            throw std::overflow_error("Heap is full");

        size++;
        int i = size - 1;
        arr[i] = item;

        // bubble up to maintain the min heap property
        bubble_up(i);
    }

	T get_kth_smallest(int k);  // This is the method that you need to implement

	// Destructor to free allocated memory
    ~MinHeap() {
        delete[] arr;
    }

private:
    void bubble_up(int i) {
        while (i > 0 && compare(arr[i], arr[parent(i)])) {
            std::swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        while (true) {
            int left = left_child(i);
            int right = right_child(i);
            int smallest = i;

            if (left < size && compare(arr[left], arr[smallest]))
                smallest = left;

            if (right < size && compare(arr[right], arr[smallest]))
                smallest = right;

            if (smallest != i) {
                std::swap(arr[i], arr[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }

};


#endif