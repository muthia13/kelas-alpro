 #include <stdio.h>

double f(double x)
{
    return 2 * x + 3;
}

double trapezoidal(double a, double b, int n)
{
    double h = (b - a) / n;
    double s = f(a) + f(b);

    for (int i = 1; i < n; i++)
        s += 2 * f(a + i * h);

    return (h / 2) * s;
}

int main()
{
    double a = -1, b = 4;
    int n;
    
    printf("Masukkan batas bawah: ");
    scanf("%f", &a);
    printf("Masukkan batas atas: ");
    scanf("%f", &b);
    printf("Masukkan jumlah blok (N): ");
    scanf("%d", &n);
    

    printf("Hasil integral: %.6lf\n", trapezoidal(a, b, n));

    return 0;
}