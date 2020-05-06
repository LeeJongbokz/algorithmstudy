#include <iostream>
#include <cstring> 

using namespace std;

int N, M, x, y, K;
int map[30][30];
int cmd[1010];
int diceNum[6];
int diceBefore[6];

bool mapMove(int num){
    
      int temp_x;
      int temp_y;
    
      temp_x = x;
      temp_y = y; 
    
      switch(num){
            
        case 1:
            temp_x;
            temp_y++;
            break;
        case 2:
            temp_x;
            temp_y--;
            break;
        case 3:
            temp_x--;
            temp_y;
            break;
        case 4:
            temp_x++;
            temp_y;
            break;  
    }
    
    if(0<=temp_x && temp_x<N && 0<=temp_y && temp_y<M){
        x = temp_x;
        y = temp_y;
        return true;
    }else{
        return false;
    }
}


void diceMove(int num){
    
    for(int i=0; i<6; i++){
        diceBefore[i] = diceNum[i];
    }
    
    switch(num){
            
        case 1:
            diceNum[5] = diceBefore[3];
            diceNum[3] = diceBefore[2];
            diceNum[2] = diceBefore[1];
            diceNum[1] = diceBefore[5];
            break;
        case 2:
            diceNum[1] = diceBefore[2];
            diceNum[2] = diceBefore[3];
            diceNum[3] = diceBefore[5];
            diceNum[5] = diceBefore[1];
            break;
        case 3:
            diceNum[0] = diceBefore[2];
            diceNum[2] = diceBefore[4];
            diceNum[4] = diceBefore[5];
            diceNum[5] = diceBefore[0];
            break;
        case 4:
            diceNum[4] = diceBefore[2];
            diceNum[5] = diceBefore[4];
            diceNum[0] = diceBefore[5];
            diceNum[2] = diceBefore[0];
            break;  
    }
    
    
}

void changeDice(int x, int y){
     
     if(map[x][y] == 0){
         map[x][y] = diceNum[5];
     }else{
         diceNum[5] = map[x][y];
         map[x][y] = 0; 
     }
}




int main(){
    
    
    cin >> N >> M >> x >> y >> K;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    
    for(int i=1; i<=K; i++){
        cin >> cmd[i];
    }
    
    memset(diceNum, 0, sizeof(diceNum));
    
    for(int i=1; i<=K; i++){
        
        if(mapMove(cmd[i])){
           diceMove(cmd[i]);
           changeDice(x, y); 
           cout << diceNum[2] << '\n';
        }
        
    }
     
    
    
}
