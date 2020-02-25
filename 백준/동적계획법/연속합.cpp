#include <iostream>
#include <algorithm> 

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int a[100010]= {0};
    int maxSum[100010] = {0};
    
    for(int i=1; i<=n; i++){
        int num;
        cin >> num;
        a[i] = num;
    }
    
    maxSum[1] = a[1];
    
    for(int i=2; i<=n; i++){
        maxSum[i] = max(maxSum[i-1]+a[i], a[i]);
    }
    
    int maxNum = maxSum[1];
    
    for(int i=2; i<=n; i++){
        maxNum = max(maxNum, maxSum[i]);
    }
    
    cout << maxNum;
    
    
    
    
    
}
