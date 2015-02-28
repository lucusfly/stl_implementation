#ifndef JIA_VECTOR_H
#define JIA_VECTOR_H

namespace jia {

    template<typename T>
    class Vector {
        typedef int size_type;
        typedef T* iterator;
        typedef const T* const_iterator;
        
        private:
            size_type _size;
            size_type _capacity;
            T* _array;

        public:
            Vector();
            Vector(size_type);
            Vector(size_type, const T&);
            Vector(const Vector<T>&);
            ~Vector();
            Vector<T>& operator=(const Vector<T>&);

            Vector<T>::size_type size() const { return _size; }
            Vector<T>::size_type capacity() const { return _capacity; }
            bool empty() const { return _size == 0; }

            T& operator[](size_type index ) { return *(_array+index); }
            const T& operator[](size_type index) const { return *(_array+index); }

            T& front() { return *_array; }
            const T& front() const { return *_array; }
            T& back() { return *(_array+_size-1); }
            const T& back() const { return *(_array+_size-1); }

            void push_back(const T&);
            void pop_back();
            void clear();

            Vector<T>::iterator begin() { return _array; }
            Vector<T>::const_iterator begin() const { return _array; }
            Vector<T>::iterator end() { return _array+size; }
            Vector<T>::const_iterator end() const { return _array+size; }

            //void erase(iterator it);
            //void erase(iterator begin, iterator end);
            //void insert(iterator it, const T& value);

    };

    template<typename T>
    Vector::Vector():_size(0),_capacity(0),_array(NULL) {};

    template<typename T>
    Vector::Vector(size_type cap):_size(0),_capacity(cap) {
        _array = allocate<T>(cap);
    }

    template<typename T>
    Vector::Vector(size_type cap, const T& ele) {
        _size = cap;
        _capacity = cap;
        _array = allocate<T>(cap);

        for (size_type i = 0; i < cap; ++i)
            construct(_array+i, ele);
    }

    template<typename T>
    Vector::Vector(const Vector<T> &v) {
        _size = v._size;
        _capacity = v._capacity;
        _array = allocate<T>(_capacity);

        for (size_type i = 0; i < size(); ++i) {
            construct(_array+i, v[i]);
        }
    }

    Vector::~Vector() {
        if (_array != NULL) 
            delete[] _array;
    }
}

#endif
