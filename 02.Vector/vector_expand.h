#pragma once

template <typename T> void Vector<T>::expand() {
    if (_size < _capacity)
        return;
    _capacity = max(_capacity, DEFAULT_CAPACITY);
    T *oldelem = _elem;
    _elem = new T[_capacity <<= 1];
    for (int i = 0; i < _size; i++)
        _elem[i] = oldelem[i];
    delete[] oldelem;
}
