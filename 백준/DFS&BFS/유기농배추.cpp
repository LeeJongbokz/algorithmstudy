#include <iostream>

using namespace std;

int M, N, K;
int map[60][60]={0};
bool check[60][60] = {0};

int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

bool isInside(int x, int y){
    if((0<=x) && (x<N) && (0<=y) && (y<M)){
        return true;
    }else{
        return false; 
    }
}


void dfs(int x, int y){
    
    check[x][y] = true;
    
    for(int i=0; i<4; i++){
        
        int dy = x + dir[i][0];
        int dx = y + dir[i][1];
        
          if(isInside(dy,dx) && map[dy][dx] == 1 && check[dy][dx]== false){
                        dfs(dy, dx);
          }
    }
    
}




int main(){
    
      int T;
      cin >> T;
    
      for(int i=1; i<=T; i++){
          
            int cnt = 0; 
          
            cin >> M >> N >> K;
          
            for(int j=0; j<60; j++){
                for(int k=0; k<60; k++){
                    map[j][k] = 0;
                }
            }
          
            for(int j=0; j<60; j++){
                for(int k=0; k<60; k++){
                    check[j][k] = false;
                }
            }
          
          
            for(int j=1; j<=K; j++){
                  int X, Y;
                  cin >> X >> Y;
                  map[Y][X] = 1;
            }
          
            for(int j=0; j<N; j++){
                for(int k=0; k<M; k++){
                if(map[j][k] == 1 && check[j][k] == false){
                     dfs(j, k);
                     cnt++; 
                }
               }
            }
          
            cout << cnt << '\n'; 
          
      }
    
    
    
}






