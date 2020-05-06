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
    
    int lastpick = picked.back();
    
    if(lastpick + T[lastpick] -1 > N){
        for(int i=0; i<picked.size()-1; i++){
            sum += P[picked[i]];
        }
    }else{
        for(int i=0; i<picked.size(); i++){
            sum += P[picked[i]];
        }
    }
    
    maxSum = max(maxSum, sum);
    
}


void pick(){
    
    int willPick = 1;
    
    if(!picked.empty()){
        willPick = picked.back() + T[picked.back()];
    }
    
    if(willPick > N){
        score();
        return;
    }
    
    
    
    for(int i=willPick; i<=N; i++){
        picked.push_back(i);
        pick();
        picked.pop_back();
    }
    
    
}






int main(){
    
    cin >> N;
    
    T.push_back(-1);
    P.push_back(-1);
    
    for(int i=1; i<=N; i++){
        int t,p;
        cin >> t >> p;
        
        T.push_back(t);
        P.push_back(p);
    }
    
    pick();
    
    cout << maxSum;
    
    
}



