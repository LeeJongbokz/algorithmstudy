#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    int map[110][110] = {0};
    
    map[1][1] = 0; 
    
    for(int i=2; i<=m; i++){
        map[i][1] = 1;
    }
    
    for(int j=2; j<=n; j++){
        map[1][j] = 1;
    }
    
    int len = puddles.size();
    
    for(int i=0; i<len; i++){
        int x = puddles[i][0];
        int y = puddles[i][1];
        
        if(x == 1){
            
            for(int i=y; i<=n; i++){
                map[1][i] = 0;
            }
            
        }else if(y == 1){
         
            for(int i=x; i<=m; i++){
                map[i][1] = 0;
            }
            
        }else{
           map[x][y] = -1;   
        }
        
        
    }
    
    for(int i=2; i<=m; i++){
        for(int j=2; j<=n; j++){
            
            if(map[i][j] == -1){
                map[i][j] = 0;
                continue;
            }
            
            map[i][j] = map[i-1][j] + map[i][j-1]; 
            map[i][j] %= 1000000007;
        }
    }
    
    answer = map[m][n];
    
    return answer;
}
