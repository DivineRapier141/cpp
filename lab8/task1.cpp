#include <iostream>
#include <cmath>
using namespace std;


double integrate(double (*f)(double), double a, double b, int n){
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        sum += f(a + i * h);
    }
    return h * sum;
}

double f1(double x){
    return x * x + x + 1;
}

double f2(double x){
    return exp(2 * x);
}

double f3(double x){
    return 1.0 / sqrt(x + 1);
}

int main(){
    int n = 1000;

    double res1 = integrate(f1, 0, 2, n);
    double res2 = integrate(f2, 0, 1, n);
    double res3 = integrate(f3, 0, 3, n);

    double total = res1 + res2 + res3;

    cout << "Integral 1 = " << res1 << "\n";
    cout << "Integral 2 = " << res2 << "\n";
    cout << "Integral 3 = " << res3 << "\n";
    cout << "Total = " << total;

    return 0;
}