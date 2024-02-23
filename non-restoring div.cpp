#include <stdio.h>
#include <stdlib.h>

#define N 8

void non_restoring_division(int dividend[], int divisor[], int quotient[]) {
    int temp[N+1];
    int neg_divisor[N+1];
    int borrow = 0;
    for (int i = 0; i < N+1; i++) {
        temp[i] = 0;
        neg_divisor[i] = (i == 0) ? 0 : (divisor[i-1] == 0) ? 1 : 0;
    }
    for (int i = 0; i < N; i++) {
        quotient[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = N; j > 0; j--) {
            temp[j] = temp[j - 1];
        }
        temp[0] = dividend[i];
        for (int j = 0; j < N+1; j++) {
            temp[j] -= (neg_divisor[j] ^ borrow);
            if (temp[j] < 0) {
                temp[j] += 2;
                borrow = 1;
            } else {
                borrow = 0;
            }
        }
        quotient[i] = borrow ? 0 : 1;
        if (borrow) {
            borrow = 0;
            for (int j = 0; j < N+1; j++) {
                temp[j] += neg_divisor[j];
            }
        }
    }
}
int main() {
    int dividend[N] = {1, 1, 0, 1, 0, 1, 0, 1}; 
    int divisor[N] = {1, 0, 1, 1, 0, 0, 1, 0};  
    int quotient[N]; 
    non_restoring_division(dividend, divisor, quotient);
    printf("Quotient: ");
    for (int i = 0; i < N; i++) {
        printf("%d", quotient[i]);
    }
    printf("\n");

    return 0;
}
