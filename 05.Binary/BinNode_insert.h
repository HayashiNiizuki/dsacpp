#pragma once

template <typename T> BinNodePosi<T> BinNode<T>::insertAsLC(T const &e) {
    return this->lc = new BinNode(e, this);
}

template <typename T> BinNodePosi<T> BinNode<T>::insertAsRC(T const &e) {
    return this->rc = new BinNode(e, this);
}