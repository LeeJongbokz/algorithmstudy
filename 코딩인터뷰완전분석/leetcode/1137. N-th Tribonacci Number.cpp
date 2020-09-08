// 10분

#include <cstring>

class Solution {
public:
    
    int a[110];
    
    int recursive(int n){
        
        a[0] = 0;
        a[1] = 1;
        a[2] = 1;
        
        for(int i=3; i<=n; i++){
            a[i] = a[i-1]+a[i-2]+a[i-3];
        }
        
        return a[n];
        
    }
    
    
    int tribonacci(int n) {
        
        memset(a, 0, sizeof(a));
        
        int result = recursive(n);
        
        return result;
    }
};
