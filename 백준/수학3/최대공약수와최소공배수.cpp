#include <iostream>

using namespace std;

int GCD(int a, int b){
    int r = a % b;
    
    if(r == 0){
        return b;
    }else{
        return GCD(b, a%b);
    }
}



int main(){
    
    int A,B;
    cin >> A >> B;
    
    int lcm, gcd;
    
    gcd = GCD(A, B);
    lcm = (A*B) / gcd;
    
    cout << gcd << '\n';
    cout << lcm;
    
    
    
    
    
}
