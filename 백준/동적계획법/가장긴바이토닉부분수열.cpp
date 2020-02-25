#include <iostream>
#include <algorithm> 

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int a[1010] = {0};
    int maxlen[1010] = {0};
    int maxlen1[1010] = {0};
    int maxlen2[1010] = {0};
    
    for(int i=1; i<=N; i++){
        cin >> a[i];
    }
    
    for(int i=1; i<=N; i++){
        maxlen1[i] = 1;
    }
    
    for(int i=1; i<=N; i++){
        maxlen2[i] = 1;
    }
    
    
    for(int i=1; i<=N; i++){
        
        for(int j=1; j<i; j++){
            if(a[j] < a[i] && maxlen1[j] == maxlen1[i]){
                maxlen1[i] += 1;
            }
        }
    }
    
    
    for(int i=N; i>=1; i--){
        
        for(int j=N; j>i; j--){
            if(a[j] < a[i] && maxlen2[j] == maxlen2[i]){
                maxlen2[i] += 1;
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        maxlen[i] = maxlen1[i] + maxlen2[i] - 1;
    }
    
    int maxNum = maxlen[1];
    
    for(int i=2; i<=N; i++){
        maxNum = max(maxNum, maxlen[i]);
    }
    
    cout << maxNum;
    
    
    
    
    
    
     
    
    
}
