#include <iostream>

using namespace std;

int a[500][500] = {0};
int cnt[10]={0};
int N;

bool isSame(int x, int y, int n){
    
      for(int i=x; i<x+n; i++){
          for(int j=y; j<y+n; j++){
              if(a[x][y] != a[i][j]){
                  return false;
              }
          }
      }
    
      return true;

}




void recursive(int x, int y, int n){
    
    if(isSame(x, y, n)){
       cnt[a[x][y]]++;
       return;
    }
    
    int m = n/2;
    
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            recursive(x+i*m, y+j*m, m);
        }
    }
    
 
}




int main(){
  
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> a[i][j];
        }
    }
    
    recursive(0, 0, N);
    
    for(int i=0; i<2; i++){
        cout << cnt[i] << '\n';
    }
    
    
    
}



