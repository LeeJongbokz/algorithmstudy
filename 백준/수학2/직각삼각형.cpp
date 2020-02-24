#include <iostream>

using namespace std;

int main(){
    
    
    while(1){
        
        int a,b,c;
        cin >> a >> b >> c;
        
        if(a == 0 && b == 0 && c == 0){
            break;
        }
        
        if(c*c == a*a + b*b || a*a == b*b + c*c || b*b == a*a+c*c){
            cout << "right" << '\n';
        }else{
            cout << "wrong" << '\n';
        }
    }
    
    
    
}
