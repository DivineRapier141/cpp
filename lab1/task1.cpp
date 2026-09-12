#include <iostream>
#include <cmath>

using namespace std;


int main(){
    double side, angle;
    const double PI = 3.1415926535;

    cout << "Enter lenght of the side: ";
    cin >> side;
    cout << "Enter any angle of the rhomb: ";
    cin >> angle;

    double radians = angle * (PI/180);

    double area = pow(side,2) * sin(radians);
    double perimeter = side * 4;

    cout << "Area: "<<area<<"\nPerimeter: "<< perimeter;
    
    return 0;
}