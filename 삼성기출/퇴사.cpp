#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int N;
vector<int> T;
vector<int> P;
vector<int> picked;
int maxSum = -987654321;

void score(){
    
    int sum = 0; 
    
    // 변수 lastPick에 벡터 picked의 맨 마지막 원소를 담는다 
    int lastpick = picked.back();
    
    // 만약 가장 마지막에 뽑은 것+그 뽑은 값의 소요 날짜가 N을 초과한다면
    // 마지막에 선택된 값은 제외해줘야 한다. 
    if(lastpick + T[lastpick] -1 > N){
        for(int i=0; i<picked.size()-1; i++){
            sum += P[picked[i]];
        }
    }else{
        for(int i=0; i<picked.size(); i++){
            sum += P[picked[i]];
        }
    }
    
    // maxSum과 sum을 비교해서 maxSum을 업데이트 한다. 
    maxSum = max(maxSum, sum);
    
}


void pick(){
    
    // 변수 willPick에 초기값 1을 넣어준다. 
    int willPick = 1;
    
    // 벡터 picked가 empty가 아니라면, 
    // 변수 willPick에 picked.back()+T[picked.back()]을 넣어준다 
    // 이 의미는 이전에 선택한 값+소요된 날짜만큼 부터 
    // 값을 선택할 수 있다는 의미이다 
    if(!picked.empty()){
        willPick = picked.back() + T[picked.back()];
    }
    
    // 만약 변수 willPick이 N을 초과한다면 
    // score() 함수에 진입한다 
    // 이렇게 하는 이유는 더 이상 값을 선택할 수 없기 때문이다 
    if(willPick > N){
        score();
        return;
    }
    
    
    // for문을 willPick부터 N까지 순회한다 
    for(int i=willPick; i<=N; i++){
        
        //벡터 picked에 선택한 값을 넣어준다. 
        picked.push_back(i);
        // 재귀함수 pick()에 진입한다
        pick();
        // 
        picked.pop_back();
    }
    
    
}






int main(){
    
    cin >> N;
    
    // 벡터 T와 벡터 P를 index 1부터 써주기 위하여
    // -1을 각각 넣어준다. 
    T.push_back(-1);
    P.push_back(-1);
    
    for(int i=1; i<=N; i++){
        
        // t는 상담에 소요되는 일수
        // p는 상담 시 받게 되는 금액을 의미한다 
        int t,p;
        cin >> t >> p;
        
        // 벡터 T에 t를, 벡터 P에 p를 넣어준다. 
        T.push_back(t);
        P.push_back(p);
    }
    
    // pick() 함수를 실행한다. 
    pick();
    
    cout << maxSum;
    
    
}



