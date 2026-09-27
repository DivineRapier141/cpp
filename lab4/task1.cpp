#include <iostream>   
using namespace std;

int main(){
    const int MAX_LEN = 500;
    long double product = 1;
    long double sum = 0;
    int n;
    double a[MAX_LEN];
    bool has_repeating = false;
    bool has_non_repeating = false;
    cout << "Enter len of array (n <= 500): ";
    cin >> n;

    if(n<=0 || n>MAX_LEN){
        cout << "Incorrect n.";
        return 1;
    }

    for(int i = 0;i < n;i++){
        cout << "Enter "<< i+1 << " element: ";
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if (a[i] == a[j]){
                count++;
            }
        }

        if (count > 1){
            product *= a[i];
            has_repeating = true;
        } else {
            sum += a[i];
            has_non_repeating = true;
        }
    }

    if (!has_repeating){
        cout << "Немає чисел, що повторюються" << endl;
    } else {
        cout << "product: " << product << endl;
    }

    if (!has_non_repeating){
        cout << "Немає чисел, що не повторюються" << endl;
    } else {
        cout << "sum: " << sum << endl;
    }

    return 0;

}