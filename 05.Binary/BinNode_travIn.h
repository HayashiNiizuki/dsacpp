#pragma once

template <typename T>
void goAlongVine(BinNodePosi<T> x, Stack<BinNodePosi<T>> &S) {
    while (x) {
        S.push(x);
        x = x->lc;
    }
}

template <typename T>
template <typename VST> //中序遍历
void BinNode<T>::travIn(VST &visit) {
    Stack<BinNodePosi<T>> S;
    BinNodePosi<T> t = this;
    goAlongVine(t, S);
    while (!S.empty()) {
        t = S.pop();
        visit(t->data);
        goAlongVine(t->rc, S);
    }
}