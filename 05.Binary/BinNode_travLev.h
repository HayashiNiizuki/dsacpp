#pragma once

template <typename T>
template <typename VST>
void BinNode<T>::travLevel(VST &visit) {
    Queue<BinNodePosi<T>> lvQu;
    lvQu.enqueue(this);
    BinNodePosi<T> t;
    while (!lvQu.empty()) {
        t = lvQu.dequeue();
        visit(t->data);
        if (t->lc)
            lvQu.enqueue(t->lc);
        if (t->rc)
            lvQu.enqueue(t->rc);
    }
}