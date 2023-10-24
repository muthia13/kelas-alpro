#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int num1, num2;

    printf("Masukkan dua bilangan bulat: ");
    scanf("%d ,%d", &num1, &num2);

    num1 = (num1 < 0) ? -num1 : num1;
    num2 = (num2 < 0) ? -num2 : num2;

    int hasil = gcd(num1, num2);

    printf("GCD dari %d dan %d adalah %d \n", num1, num2, hasil);

    return 0;
}
