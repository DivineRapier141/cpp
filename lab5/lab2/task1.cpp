#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    double *a = new double;
    double *b = new double;
    double *c = new double;
    cout << "Enter a: ";
    cin >> *a;
    cout << "Enter b: ";
    cin >> *b;
    cout << "Enter c: ";
    cin >> *c;

    double *result = new double; 
    *result = min(*a,*b) + pow(max(*b,*c), 2);

    cout << *result << endl;

    delete a;
    delete b;
    delete c;
    delete result;

    return 0;
}
