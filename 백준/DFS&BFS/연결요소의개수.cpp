#include <iostream>
#include <vector>

using namespace std;

vector<int> a[1001];
bool check[1001] = {0};

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
    
    int N, M;
    cin >> N >> M;
    
    
    for(int i=0; i<M; i++){
        int u,v;
        cin >> u >> v;
        
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    int cnt = 0; 
    
    for(int i=1; i<=N; i++){
        if(check[i] == false){
            cnt++;
            dfs(i);
        }
    }
    
    cout << cnt;
    
    
    
    
}
