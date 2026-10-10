#include <iostream>
using namespace std;

long long getX(int i) {
    if (i == 0) return 0;
    if (i == 1 || i == 2) return 9;
    return getX(i - 1) + 4 * getX(i - 3);
}

int main() {
    int n;
    cout << "Введіть n: ";
    cin >> n;

    cout << "x" << n << " = " << getX(n) << endl;

    return 0;
}