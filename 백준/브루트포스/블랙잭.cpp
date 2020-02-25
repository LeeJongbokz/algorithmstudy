#include <iostream>

using namespace std;

int N, M;
int a[110] = {0};
int minGap = 99999999;
int gap = 0; 
int sum = 0;
int result = 0; 
bool check[110] = {0};

void recursive(int index){
    
    if( index >= 3){
        
        gap = M - sum;
        
        if(minGap >= gap && gap >= 0){
            minGap = gap;
            result = sum;
        }
        return;
    }
    
    for(int i=1; i<=N; i++){
        if(check[i] == false){
            check[i] = true;
            sum += a[i];
            recursive(index+1);
            sum -= a[i];
            check[i] = false;
        }
    }
    
}



int main(){
    
    cin >> N >> M;
    
    for(int i=1; i<=N; i++){
        cin >> a[i];
    }
    
    recursive(0);
    
    cout << result;
  
    
    
}
