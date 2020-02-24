#include <iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    int a[20][20] = {0};
    
    for(int i=1; i<=14; i++){
         a[0][i] = i;
    }
    
    for(int i=1; i<=14; i++){
        
        for(int j=1; j<=14; j++){
            for(int k=1; k<=j; k++){
                a[i][j] += a[i-1][k];
            }
        }
    }
    
    
    
    for(int i=1; i<=T; i++){
        int k, n;
        cin >> k >> n;
        
        cout << a[k][n] << '\n';
    }
    
    
    
    
    
}
