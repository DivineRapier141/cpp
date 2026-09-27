#include <iostream>
#include <cmath>

using namespace std;


int main(){
    double *side = new double; 
    double *angle = new double;

    cout << "Enter lenght of the side: ";
    cin >> *side;
    cout << "Enter any angle of the rhomb: ";
    cin >> *angle;

    double *radians = new double;
    *radians = *angle * (M_PI/180);

    double *area = new double;
    *area = pow(*side,2) * sin(*radians);
    double *perimeter = new double;
    *perimeter = *side * 4;

    cout << "Area: "<<*area<<"\nPerimeter: "<< *perimeter;
    
    delete side;
    delete angle;
    delete radians;
    delete area;
    delete perimeter;

    return 0;
}