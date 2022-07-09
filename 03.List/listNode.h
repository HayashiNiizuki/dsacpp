#pragma once

using Rank = int; //��
template <typename T> struct ListNode;
template <typename T> using ListNodePosi = ListNode<T>*; //�б�ڵ�λ��
template <typename T> struct ListNode { //�б�ڵ�ģ���ࣨ��˫��������ʽʵ�֣�
// ��Ա
   T data; ListNodePosi<T> pred; ListNodePosi<T> succ; //��ֵ��ǰ�������
// ���캯��
   ListNode() {} //���header��trailer�Ĺ���
   ListNode ( T e, ListNodePosi<T> p = nullptr, ListNodePosi<T> s = nullptr )
      : data ( e ), pred ( p ), succ ( s ) {} //Ĭ�Ϲ�����
// �����ӿ�
   ListNodePosi<T> insertAsPred ( T const& e ); //������ǰ�ڵ�֮ǰ�����½ڵ�
   ListNodePosi<T> insertAsSucc ( T const& e ); //���浱ǰ�ڵ�֮������½ڵ�
};

#include "listNode_implementation.h"