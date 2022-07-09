#pragma once

template <typename T> struct BinNode;
template <typename T> using BinNodePosi = BinNode<T> *;

template <typename T> struct BinNode {
    T data;
    BinNodePosi<T> parent, lc, rc;
    int height;
    // construct
    BinNode() : parent(nullptr), lc(nullptr), rc(nullptr), height(0) {}
    BinNode(T e, BinNodePosi<T> pa = nullptr, BinNodePosi<T> l = nullptr,
            BinNodePosi<T> r = nullptr, int h = 0)
        : data(e), parent(pa), lc(l), rc(r), height(h) {}
    //操作接口
    int size(); //统计当前节点后代总数，亦即以其为根的子树的规模
    BinNodePosi<T> insertAsLC(T const &); //作为当前节点的左孩子插入新节点
    BinNodePosi<T> insertAsRC(T const &); //作为当前节点的右孩子插入新节点
    BinNodePosi<T> succ();                //取当前节点的直接后继
    template <typename VST> void travLevel(VST &); //子树层次遍历
    template <typename VST> void travPre(VST &); //子树先序遍历
    template <typename VST> void travIn(VST &);   //子树中序遍历
    template <typename VST> void travPost(VST &); //子树后序遍历
};

#include "BinNode_implementation.h"