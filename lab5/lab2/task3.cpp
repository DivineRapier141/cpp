#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
    double *x1 = new double;
    double *y1 = new double;
    double *x2 = new double;
    double *y2 = new double;
    double *x3 = new double;
    double *y3 = new double;

    cout << "Enter coords of A (x1 y1): ";
    cin >> *x1 >> *y1;
    cout << "Enter coords of B (x2 y2): ";
    cin >> *x2 >> *y2;
    cout << "Enter coords of C (x3 y3): ";
    cin >> *x3 >> *y3;

    double *sideAB = new double;
    double *sideAC = new double;
    double *sideBC = new double;

    *sideAB = sqrt(pow(*x1 - *x2, 2) + pow(*y1 - *y2, 2));
    *sideAC = sqrt(pow(*x1 - *x3, 2) + pow(*y1 - *y3, 2));
    *sideBC = sqrt(pow(*x2 - *x3, 2) + pow(*y2 - *y3, 2));

    string *result = new string;

    if(*sideAB >= *sideAC && *sideAB >= *sideBC){
        *result = "AB";
    }
    else if(*sideAC >= *sideAB && *sideAC >= *sideBC){
        *result = "AC";
    }
    else{
        *result = "BC";
    }

    cout << "Longest side: " << *result << endl;

    delete x1;
    delete y1;
    delete x2;
    delete y2;
    delete x3;
    delete y3;
    delete sideAB;
    delete sideAC;
    delete sideBC;
    delete result;

    return 0;
}