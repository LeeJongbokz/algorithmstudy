#include <string>
#include <vector>

using namespace std;

vector<int> a[210];
bool check[210] = {0};    

void dfs(int x){
    
    check[x] = true;
    
       for(int i=0; i<a[x].size(); i++){
             int y = a[x][i];
           
             if(check[y] == false){
                   dfs(y);
             }
       }
}

int solution(int n, vector<vector<int>> computers) {
    
    int answer = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j && computers[i][j] == 1){
                a[i].push_back(j);
            }
        }
    }
    
    for(int i=0; i<n; i++){
        if(check[i] == false){
            answer++;
            dfs(i);
        }
    }
    
    return answer;
}
