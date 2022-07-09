#pragma once

template <typename T> void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {
    Rank i = 0;
    T *A = _elem + lo;
    Rank j = 0, lb = mi - lo;
    T *B = new T[lb];
    for (Rank i = 0; i < lb; i++)
        B[i] = A[i];
    Rank k = 0, lc = hi - mi;
    T *C = _elem + mi;
    while ((j < lb) && (k < lc))
        A[i++] = (B[j] <= C[k]) ? B[j++] : C[k++];
    while (j < lb)
        A[i++] = B[j++];
    delete[] B;
}