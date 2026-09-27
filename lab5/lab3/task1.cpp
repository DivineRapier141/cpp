#include <iostream>
#include <cmath>

using namespace std;

int main(){
    unsigned int *n = new unsigned int;
    unsigned long long *s = new unsigned long long;
    *s = 1;
    cout << "Enter a number: ";
    cin >> *n;
    for(int i = 1;i<=*n;i++){
        *s *= pow(i, i-1);
    }
    cout << "S = " << *s << endl;

    delete n;
    delete s;
    
    return 0;
}