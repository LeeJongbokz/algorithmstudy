#include <iostream>

using namespace std;

int main(){
    
    
    int a[20];
    
    a[1]=1;
    a[2]=2;
    a[3]=4;
    
    for(int i=4; i<=10; i++){
        a[i] = a[i-1]+a[i-2]+a[i-3];
    }
    
    int T;
    cin >> T;
    
    for(int i=1; i<=T; i++){
        
        int n;
        cin >> n;
        
        cout << a[n]<< '\n';        
        
    }
    
    
    
    
    
    
}
