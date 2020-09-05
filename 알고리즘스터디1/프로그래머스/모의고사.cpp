// 20분

#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

bool cmp(pair<int,int>&A, pair<int,int>& B){
    
    if(A.second > B.second){
        return true;
    }else if(A.second == B.second){
        return A.first < B.first;
    }else{
        return false; 
    }
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int A[10] = {1, 2, 3, 4, 5};
    int B[10] = {2, 1, 2, 3, 2, 4, 2, 5};
    int C[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int cntA = 0;
    int cntB = 0;
    int cntC = 0; 
    vector<pair<int,int>> v;
    
    for(int i=0; i<answers.size(); i++){
        if(A[i%5] == answers[i]){
            cntA += 1;
        }
        if(B[i%8] == answers[i]){
            cntB += 1;
        }
        if(C[i%10] == answers[i]){
            cntC += 1;
        }
    }
    
    v.push_back(make_pair(1, cntA));
    v.push_back(make_pair(2, cntB));
    v.push_back(make_pair(3, cntC));
 
    sort(v.begin(), v.end(), cmp);
    int most = v[0].second; 
    for(int i=0; i<v.size(); i++){
        if(most == v[i].second){
            answer.push_back(v[i].first);
        }
    }
    
    
    return answer;
}
