#pragma once

template <typename T> ListNodePosi<T> ListNode<T>::insertAsPred(T const &e) {
    ListNodePosi<T> a = new ListNode(e, pred, this);
    pred->succ = a;
    pred = a;
    return a;
}