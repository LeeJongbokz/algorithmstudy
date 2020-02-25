#include <iostream>
#include <cmath>

#define MAX 1000000

using namespace std;

int check[MAX] = {0};

int A, P;

void dfs(int x){
    
    check[x] += 1;
    
    if(check[x] == 3){
        return;
    }
    
    int next = 0; 
    
    while(x!=0){
        next += pow((x%10), P);
        x /= 10;
    }
    
    dfs(next);
    
}



int main(){
    
    cin >> A >> P;
    
    dfs(A);
    
    int cnt = 0; 
    
    for(int i=1; i<=MAX; i++){
        if(check[i] == 1){
            cnt++;
        }
    }
    
    cout << cnt;
    
    
    
    
}
