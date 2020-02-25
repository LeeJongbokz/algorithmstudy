#include <iostream>
#include <queue>

using namespace std;

int N, M;

int map[101][101];
int check[101][101] = {0};

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isInside(int x, int y){
    if((0<=x) && (x<N) && (0<=y) && (y<M)){
        return true;
    }else{
        return false;
    }
}


void bfs(int x, int y){
    
    check[x][y] = 1;
    
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        if( (x == N-1) && (y == M-1)){break;}
        
        
        for(int i=0; i<4; i++){
            
            int dy = x + dir[i][0];
            int dx = y + dir[i][1];
            
            if(isInside(dy, dx)== true && map[dy][dx] == 1 && check[dy][dx]== 0){
                check[dy][dx] = check[x][y] + 1;
                q.push(make_pair(dy, dx));
            }
            
        }
        
    }
    
    
}



int main(){
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        
        string num;
        cin >> num;
        
        for(int j=0; j<M; j++){
            map[i][j] = num[j] - '0';
        }
        
    }
    
    bfs(0, 0);
    
    
    cout << check[N-1][M-1];
     
    
}
