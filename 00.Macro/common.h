#pragma once

template <typename T> T max(T a, T b) { return a < b ? b : a; }

template <typename T> void swap(T &a, T &b) {
    T c = b;
    b = a;
    a = c;
}