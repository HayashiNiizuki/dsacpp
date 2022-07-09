#pragma once

template <typename T> T Vector<T>::remove(Rank r) {
    T a = _elem[r];
    for (int i = r + 1; i < _size; i++)
        _elem[i - 1] = _elem[i];
    _size--;
    shrink();
    return a;
}