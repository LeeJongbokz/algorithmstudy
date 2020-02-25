#include <iostream>

using namespace std;


int N;
int cnt[10]={0};
int map[3000][3000]={0};


bool isSame(int x, int y, int n){
    
      for(int i=x; i<x+n; i++){
          for(int j=y; j<y+n; j++){
              if(map[x][y] != map[i][j]){
                  return false;
              }
          }
      }
    
      return true; 
    
}




void recursive(int x, int y, int n){
    
    if(isSame(x, y, n)){
        cnt[map[x][y]+1]++;
        return;
    }
    
    int m = n/3;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            recursive(x+i*m, y+j*m, m);
        }
    }
    
        
    
}

int main(){
    
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
    
    recursive(0, 0, N);
    
    
    for(int i=0; i<3; i++){
        cout << cnt[i] << '\n';
    }
    
    
    
    
}
