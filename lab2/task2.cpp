#include <iostream>

using namespace std;

int main(){
    int y;
    double n;

    cout << "Enter n: ";
    cin >> n;
    
    if(0 <= n && n < 5){
        y = 0;
    }
    else if(5 <= n && n < 10){
        y = 1;
    }
    else if(10 <=n && n < 15){
        y = 2;
    }
    else{
        y = 3;
    }

    cout << "y = "<< y;

    return 0;
}