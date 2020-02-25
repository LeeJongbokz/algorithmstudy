#include <iostream>
#include <algorithm> 

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int a[1010][3]={0};
    int minSum[1010][3] = {0};
    
    for(int i=0; i<N; i++){
        int num1, num2, num3;
        cin >> num1 >> num2 >> num3;
        
        a[i][0] = num1;
        a[i][1] = num2;
        a[i][2] = num3;
    }
    
    minSum[0][0] = a[0][0];
    minSum[0][1] = a[0][1];
    minSum[0][2] = a[0][2];
    
    for(int i=1; i<=N-1; i++){
        minSum[i][0] = min(a[i][0]+minSum[i-1][1], a[i][0]+minSum[i-1][2]);
        minSum[i][1] = min(a[i][1]+minSum[i-1][0], a[i][1]+minSum[i-1][2]);
        minSum[i][2] = min(a[i][2]+minSum[i-1][0], a[i][2]+minSum[i-1][1]);
    }
    
    int result = min(minSum[N-1][0], minSum[N-1][1]);
    result = min(result , minSum[N-1][2]);
    
    cout << result;
    
    
    
    
    
    
}
