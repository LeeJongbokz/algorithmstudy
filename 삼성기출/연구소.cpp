#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int map[20][20];
int tempMap[20][20];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool check[20][20];
int maxSafeZone = -1; 

bool isRange(int x, int y){
    
    if(1<=x && x<=N && 1<=y && y<=M){
        return true;
    }else{
        return false; 
    }
}


void dfs(int x, int y){
    
    check[x][y] = true;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if( (isRange(nx, ny)) && (tempMap[nx][ny] == 0) &&  (check[nx][ny] == false)){
            check[nx][ny] = true;
            tempMap[nx][ny] = 2;
            dfs(nx, ny);
        }
        
    }
    
    
}




void virusSpread(){
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if( (tempMap[i][j] == 2) && (check[i][j] == false) ){
                dfs(i,j);
            }
        }
    }
    
    
    
    
}

int getSafeZone(){
   
    int safeZone = 0;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(tempMap[i][j] == 0){
                safeZone += 1;
            }
        }
    }
    return safeZone; 
}





void recursive(int x, int y, int toPick){
    
    if(toPick == 0){
        
         for(int i=1; i<=N; i++){
             for(int j=1; j<=M; j++){
                 tempMap[i][j] = map[i][j];
             }
         }
         memset(check, false, sizeof(check)); 
        
         virusSpread();
         int safeZone = getSafeZone();
          
         if(maxSafeZone < safeZone){
             maxSafeZone = safeZone;
         }
         return;
    }
    
    
    
    
    for(int i=x; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(( map[i][j] == 0)){
                map[i][j] = 3;
                recursive(i, j, toPick-1);
                map[i][j] = 0; 
            }
        }
    }
    
    
       
}



int main(){
    
    cin >> N >> M;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
        }
    }
    
    recursive(1, 1, 3);
    
    cout << maxSafeZone;
    
    
}

