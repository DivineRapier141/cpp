#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
using namespace std;

const double EPS = 1e-9;

class StraightLine{
    
    public:
        double coef_a, coef_b, coef_c;

        StraightLine(){
            coef_a = 1.0;
            coef_b = 0.0;
            coef_c = 0.0;
        }

    
        StraightLine(double a, double b, double c){
            assert(fabs(a) > EPS || fabs(b) > EPS);
            coef_a = a;
            coef_b = b;
            coef_c = c;
        }

        void input(){
            double in_a, in_b, in_c;
            do {
            cout << "Введіть коефіцієнти A, B, C (A та B не 0 одночасно): ";
            cin >> in_a >> in_b >> in_c;
            if (fabs(in_a) <= EPS && fabs(in_b) <= EPS) {
                cout << "Помилка: A та B не можуть одночасно дорівнювати 0.\n";
            }
            } while (fabs(in_a) <= EPS && fabs(in_b) <= EPS);

            coef_a = in_a;
            coef_b = in_b;
            coef_c = in_c;
        }

        void print() const {
        cout << coef_a << "*x + " << coef_b << "*y + " << coef_c << " = 0";
        }

        bool hasPoint(double x, double y) const{
            return fabs(coef_a * x + coef_b * y + coef_c) < EPS;
        }

        bool isParallel(const StraightLine& other) const {
            double det = coef_a * other.coef_b - other.coef_a * coef_b;
            return fabs(det) < EPS;
        }

        int intersect(const StraightLine& other, double& outX, double& outY) const {
        cout << "\nОбчислення перетину прямих:\n  L1: "; print();
        cout << "\n  L2: "; other.print(); cout << endl;

        if ((fabs(coef_a) <= EPS && fabs(coef_b) <= EPS) || (fabs(other.coef_a) <= EPS && fabs(other.coef_b) <= EPS)) {
            cout << "Помилка: Одна з прямих має некоректні коефіцієнти (A=0 і B=0).\n";
            return 0;
        }

        double det = coef_a * other.coef_b - other.coef_a * coef_b;
        double detX = coef_b * other.coef_c - other.coef_b * coef_c;
        double detY = other.coef_a * coef_c - coef_a * other.coef_c;

        if (fabs(det) < EPS) {
            if (fabs(detX) < EPS && fabs(detY) < EPS) {
                cout << "Результат: Прямі збігаються.\n";
                return -1;
            }
            cout << "Результат: Прямі паралельні.\n";
            return 0;
        }

        outX = detX / det;
        outY = detY / det;

        if (fabs(outX) < EPS) outX = 0.0;
        if (fabs(outY) < EPS) outY = 0.0;

        cout << "Результат: Одна точка перетину (" << outX << ", " << outY << ")\n";
        return 1;
        }
};

int main(){
    double x = 0, y = 0;

    cout << "=== 1. ВЕРТИКАЛЬНА ТА ГОРИЗОНТАЛЬНА ПРЯМІ ===";
    StraightLine vert(1, 0, -3);
    StraightLine horiz(0, 1, -5);
    vert.intersect(horiz, x, y);

    cout << "\n=== 2. ПАРАЛЕЛЬНІ ВЕРТИКАЛЬНІ ПРЯМІ ===";
    StraightLine vert1(1, 0, -2);
    StraightLine vert2(1, 0, -7);
    vert1.intersect(vert2, x, y);

    cout << "\n=== 3. ЗБІЖНІ ГОРИЗОНТАЛЬНІ ПРЯМІ ===";
    StraightLine horiz1(0, 2, -8);
    StraightLine horiz2(0, 5, -20);
    horiz1.intersect(horiz2, x, y);

    cout << "\n=== 4. ПЕРЕТИН У ПОЧАТКУ КООРДИНАТ ===";
    StraightLine lineA(2, 3, 0);
    StraightLine lineB(1, -1, 0);
    lineA.intersect(lineB, x, y);

    cout << "\n=== 5. ДРОБОВІ КООРДИНАТИ ===";
    StraightLine frac1(3, 4, -5);
    StraightLine frac2(2, -3, 1);
    frac1.intersect(frac2, x, y);

    cout << "\n=== 6. ПЕРЕВІРКА НАЛЕЖНОСТІ ЗНАЙДЕНОЇ ТОЧКИ ===";
    cout << "\nТочка (" << x << ", " << y << ") належить L1: " 
         << (frac1.hasPoint(x, y) ? "Так" : "Ні") << endl;
    cout << "Точка (" << x << ", " << y << ") належить L2: " 
         << (frac2.hasPoint(x, y) ? "Так" : "Ні") << endl;
    return 0;
}