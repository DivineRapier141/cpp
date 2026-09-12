#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    double a, b, c;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;

    double result = min(a,b) + pow(max(b,c), 2);

    cout << result;

    return 0;
}
