#ifndef JIA_MEMORY_H
#define JIA_MEMORY_H
#include <new>

namespace jia {

    template<typename T>
    inline T* allocate(size_t n) {
        return (T*)(::operator new(n*sizeof(T)));
    }

    template<typename T>
    inline deallocate(T* buff) {
        ::operator delete(buff);
    }

    template<typename T>
    inline void construct(T* p, const T& value) {
        return new (p) T(value);
    }

    template<typename T>
    inline void construct(T* p) {
        return new (p) T();
    }

    template<typename T>
    inline void destroy(T* p) {
        p->~T();
    }

    template<typename T>
    inline void destroy(T* start, T* end) {
        while(start != end) {
            destory(start++);
        }
    }

    template<typename InputIter, typename ForwardIter>
    inline ForwardIter copy_range(InputIter first, InputIter last, ForwardIter result) {
        while(first != last) {
            construct(&*result++, *first++);
        }

        return result;
    }

    template<typename InputIter, typename ForwardIter, typename Size>
    inline pair<InputIter, ForwardIter> copy_n(InputIter first, ForwardIter result, Size count) {
        for (; count > 0; count--) {
            construct(&*result++, *first++);
        }

        return pair<InputIter, ForwardIter>(first, result);
    }

    template<typename ForwardIter, typename T>
    inline void fill_range(ForwardIter first, ForwardIter end, const T& value) {
        while(first != last) {
            construct(&*first++, value);
        }
    }

    template<typename ForwardIter, typename Size, typename T>
    inline ForwardIter fill_n(ForwardIter first, Size n, const T& value) {
        for (; n > 0; n--) {
            construct(&*first++, value);
        }

        return first;
    }
}

#endif
