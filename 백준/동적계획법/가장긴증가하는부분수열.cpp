#include <iostream>
#include <algorithm> 

using namespace std;

int N;
int A[1010];
int cache[1010];
int longest = -1; 

int lis(int start){
    
    int ret = cache[start];
    
    if(ret != -1){
        return ret;
    }
    
    ret = 1;
    
    for(int next = start+1; next<N; next++){
        
        if(A[start] < A[next]){
            ret = max(ret, lis(next)+1);
        }
    }
    
    return cache[start] = ret;
        
}


int main(){
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    
    for(int i=0; i<N; i++){
        
        for(int j=0; j<N; j++){
            cache[j] = -1;
        }
        
        int result = lis(i);
        
        if(longest < result){
           longest = result; 
        }
        
    }
    
    cout << longest; 
    
}
