#ifndef _HEAP_H_
#define _HEAP_H_

#include <iterator>

using namespace std;

template<typename RandomAccessIterator>
bool isheap(RandomAccessIterator first, RandomAccessIterator last) {
    int len = last - first;
    for (int i = len/2-1; i >= 0; --i) {
        int child = 2*i+2;
        if (child < len && *(first+i) < *(first+child))
            return false;
        if (--child < len && *(first+i) < *(first+child))
            return false;
    }
    
    return true;
}

template<typename RandomAccessIterator>
void heapify(RandomAccessIterator first, RandomAccessIterator last, int i) {
    typedef typename iterator_traits<RandomAccessIterator>::value_type value_type;

    value_type value = *(first+i);

    int parent = i;
    int child = 2*i + 2;
    int len = last - first;

    while( child < len) {
        if (*(first+child) < *(first+child-1)) 
            child--;

        if (*(first+child) < value) 
            break;

        *(first+parent) = *(first+child);
        parent = child;
        child = 2*parent + 2;
    }

    if (child == len && value < *(first+child-1)) {
        *(first+parent) = *(first+child-1);
        parent = child-1;
    }

    *(first+parent) = value;
}

template<typename RandomAccessIterator>
void makeHeap(RandomAccessIterator first, RandomAccessIterator last) {
    int len = last - first;

    for (int i = len/2-1; i >= 0; --i) {
        heapify(first, last, i);
    }
}

template<typename RandomAccessIterator>
void popHeap(RandomAccessIterator first, RandomAccessIterator last) {
    typedef typename iterator_traits<RandomAccessIterator>::value_type value_type;

    value_type temp = *(first);
    *(first) = *(last-1);
    *(last-1) = temp;

    heapify(first, last-1, 0);
}

template<typename RandomAccessIterator>
void heapSort(RandomAccessIterator first, RandomAccessIterator last) {
    makeHeap(first, last);

    int len = last - first;

    for (int i = 0; i < len-1; ++i) {
        popHeap(first, last-i);
    }
}

#endif
