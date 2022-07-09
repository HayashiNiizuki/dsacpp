#pragma once

template <typename T> //更新节点x高度
int BinTree<T>::updateHeight(BinNodePosi<T> x) {
    return x->height = 1 + max(stature(x->lc), stature(x->rc));
} //具体规则，因树而异

template <typename T> //更新高度
void BinTree<T>::updateHeightAbove(BinNodePosi<T> x) {
    while (x) {
        updateHeight(x);
        x = x->parent;
    }
} //从x出发，覆盖历代祖先。可优化