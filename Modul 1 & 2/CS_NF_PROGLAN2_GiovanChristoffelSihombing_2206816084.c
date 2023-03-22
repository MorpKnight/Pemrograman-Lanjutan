#include <stdio.h>
#include <math.h>

float integral(float x, int n_kali) {
    return (n_kali == 1) ? 1 :(float) x/(n_kali) * integral(x, n_kali -1);
}
int main(){
    int x, n_kali;
    printf("x: ");
    scanf("%d", &x);
    printf("x akan diintegralkan sebanyak: ");
    scanf("%d", &n_kali);
    float hasil = integral(x, n_kali);
    printf("\n%.2f", hasil);
    return 0;
}