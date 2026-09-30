#include <iostream>

using namespace std;

int main(){
    const int MAX_N = 15;
    int n;
    int a[MAX_N][MAX_N];
    bool has_identical_row = false;
    bool has_even_col = false;

    cout << "Введіть розмірність матриці n (n < 15): ";
    cin >> n;

    if (n <= 0 || n > MAX_N) {
        cout << "Помилка: некоректне значення n!" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Введіть елемент " << "[" << i+1 << "][" << j+1 <<"]" << endl;
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n;i++){
        int count = 0;
        for (int j = 0; j < n - 1; j++){
            if (a[i][j] == a[i][j+1]){
                count++;
            }
        }
        if (count == n-1){
            cout << "Рядок " << i+1 << " складається з однакових чисел" << endl;
            has_identical_row = true;
        }
    }

    for (int i = 0; i < n ; i++){
        int count = 0;
        for (int j = 0; j < n; j++){
            if (a[j][i] % 2 == 0){
                count++;
            }
        }
        if (count == n){
            cout << "Стовпчик " << i + 1 << " складається з парних чисел" << endl;
            has_even_col = true;
        }
    }

    if (!has_identical_row){
        cout << "Немає рядків з однакових чисел" << endl;
    }

    if (!has_even_col){
        cout << "Немає стовпчиків з парних чисел" << endl;
    }
    
    return 0;
}
