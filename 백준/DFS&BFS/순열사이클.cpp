#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

vector<int> a[1001];
bool check[1001]={0};


void dfs(int x){
    
    check[x] = true;
    
    for(int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        
        if(check[y] == false){
               dfs(y);
        }
    }
    
    
}



int main(){
    
    int T;
    cin >> T;
    
    
    for(int i=0; i<T; i++){
        
        memset(check, false, sizeof(check));
        
        for(int j=1; j<=1000; j++){
            a[j].clear();
        }
        
        int N;
        cin >> N;
        
        
        for(int j=1; j<=N; j++){
            int u;
            cin >> u;
            
            a[j].push_back(u);
        }
        
        
        int cnt = 0; 
        
        
        for(int j=1; j<=N; j++){
            
            if(check[j] == false){
                cnt++;
                dfs(j);
            }
        }
        
        
        cout << cnt << '\n';
       
        
    }
    
    
    
    
}
