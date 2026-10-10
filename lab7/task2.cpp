#include <iostream>
#include <cmath>
using namespace std;


double getAngleBetweenVectors(double x1, double y1, double x2, double y2){
    double dot = x1 * x2 + y1 * y2;
    double len = sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2);
    double a = dot / len;
    return acos(a) * 180.0 / M_PI; 
}

int main(){
    double xA, yA, xB, yB, xC, yC;
    const double EPS = 1e-9;
    cout << "Введіть координати A, B, C (по 1 за раз): ";
    cout << endl;
    cin >> xA >> yA >> xB >> yB >> xC >> yC;

    double cross = (xB - xA) * (yC - yA) - (yB - yA) * (xC - xA);
    if (fabs(cross) < EPS) {
    cout << "Трикутник не існує\n";
    return 0;
    }

    double ang_a = getAngleBetweenVectors(xB - xA, yB - yA, xC - xA, yC - yA);
    double ang_b = getAngleBetweenVectors(xA - xB, yA - yB, xC - xB, yC - yB);
    double ang_c = getAngleBetweenVectors(xA - xC, yA - yC, xB - xC, yB - yC);
    
    cout << "Кути: A = " << ang_a << ", B = " << ang_b << ", C = " << ang_c << endl;

    double max_ang = ang_a;
    if (ang_b > max_ang) max_ang = ang_b;
    if (ang_c > max_ang) max_ang = ang_c;
    if (fabs(max_ang - 90) < EPS)
        cout << "Трикутник прямокутний\n";
    else if (max_ang > 90)
        cout << "Трикутник тупокутний\n";
    else
        cout << "Трикутник гострокутний\n";

    return 0;
}