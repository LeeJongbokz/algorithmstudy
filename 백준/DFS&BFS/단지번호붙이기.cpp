#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int map[30][30];
bool check[30][30];

vector<int> v;
int TOWN = 0;
int CNT = 0; 

int dir[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1}};

bool isInside(int x, int y){
    if( 0<= x && x <N && 0<=y && y <N){
        return true;
    }else{
        return false;
    }
}


void dfs(int x, int y){
    
    check[x][y] = true;
    CNT += 1;
    
    for(int i=0; i<4; i++){
        int dy = x + dir[i][0];
        int dx = y + dir[i][1];
        
        if(map[dy][dx] == 1 && check[dy][dx] == false && isInside(dy,dx)){
               dfs(dy, dx);
        }
    }
}



int main(){
    
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        
        for(int j=0; j<N; j++){
            map[i][j] = str[j] - '0';
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] == 1 && check[i][j] == false){
                TOWN += 1;
                CNT = 0;
                dfs(i,j);
                v.push_back(CNT);
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    cout << TOWN << '\n';
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
    
    
    
    
    
    
    
}
