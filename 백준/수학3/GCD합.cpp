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
    
    int T;
    cin >> T;
    
    for(int i=1; i<=T; i++){
        int n;
        cin >> n;
        
        int a[1000010] = {0};
        
        for(int j=0; j<n; j++){
            cin >> a[j];
        }
        
        long long sum = 0; 
        
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                int gcd = GCD(a[j], a[k]);
                sum += gcd; 
            }
        }
  
        cout << sum << '\n';
        
    }
    
    
    
}
