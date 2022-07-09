#pragma once

template <typename T> void Vector<T>::quickSort(Rank lo, Rank hi) {
    if (lo >= hi)
        return;
    Rank i = lo;
    Rank j = hi;
    T key = _elem[lo];
    while (true) {
        while (i < hi) {
            if (_elem[i] <= key)
                i++;
            else
                break;
        }
        while (lo < j) {
            if (_elem[j] > key)
                j--;
            else
                break;
        }
        if (i >= j)
            break;
        swap(_elem[i], _elem[j]);
    }
    quickSort(lo, i);
    quickSort(i + 1, hi);
    return;
}