#pragma once

template <typename T> int Vector<T>::uniquify() { // Sorted Vector
    int num = 1;
    for (int i = 1; i < _size; i++) {
        if (_elem[i] > _elem[i - 1]) {
            _elem[num++] = _elem[i];
        }
    }
    num = _size - num;
    _size -= num;
    shrink();
    return num;
}