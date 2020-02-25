#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


int V,E;
vector<int> a[20001];
int nodeColor[20001]={0};


void dfs(int x, int num){
    
    nodeColor[x] = num;
    
    for(int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        
        if(nodeColor[y] == 0){
            dfs(y, 3-num);
        }
        
    }
    
}


bool biParte(){
    
    for(int i=1; i<=V; i++){
        for(int j=0; j<a[i].size(); j++){
            int y = a[i][j];
            
            if(nodeColor[i] == nodeColor[y]){
                return false;
            }
        }
    }
    
    return true; 
    
}





int main(){
    
    int K;
    cin >> K;
    
    for(int i=0; i<K; i++){
        
        for(int j=1; j<=20000; j++){
            a[j].clear();
        }
        
        memset(nodeColor, false, sizeof(nodeColor));
        
        cin >> V >> E;
        
        for(int j=1; j<=E; j++){
            int u,v;
            cin >> u >> v;
            
            a[u].push_back(v);
            a[v].push_back(u);
        }
        
        for(int j=1; j<=V; j++){
            if(nodeColor[j] == 0){
                dfs(j, 1);
            }
        }
        
        if(biParte()){
            cout << "YES" <<'\n';
        }else{
            cout << "NO" << '\n';
        }
        
        
        
    }
    
    
    
    
    
}
