#pragma once

template <typename T>
void Vector<T>::sort(Rank lo, Rank hi) { //向量区间[lo, hi)排序
    switch (3) {
    case 1:
        bubbleSort(lo, hi);
        break; //起泡排序
    case 2:
        selectionSort(lo, hi);
        break; //选择排序（习题）
    case 3:
        mergeSort(lo, hi);
        break; //归并排序
    case 4:
        heapSort(lo, hi);
        break; //堆排序（第12章）
    case 5:
        quickSort(lo, hi);
        break; //快速排序（第14章）
    default:
        shellSort(lo, hi);
        break; //希尔排序（第14章）
    } //随机选择算法以充分测试。实用时可视具体问题的特点灵活确定或扩充
}
