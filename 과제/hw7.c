#include <stdio.h>

unsigned long long locker_lower = 0;
unsigned long long locker_upper = 0;

void toggle(int n) {
    if (n < 64) {
        locker_lower ^= (1ULL << n);
    }
    else {
        locker_upper ^= (1ULL << (n - 64));
    }
}

int isOpen(int n) {
    if (n < 64) {
        return (locker_lower >> n ) & 1;
    }
    else {
        return (locker_upper >> (n - 64)) & 1;
    }
}

int main() {
    for (int i = 1; i <= 100; i++) {
        for (int j = i; j <= 100; j += i) {
            toggle(j - 1);
        }
    }

    for (int i = 0; i < 100 ; i++) {
        if (isOpen(i)) {
            printf("%d ", i + 1);
        }
    }

    return 0;
}