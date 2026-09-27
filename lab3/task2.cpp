#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x, epsilon;
    cout << "Enter x (x>1): ";
    cin >> x;
    cout << "Enter epsilon: ";
    cin >> epsilon;

    if(x <= 1){
        cout << "x must be > 1";
        return 0;
    }

    double sum = M_PI / 2.0;
    double a = -1.0 / x;
    int n = 0;
    while (a > epsilon || a < -epsilon) {
        sum += a;
        a *= -(2.0 * n + 1.0) / ((2.0 * n + 3.0) * x * x);
        n++;
    }

    cout << "Approx arctg(" << x << ") = " << sum << "\n";
    cout << "Real arctg(" << x << ") = " << atan(x) << "\n";
    cout << "Iterations: " << n << "\n"; 
    
    return 0;
}
