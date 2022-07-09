#pragma once

template <typename T> List<T>::List(ListNodePosi<T> p, int n) {
    copyNodes(p, n);
}

template <typename T> List<T>::List(List<T> const &L) {
    copyNodes(L.first(), L._size);
}

template <typename T> List<T>::List(List<T> const &L, int r, int n) {
    ListNodePosi<T> p = L.first();
    while (0 < r--)
        p = p->succ;
    copyNodes(p, n);
}