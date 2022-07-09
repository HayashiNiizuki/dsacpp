#pragma once

template <typename T> T &List<T>::operator[](Rank r) const {
    ListNodePosi<T> x = first();
    while (0 < r--)
        x = x->succ;
    return x->data;
}