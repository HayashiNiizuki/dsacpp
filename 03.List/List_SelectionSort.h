#pragma once

template <typename T> void List<T>::selectionSort(ListNodePosi<T> p, int n) {
    ListNodePosi<T> tail = p;
    for (int i = 0; i < n; i++)
        tail = tail->succ;
    while (--n) {
        ListNodePosi<T> max = selectMax(p->pred->succ, n + 1);
        insert(remove(max), tail);
        tail = tail->pred;
    }
}