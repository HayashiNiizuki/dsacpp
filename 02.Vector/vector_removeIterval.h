#pragma once

template <typename T> int Vector<T>::remove(Rank lo, Rank hi) {
    while (hi < _size)
        _elem[lo++] = _elem[hi++];
    _size = lo;
    shrink();
    return hi - lo;
}