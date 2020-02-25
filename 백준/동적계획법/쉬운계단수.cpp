#include <iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int a[110][110] = {0};
    
    for(int i=0; i<=9; i++){
        if(i == 0){
            a[1][i] = 0;
        }else{
            a[1][i] = 1;
        }
    }
    
    for(int i=2; i<=N; i++){
        
        for(int j=0; j<=9; j++){
            if(j == 0){
                a[i][j] = a[i-1][j+1];
                a[i][j] %= 1000000000;
            }else if(j == 9){
                a[i][j] = a[i-1][j-1];
                a[i][j] %= 1000000000;
            }else{
                a[i][j] = a[i-1][j-1]+a[i-1][j+1];
                a[i][j] %= 1000000000;
            }
        }
        
    }
    
    long long sum = 0; 
    
    
    for(int i=0; i<=9; i++){
        sum += a[N][i];
    }
    
    cout << sum % 1000000000;
    
    
    
    
    
    
    
    
    
}
