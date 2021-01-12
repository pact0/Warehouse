#pragma once
#include <iostream>
#include <string>
#include "exceptions/OutOfBoundsException.h"
#include "exceptions/NonPositiveSize.h"

template<typename T>
class basic_vector {
private:
    unsigned int _size;
    unsigned int _capacity;
    T * buffer;
public:
    basic_vector();
    explicit basic_vector(unsigned int size);
    explicit basic_vector(unsigned int size, const T & initial);
    basic_vector(const basic_vector<T> & v);
    ~basic_vector();

    unsigned int capacity() const { return _capacity; };
    unsigned int size() const { return _size; };
    bool empty() const { return !_size; };
    void clear();
    T * begin() const { return &buffer[0]; };
    T * end() const { return &buffer[_size]; };
    T * begin() { return &buffer[0]; };
    T * end() { return &buffer[_size]; };

    T * cbegin() const { return &buffer[0]; };
    T * cend() const { return &buffer[_size]; };

    T & front() const { return buffer[0]; };
    T & back() const { return buffer[_size]; };
    T & front() { return buffer[0]; };
    T & back() { return buffer[_size]; };

    void push_back(const T & value);
    void pop_back();

    void reserve(unsigned int capacity);

    T & operator[](unsigned int index);
    T & operator[](unsigned int index) const;
    basic_vector<T> & operator=(const basic_vector<T> &);

};

template<typename T>
basic_vector<T>::basic_vector() {
    _capacity = 0;
    _size = 0;
    buffer = 0;
}

template<typename T>
basic_vector<T>::basic_vector(unsigned int size) {
    if ( size <= 0 )
        throw NonPositiveSize(size);
    _capacity = size;
    _size = 0;
    buffer = static_cast<T*>(::operator new (sizeof(T) * _capacity));
}

template<typename T>
basic_vector<T>::basic_vector(unsigned int size, const T &initial) {
    if ( size <= 0 )
        throw NonPositiveSize(size);
    _capacity = size;
    _size = 0;
    buffer = ::operator new (sizeof(T) * _capacity);
    for (int i = 0; i < size; i++)
        buffer[i] = initial;
}

template<typename T>
basic_vector<T>::basic_vector(const basic_vector <T> &v) {
    delete[ ] buffer;
    _size = v._size;
    _capacity = v._capacity;
    buffer = ::operator new (sizeof(T) * _capacity);
    for (int i = 0; i < _size; i++)
        buffer[i] = v.buffer[i];
}

template<typename T>
basic_vector<T>::~basic_vector() {
    clear();
    ::operator delete(buffer);
}

template<typename T>
void basic_vector<T>::clear() {
    for (int i = 0; i < _size; i++) {
        buffer[i].~T();
    }
    _size=0;
}

template<typename T>
void basic_vector<T>::push_back(const T &value) {
    if ( _size == _capacity ) {
        reserve(2 * ( size() + 1) );
    }
    ::new (buffer+ _size++) T{ value };
}

template<typename T>
void basic_vector<T>::pop_back() {
    if( !empty() ) {
    buffer[_size-1].~T();
    _size--;
    }
}

template<typename T>
void basic_vector<T>::reserve(unsigned int capacity) {
    _capacity = capacity;
    T* temp = static_cast<T*>(::operator new (sizeof(T)*_capacity));
    for (int i = 0; i < _size ; ++i) {
        temp[i] = buffer[i];
    }
    ::operator delete(buffer);
    buffer = temp;
}

template<typename T>
T &basic_vector<T>::operator[](unsigned int index) {
    if (index < 0) {
        if (index < -_size) {
            std::cout << "Array index out of bound, exiting";
            throw OutOfBoundsException(index);
        }
        }
        if (index >= _size) {
            std::cout << "Array index out of bound, exiting";
            throw OutOfBoundsException(index);
        }

    return buffer[index];
}

template<typename T>
T &basic_vector<T>::operator[](unsigned int index) const {
    if (index < 0) {
        if (index < -_size) {
            std::cout << "Array index out of bound, exiting";
            throw OutOfBoundsException(index);
        }
    }
    if (index >= _size) {
        std::cout << "Array index out of bound, exiting";
        throw OutOfBoundsException(index);
    }

    return buffer[index];
}


template<typename T>
basic_vector<T> & basic_vector<T>::operator=(const basic_vector<T> &) {
this->clear();
this->_capacity = v.capacity();
for (auto &item : v)
    this->push_back(item);
}

