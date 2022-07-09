#pragma once

#include "../03.List/list.h"

template <typename T> class Queue : public List<T> {
  public:
    void enqueue(T const &e) { this->insertAsLast(e); }
    T dequeue() { return this->remove(this->first()); };
    T front() { return this->first()->data; }
    T rear() { return this->last()->data; }
};