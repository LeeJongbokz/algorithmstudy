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


// isRange()는 해당 좌표가 맵에 속하는지를 검사함 
bool isRange(int x, int y){
    if(1<=x && x<=N && 1<=y && y<=N){
        return true;
    }else{
        return false; 
    }
}


// 1) 가을에 번식을 하기 위해서 작성을 한 함수임
//    map을 벗어나서는 번식을 할 수 없기 때문에,
//    새로 번식을 할 좌표가 맵에 속하는지를 확인하기 위한 isRange()를 만들어줌 
void breed(int x, int y){
    
    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // isRange()에 의해서 map에 속한다고 판단되면,
        // 해당 좌표에 나이가 1인 나무를 추가해줌 
        if(isRange(nx, ny)){
            tree[nx][ny].push_back(1);
        }
    }
    
}



// 1) 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가함.
// 2) 각각의 나무는 나무가 있는 1x1 크기의 양분만 먹을 수 있음 
// 3) 하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹음
// 4) 만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽음 

void spring(){
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            
            // 3)번 조건을 표현함
            // 나이가 어린 나무부터 양분을 먹을 수 있도록, sort함수로 오름차순 정렬을 함 
            sort(tree[i][j].begin(), tree[i][j].end());
            
            int len = tree[i][j].size();
            bool die = false;
            int diePos = 0;
            
            
            for(int k=0; k<len; k++){
                int age = tree[i][j][k];
                
                // 1)번, 2)번 조건을 표현함
                // 나무는 자신의 나이만큼 양분을 먹고, 나이가 1 증가함
                // 땅의 양분은 나이만큼 줄어듬
                if(map[i][j]>=age){
                    map[i][j] -= age;
                    tree[i][j][k] += 1;
                }
                // 4)번 조건을 표현함
                // 만약, 땅에 현재 있는 양분이 자신의 나이보다 부족하면
                // 그 위치 이후의 나무들은 전부 죽게됨 
                // 여기서는 나무가 죽었다는 사실과 나무가 처음 죽은 위치를 저장함
                else{
                    die = true;
                    diePos = k;
                    break;
                }
            }
            
            // 봄에 죽은 나무들은, 여름에 나이를 2로 나눈 값으로 추가되는데
            // tempMap을 만들어서, 여름에 추가할 양분의 값을 저장함
            // 이 때, 전체 제거해야할 갯수(deleteNum)를 구하고, 
            // tree[i][j]의 마지막 원소부터 1/2값을 더해주면서 제거해나가는 방식을 채택함 
            // 여기서 주의할 점은, 제거해야할 갯수(deleteNum)를 정확하게 계산해야 함
            
            // 또한 주의할 점은, 
            // (1) 각각의 죽은 나무마다 2로 나눈 값의 소수점을 버리는 것과 
            // (2) 전체 죽은 나무를 2로 나눈 값의 합의 소수점을 버리는 것을 구분해야 함 
            // 예를 들어, 죽은 나무 2개가 5,5라고 하면 
            // (1)의 경우는 2.5-> 2 , 2.5-> 2 즉, 2+2 = 4가 됨
            // (2)의 경우는 2.5+2.5 = 5가 됨 
            // 문제의 케이스는 (1)이었고, 이에 따라 그대로 잘 구현했음
            // 다만, 만약 (2)였다면 total과 (tree[i][j].back()/2)를 double로 선언해야 함 
            // 이러한 디테일한 조건에 유의할 필요가 있음 
            
            // 또한, tree[i][j]에서 나무를 제거하는 것이 필수적인 이유는
            // 나중에 살아 있는 나무의 수만 구하는 것이 이 문제의 목적이기 때문임
            // 따라서 죽은 나무들은 제거를 해줘야 함 
            
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



// 1) 여름에는 봄에 죽은 나무가 양분으로 변함.
//    이를 구현하기 위해 spring()에서 맵의 각 위치에 더해야 할 값을 미리 계산해 놓음


void summer(){
    
    
    // 1)번 조건을 표현함. spring()에서 계산한 더해야 하는 양분 값을 그대로 더해줌 
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            map[i][j] += tempMap[i][j];
        }
    }
    
    // tempMap을 반드시 초기화해줘야 함
    // 왜냐하면 매년마다 더해야 하는 양분 값을 새로 계산해야 하기 때문임
    memset(tempMap, 0, sizeof(tempMap));
}


// 1) 가을에는 나무가 번식함. 단, 번식하는 나무는 나이가 5의 배수이어야 하며,
//    인접한 8개의 칸에 나이가 1인 나무가 생김       

void fall(){
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int len = tree[i][j].size();
            
            // 맵의 하나의 좌표(tree[i][j])에는 여러 개의 나무가 있을 수 있음
            // 따라서 이렇게 여러 개의 나무에 대해 
            // 각각이 번식 가능한지 검사하고자 함 
            for(int k=0; k<len; k++){
                int age = tree[i][j][k];
                
                // 1)번 조건을 표현함
                // 즉, 나이가 5의 배수인 나무만 번식할 수 있음
                // 번식에 대해서는 따로 함수를 만들어줌 
                if(age % 5 == 0){
                    breed(i,j);
                }
            }
        }
    }
}

// 1) 겨울에는 땅에 양분을 추가함
//    추가해야 하는 양분은 미리 행렬에 저장해 놓음

void winter(){
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            // 1)번 조건을 구현함
            // 즉, 추가해야 하는 양분을 map에 추가해줌 
            map[i][j] += A[i][j];
        }
    }
}







int main(){
    
    memset(map, 0, sizeof(map));
    memset(tempMap, 0, sizeof(tempMap));
    
    // N, M, K 초기값을 입력함
    
    cin >> N >> M >> K;
    
    
    // 가장 처음에 양분은 모든 칸에 5만큼 들어 있음을 나타냄
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            map[i][j] = 5;
        }
    }
    
    // 각 칸에 추가되는 양분의 양을 입력함
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> A[i][j]; 
        }
    }
    
    // 나무의 위치와 나무의 나이를 2차원 벡터에 입력함 
    
    for(int i=1; i<=M; i++){
        int x,y,z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }
    
    // K년만큼 지난 후를 나타내기 위해, 반복문으로 K번 반복함
    
    while(K--){
        
        // 봄, 여름, 가을, 겨울을 한 번씩 실행함
        
        spring();
        summer();
        fall();
        winter();
    }
    
    int alive = 0;
    
    // K년이 지난 후 살아 남은 나무의 개수를 구함
    // 이를 위해서는 각 좌표마다 살아 있는 나무의 수를 더해줌 
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            alive += tree[i][j].size(); 
        }
    }
    
    
    // 전체 살아 있는 나무의 수를 결과로 출력함
    cout << alive; 
    
    
    
}
