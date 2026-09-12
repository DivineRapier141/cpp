#include <iostream>
#include <cmath>

using namespace std;

int main(){
    unsigned int n;
    unsigned long long s = 1;
    cout << "Enter a number: ";
    cin >> n;
    for(int i = 1;i<=n;i++){
        s *= pow(i, i-1);
    }
    cout << "S = " << s;
    return 0;
}