#include <stdio.h>

int fibonacci(int n, int *result) {
    if(n == 1 || n == 2) {
        return 1;
    } else {
        return fibonacci(n - 1, result) + fibonacci(n - 2, result);
    }
}

int total(int n, int *result) {
    int total_fib, fib;
    if(n == 1) {
        printf("1");
        return 1;
    } else {
        int fib = fibonacci(n, result);
        int total_fib = total(n - 1, result);
        printf(" + %d", fib);
        return fib + total_fib;
    }
}

int main(){
    int n, result;
    result = 0;

    printf("Masukkan nilai n: ");
    scanf("%d", &n);
    printf(" = %d", total(n, &result));
}