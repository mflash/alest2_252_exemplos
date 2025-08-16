#ifndef _MAXHEAP_H
#define _MAXHEAP_H

#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <stdexcept>

template <typename T>
class MaxHeap {
private:
    std::vector<T> heap;

    void swim(int k) {
        while (k > 1 && heap[k / 2] < heap[k]) {
            std::cout << "Swap " << heap[k] << " with " << heap[k / 2] << std::endl;
            std::swap(heap[k], heap[k / 2]);
            k = k / 2;
        }
    }

    void sink(int k) {
        int size = heap.size() - 1;
        while (2 * k <= size) {
            int j = 2 * k;
            if (j < size && heap[j] < heap[j + 1])
                j++;
            if (heap[k] >= heap[j])
                break;
            std::cout << "Swap " << heap[k] << " with " << heap[k / 2] << std::endl;
            std::swap(heap[k], heap[j]);
            k = j;
        }
    }

public:
    MaxHeap() {
        heap.push_back(T()); // Placeholder for index 0
    }

    void put(T data) {
        heap.push_back(data);
        swim(heap.size() - 1);
    }

    T get() {
        if (heap.size() <= 1)
            throw std::out_of_range("Heap is empty");
        T res = heap[1];
        heap[1] = heap.back();
        heap.pop_back();
        sink(1);
        return res;
    }

    void sort(T* data, int n) {
        // implemente heapsort!
    }

    void print() const {
        int size = heap.size() - 1;
        int b = 1;
        int elem = 1;
        int sp = 32;

        for (int j = 1; j <= size; j++)
            std::cout << heap[j] << " ";
        std::cout << std::endl;

        while (true) {
            for (int j = 0; j <= sp / 2; j++)
                std::cout << " ";
            for (int i = b; i < b + elem; i++) {
                if (i > size) {
                    std::cout << std::endl;
                    return;
                }
                std::cout << heap[i];
                for (int j = 0; j < sp; j++)
                    std::cout << " ";
            }
            std::cout << std::endl;
            b = b + elem;
            elem = 2 * elem;
            sp = sp / 2;
        }
    }
};
#endif

