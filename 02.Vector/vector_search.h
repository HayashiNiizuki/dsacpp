#pragma once

template <typename T>
Rank Vector<T>::search(T const &e, Rank lo, Rank hi) const {
    Rank mi;
    while (lo < hi) {
        mi = (hi + lo) >> 1;
        if (_elem[mi] > e)
            hi = mi;
        else
            lo = mi + 1;
    }
    return --lo;
}