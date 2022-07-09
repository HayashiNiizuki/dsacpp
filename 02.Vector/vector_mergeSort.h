#pragma once

template <typename T> void Vector<T>::mergeSort(Rank lo, Rank hi) {
    if (hi - lo < 2)
        return;
    Rank mi = (hi + lo) >> 1;
    mergeSort(lo, mi);
    mergeSort(mi, hi);
    merge(lo, mi, hi);
}