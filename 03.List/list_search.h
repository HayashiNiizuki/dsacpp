#pragma once

//在有序列表内节点p（可能是trailer）的n个（真）前驱中，找到不大于e的最后者
template <typename T>
ListNodePosi<T> List<T>::search(T const &e, int n, ListNodePosi<T> p) const {
    do {
        p = p->pred;
        n--;
    } while ((n > -1) && (e < p->data));
    return p;
}