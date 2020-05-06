#include <iostream>
#include <vector>
#include <algorithm> 
#include <cstring> 

using namespace std;

int N,M,K;
int map[20][20];
int tempMap[20][20];
int A[20][20];
vector<int> tree[20][20];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1};


bool isRange(int x, int y){
    if(1<=x && x<=N && 1<=y && y<=N){
        return true;
    }else{
        return false; 
    }
}


void breed(int x, int y){
    
    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(isRange(nx, ny)){
            tree[nx][ny].push_back(1);
        }
    }
    
}





void spring(){
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            
            sort(tree[i][j].begin(), tree[i][j].end());
            
            int len = tree[i][j].size();
            bool die = false;
            int diePos = 0;
            
            for(int k=0; k<len; k++){
                int age = tree[i][j][k];
                
                if(map[i][j]>=age){
                    map[i][j] -= age;
                    tree[i][j][k] += 1;
                }else{
                    die = true;
                    diePos = k;
                    break;
                }
            }
            
            if(die == true){
                int total = 0; 
                
                int deleteNum = len - diePos;
                
                while(deleteNum--){
                    total += (tree[i][j].back()/2);
                    tree[i][j].pop_back();
                }
                
                tempMap[i][j] = total;
            }
            
        }
    }
}


void summer(){
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            map[i][j] += tempMap[i][j];
        }
    }
    
    memset(tempMap, 0, sizeof(tempMap));
}


void fall(){
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int len = tree[i][j].size();
            
            for(int k=0; k<len; k++){
                int age = tree[i][j][k];
                
                if(age % 5 == 0){
                    breed(i,j);
                }
            }
        }
    }
}


void winter(){
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            map[i][j] += A[i][j];
        }
    }
}







int main(){
    
    memset(map, 0, sizeof(map));
    memset(tempMap, 0, sizeof(tempMap));
    
    cin >> N >> M >> K;
    
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            map[i][j] = 5;
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> A[i][j]; 
        }
    }
    
    
    for(int i=1; i<=M; i++){
        int x,y,z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }
    
    while(K--){
        
        spring();
        summer();
        fall();
        winter();
    }
    
    int alive = 0;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            alive += tree[i][j].size(); 
        }
    }
    
    cout << alive; 
    
    
    
}
