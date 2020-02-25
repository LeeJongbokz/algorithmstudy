#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100001];
bool check[100001]={0};
int parent[100001];


void findParent(int x){
    
    check[x] = true;
    
    
    for(int i=0; i<tree[x].size(); i++){
        int y = tree[x][i];
        
        if(check[y] == false){
             parent[y] = x;
             findParent(y);
        }
    }
    
    
}





int main(){
    
    int N;
    cin >> N;
    
    
    for(int i=1; i<=N; i++){
        int u, v;
        cin >> u >> v;
        
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    
    findParent(1);
    
    for(int i=2; i<=N; i++){
        cout << parent[i] << '\n';
    }
    
    
}


