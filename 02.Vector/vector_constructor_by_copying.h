#pragma once

template <typename T> void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi) {
    _elem = new T[_capacity = 2 * (hi - lo)];
    for (_size = 0; lo < hi; _size++, lo++)
        _elem[_size] = A[lo];
}