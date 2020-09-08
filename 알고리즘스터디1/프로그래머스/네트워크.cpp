// 30분

#include <string>
#include <vector>
#include <cstring> 

using namespace std;

bool check[210];

void dfs(int a, int b, vector<vector<int>>& computers){
    
    check[a] = true;
    check[b] = true;
    
    for(int i=0; i<computers[b].size(); i++){
        if(check[i] == false && computers[b][i] == 1){
            dfs(b, i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    memset(check, false, sizeof(check));
    
    int network = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){
                continue;
            }else{
                if(check[i] == false && check[j] == false && computers[i][j] == 1){
                    dfs(i,j,computers);
                    network += 1;
                }
            }
        }
    }
    
    for(int i=0; i<n; i++){
        if(check[i] == false){
            network += 1;
        }
    }
    
    
    int answer = network;
    return answer;
}
