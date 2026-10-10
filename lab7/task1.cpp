#include <iostream>
#include <cmath>
using namespace std;

float max(float x, float y, float z){
    float m = x;
    if(m<y) m = y;
    if(m<z) m = z;
    return m;
}

int main(){
    float x,y,z;
    cin >> x >> y >> z;
    float result = (max(x,y,z)+max(x+y,x*y,4.0*z))/(max(pow(max(x+y,x*y,pow(x,2)),2),7.0,pow(z,2)));
    cout << result;
    return 0;
}