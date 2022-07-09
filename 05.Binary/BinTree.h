#pragma once

#include "BinNode.h"

template <typename T> class BinTree {
  protected:
    BinNodePosi<T> _root;
    int _size;
    virtual int updateHeight(BinNodePosi<T> x); //更新节点x的高度
    void updateHeightAbove(BinNodePosi<T> x); //更新节点x及其祖先的高度
  public:
    BinTree() : _size(0), _root(nullptr) {}               //构造函数
    ~BinTree() { if (0 < _size) remove(_root); }          //析构函数
    int size() const { return _size; }                    //规模
    bool empty() const { return !_root; }                 //判空
    BinNodePosi<T> root() const { return _root; }         //树根
    BinNodePosi<T> insert(T const &);                     //插入根节点
    BinNodePosi<T> insert(T const &, BinNodePosi<T>);     //插入左孩子
    BinNodePosi<T> insert(BinNodePosi<T>, T const &);     //插入右孩子
    BinNodePosi<T> attach(BinTree<T> *&, BinNodePosi<T>); //接入左子树
    BinNodePosi<T> attach(BinNodePosi<T>, BinTree<T> *&); //接入右子树
    int remove(BinNodePosi<T>);                           //子树删除
    BinTree<T> *secede(BinNodePosi<T>);                   //子树分离
};

#include "BinTree_implementation.h"