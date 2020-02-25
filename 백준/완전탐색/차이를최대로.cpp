#include <iostream>
#include <algorithm>

using namespace std;

bool check[100] = {0};
int a[100]={0};
int result[100]={0};
int gap[100]={0};
int maxSum = -987654321;
int N;
int sum = 0;

void recursive(int index){
    
    if(index >= N){
        for(int i=1; i<N; i++){
            gap[i] = abs(result[i] - result[i-1]);
            sum += gap[i];
        }
        if(maxSum < sum){
            maxSum = sum;
        }
        sum = 0;
        return;
        
    }
    
    
    for(int i=0; i<N; i++){
        
        if(check[i] == false){
            check[i] = true;
            result[index] = a[i];
            recursive(index+1);
            result[index] = 0;
            check[i] = false;
        }
    }
      
    
}


int main(){
    
    cin >> N;
   
    
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    
    recursive(0);
    
    cout << maxSum; 
        
    
}
