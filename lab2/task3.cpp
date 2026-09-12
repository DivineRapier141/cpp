#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x1, x2, x3, y1, y2, y3;
    cout << "Enter coords of A (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter coords of B (x2 y2): ";
    cin >> x2 >> y2;
    cout << "Enter coords of C (x3 y3): ";
    cin >> x3 >> y3;

    double sideAB = sqrt(pow(x1 - x2, 2) + (pow(y1 - y2, 2)));
    double sideAC = sqrt(pow(x1 - x3, 2) + (pow(y1 - y3, 2)));
    double sideBC = sqrt(pow(x2 - x3, 2) + (pow(y2 - y3, 2)));

    string result;

    if(sideAB >= sideAC && sideAB >= sideBC){
        result = "AB";
    }
    else if(sideAC >= sideAB && sideAC >= sideBC){
        result = "AC";
    }
    else{
        result = "BC";
    }

    cout << "Longest side: " <<result;
    return 0;
}