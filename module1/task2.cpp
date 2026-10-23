// 2. Обчислити суму непарних елементів в заданому масиві a(а[1], а[2],
// ...,а[n]) та їх кількість.

#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Введіть кількість елементів: ";
    cin >> n;

    if (n < 1){
        cout << "Має бути більше нуля";
        return 1;
    }

    int *a = new int[n];

    for (int i = 0; i < n; ++i){
        cout << "Введіть " << i+1 << " елемент: " << endl;
        cin >> a[i];
    }

    int sum = 0;
    int count = 0;

    for (int i = 0; i < n; ++i){
        if (a[i] % 2 != 0){
          sum += a[i];
          count ++;
        }
    }

    cout << "Сума = " << sum << ", кількість: " << count << endl;

    delete[] a;


    return 0;
}