#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

vector<int> a[110];
bool check[110];
int cnt = 0; 

void dfs(int x){
    
    check[x] = true;
    cnt += 1;
    
    for(int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        if(check[y] == false){
            dfs(y);
        }
    }
}


int main(){
    
    int N, C;
    cin >> N >> C;
    
    for(int i=1; i<=C; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    memset(check, false, sizeof(check));
    
    dfs(1);
    
    cout << cnt-1;
    
    
}

