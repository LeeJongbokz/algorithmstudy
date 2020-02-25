#include <iostream>

using namespace std;

int N;
string result;
int map[100][100]={0};


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
         result += to_string(map[x][y]);
         return;
     }else{
         result += '(';
     }
    
    
     int m = n/2;
    
    
     for(int i=0; i<2; i++){
         for(int j=0; j<2; j++){
              recursive(x+i*m, y+j*m, m);
         }
     }
    
    
     result += ')';
    
    
}





int main(){
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
     
        for(int j=0; j<N; j++){
           map[i][j] = s[j] - '0';
        }
    }
    
    
    recursive(0, 0, N);
    
    
    cout << result;
    
    
}





