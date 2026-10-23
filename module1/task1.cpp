// 1. Знайти найбільше із трьох значень f (x) , f (2x) та f (3x), де f (x)
// sin(x). Значення аргументу вводиться із клавіатури у градусах, тому
// перед обчисленням функції перевести їх у радіани.

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double angle;
    cout << "Введіть значення кута: ";
    cin >> angle;

    double rads = angle * M_PI / 180.0;

    double f1 = sin(rads);
    double f2 = sin(2 * rads);
    double f3 = sin(3 * rads);

    double max = f1;

    if (max < f2) max = f2;
    if (max < f3) max = f3;

    cout << "Найбільше: " << max << endl;
    
    return 0;
}