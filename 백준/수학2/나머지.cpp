#include <iostream>

using namespace std;

int main(){
    
    int A, B, C;
    cin >> A >> B >> C;
    
    int result1;
    int result2;
    int result3;
    int result4; 
    
    result1 = (A+B)%C;
    result2 = (A%C + B%C) % C;
    result3 = (A*B) % C;
    result4 = ((A%C)*(B%C))%C;
    
    cout << result1 << '\n';
    cout << result2 << '\n';
    cout << result3 << '\n';
    cout << result4 << '\n';
    
    
}
