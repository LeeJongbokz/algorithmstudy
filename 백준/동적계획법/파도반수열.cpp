#include <iostream>

using namespace std;

int main(){
    
    long long a[110] = {0};
    
    a[1] = 1;
    a[2] = 1;
    a[3] = 1;
    a[4] = 2;
    a[5] = 2;
    
    for(int i=6; i<=100; i++){
        a[i] = a[i-1] + a[i-5];
    }
    
    
    int T;
    cin >> T;
    
    for(int i=1; i<=T; i++){
        
        int N;
        cin >> N;
        
        cout << a[N] << '\n';
        
    }
      
    
}
