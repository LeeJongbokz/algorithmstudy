#include <iostream>
#include <cmath>

using namespace std; 

int main(){
    
    int R;
    cin >> R;
    
    double area1;
    double area2;
    
    area1 = M_PI * R * R;
    area2 = 2*R*R;
    
    cout << fixed;
    cout.precision(5);
    cout << area1 << '\n';
    cout << area2;
    
}
