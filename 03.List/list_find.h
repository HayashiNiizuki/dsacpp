#pragma once

template <typename T>
ListNodePosi<T> List<T>::find(T const &e, int n, ListNodePosi<T> p) const {
    while (n--) {
        p = p->pred;
        if (p->data == e)
            return p;
    }
    return nullptr;
}