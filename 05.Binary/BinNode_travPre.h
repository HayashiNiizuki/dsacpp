#pragma once

template <typename T, typename VST>
void visitAlongVine(BinNodePosi<T> LTree, VST &visit,
                    Stack<BinNodePosi<T>> &S) {
    while (LTree) {
        visit(LTree->data);
        S.push(LTree->rc);
        LTree = LTree->lc;
    }
}

template <typename T>
template <typename VST> //先序遍历
void BinNode<T>::travPre(VST &visit) {
    Stack<BinNodePosi<T>> S;
    S.push(this);
    while (!S.empty()) {
        visitAlongVine(S.pop(), visit, S);
    }
}