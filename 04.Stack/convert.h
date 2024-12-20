#pragma once

void convert(Stack<char> &S, int n, int base) {
    static char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                           '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (n > 0) {
        S.push(digit[n % base]);
        n /= base;
    }
}