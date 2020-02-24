#include <iostream>

using namespace std;

int main(){
    
    int a;
    int b;
    cin >> a >> b;
    
    int hundred;
    int ten;
    int one;
    
    int newA=0;
    int newB=0;
    
    hundred = a/100;
    ten = (a/10)%10;
    one = a%10;
    
    newA = 100*one+10*ten+hundred;
    
    hundred = b/100;
    ten = (b/10)%10;
    one = b%10;
    
    newB = 100*one+10*ten+hundred;
    
    if(newA < newB){
        cout << newB;
    }else{
        cout << newA;
    }
    
    
    
}
