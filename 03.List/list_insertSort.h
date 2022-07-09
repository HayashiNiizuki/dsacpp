#pragma once

template <typename T> //对列表中起始于位置p、宽度为n的区间做插入排序
void List<T>::insertionSort(ListNodePosi<T> p, int n) {
    for (int i = 0; i < n; i++) {
        insert(search(p->data, i, p), p->data);
        p = p->succ;
        remove(p->pred);
    }
}