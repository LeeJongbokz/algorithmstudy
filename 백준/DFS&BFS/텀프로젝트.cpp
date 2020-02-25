#include <iostream>
#include <cstring>

using namespace std;

int T, n, cnt;
bool isVisited[100010] = {0};
bool isFinished[100010] = {0};
int vertex[100010];

void dfs(int curr_v){
    
     isVisited[curr_v] = true;
     int next_v = vertex[curr_v];
    
     if(!isVisited[next_v]){
         dfs(next_v);
     }else{
         
         if(!isFinished[next_v]){
             
             for(int x=next_v; x!=curr_v; x=vertex[x]){
                    cnt++;
             }
             cnt++;
         }
     }
     
     isFinished[curr_v] = true;
    

    
}


int main(){
    
    cin >> T;
    
    for(int i=1; i<=T; i++){
        
         cin >> n;
        
         memset(vertex, false, sizeof(vertex));
         memset(isVisited, false, sizeof(isVisited));
         memset(isFinished, false, sizeof(isFinished));
        
         for(int j=1; j<=n; j++){
             cin >> vertex[j];
         }
        
         cnt = 0; 
         
         for(int j=1; j<=n; j++){
             if(!isVisited[j]){
                  dfs(j);
             }
         }
        
         cout << n-cnt << '\n';
           
    }
    
    
    
}







