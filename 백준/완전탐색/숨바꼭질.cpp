#include <iostream>
#include <queue>

using namespace std;

int N,K;

int check[100010] = {0};

bool isInside(int x){
    if(0<=x && x<=100000){
        return true;
    }else{
        return false; 
    }
}


void bfs(int x){
    
    queue<int> q;
    q.push(x);
    
    if(x == K){
        return;
    }
    
    while(!q.empty()){
          
          int x = q.front();
          q.pop();
        
          int t = check[x];
        
          int dy1 = 2*x;
          int dy2 = x+1;
          int dy3 = x-1;
        
          if(isInside(dy1)){
              int num1 = t+1;
              
              if(check[dy1] == 0){
                  check[dy1] = num1;
                  if(dy1 == K){
                      break;
                  }
                  q.push(dy1);
              }      
          }
        
        
          if(isInside(dy2)){
              int num2 = t+1;
              
              if(check[dy2] == 0){
                  check[dy2] = num2;
                  if(dy2 == K){
                      break;
                  }
                  q.push(dy2);
              }    
          }
        
          if(isInside(dy3)){
              int num2 = t+1;
              
              if(check[dy3] == 0){
                  check[dy3] = num2;
                  if(dy3 == K){
                      break;
                  }
                  q.push(dy3);
              }     
          }   
        
    }
    
    
    
}


int main(){
    
    
     cin >> N >> K;
     
     bfs(N);
    
     cout << check[K];
      
    
}

