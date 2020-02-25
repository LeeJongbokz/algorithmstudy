#include <iostream>

using namespace std;

int main(){
    
    char map[60][60];
    char chess1[10][10];
    char chess2[10][10];
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if((i+j) % 2 == 0){
                chess1[i][j] = 'B';
                chess2[i][j] = 'W';
            }else{
                chess1[i][j] = 'W';
                chess2[i][j] = 'B';
            }
        }
    }
    
    int N, M;
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    
    int minCnt = 9999999;
    int cnt = 0; 
    
    
    for(int i=0; i<N-7; i++){
        for(int j=0; j<M-7; j++){
            
            cnt = 0; 
         
            for(int k=i; k<i+8; k++){
                for(int l=j; l<j+8; l++){
                    if(map[k][l] != chess1[k-i][l-j]){
                        cnt += 1;
                    }
                }
            }
            
            if(minCnt > cnt){
                minCnt = cnt;
            }   
        }   
    }
    
    for(int i=0; i<N-7; i++){
        for(int j=0; j<M-7; j++){
            
            cnt = 0; 
         
            for(int k=i; k<i+8; k++){
                for(int l=j; l<j+8; l++){
                    if(map[k][l] != chess2[k-i][l-j]){
                        cnt += 1;
                    }
                }
            }
            
            if(minCnt > cnt){
                minCnt = cnt;
            }   
        } 
       
    }
          
             
    cout << minCnt;
    
    
 
    
    
}
