#include <iostream>

using namespace std;

int main(){
    int *y = new int;
    double *n = new double;

    cout << "Enter n: ";
    cin >> *n;
    
    if(0 <= *n && *n < 5){
        *y = 0;
    }
    else if(5 <= *n && *n < 10){
        *y = 1;
    }
    else if(10 <=*n && *n < 15){
        *y = 2;
    }
    else{
        *y = 3;
    }

    cout << "y = "<< *y << endl;

    delete y;
    delete n;

    return 0;
}