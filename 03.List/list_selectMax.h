#pragma once

template <typename T>
ListNodePosi<T> List<T>::selectMax(ListNodePosi<T> p, int n) {
    ListNodePosi<T> maxp = p;
    ListNodePosi<T> q = p;
    while (--n) {
        if ((q = q->succ)->data > maxp->data)
            maxp = q;
    }
    return maxp;
}