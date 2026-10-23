// 3. Знайти добуток ненульових елементів кожної непарної стрічки
#include <iostream>

using namespace std;

int main(){
    int m,n;
    cout << "Введіть m, n: " << endl;
    cin >> m >> n;

    if (m < 1 || n < 1){
        cout << "m, n > 0";
        return 1;
    }

    double **a = new double*[m];

    for (int i = 0; i < m; ++i){
        a[i] = new double[n];
    }

    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            cout << "Введіть " << "[" << i+1 << "][" << j+1 << "]" << " елемент" << endl;
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i+=2){
        double prod = 1;
        bool has_el = false;
        for (int j = 0; j < n; j++){
            if (a[i][j] != 0){
                prod *= a[i][j];
                has_el = true;
            }
        }
        if (has_el){
            cout << "Добуток рядка " << i+1 << " = " << prod << endl;
        }
        else{
            cout << "У рядку " << i+1 << " всі елементи = 0" << endl;
        }
    }

    for (int i = 0; i < m; ++i){
        delete[] a[i];
    }

    delete[] a;

    return 0;
}