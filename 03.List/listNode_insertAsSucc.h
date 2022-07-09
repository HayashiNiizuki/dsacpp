#pragma once

template <typename T> ListNodePosi<T> ListNode<T>::insertAsSucc(T const &e) {
    ListNodePosi<T> a = new ListNode(e, this, succ);
    succ->pred = a;
    succ = a;
    return a;
}