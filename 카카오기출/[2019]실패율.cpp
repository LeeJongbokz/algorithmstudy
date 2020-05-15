// 이 문제의 핵심은 어떻게 실패율을 정의하고
// 실패율을 데이터로서 관리할 것인지이다
// 나는 2차원 벡터를 만들어서, stage와 그 stage의 실패율을 저장했고,
// 이후에 그 벡터를 정렬하는 방식을 사용했다. 
// 특히, 2차원 벡터를 정렬하는 것은 매우 자주 사용되므로
// 잘 알아둬야 한다. 

#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

// cmp 함수는 두번째 값이 큰 순으로 정렬하고,
// 두 번째 값이 같으면, 첫번째 값이 작은 순으로 정렬한다. 
// 이 코드는 매우 유용하므로, 잘 숙지해놓는 것이 좋다 
bool cmp(pair<int, double> a, pair<int,double> b){
    
    if(a.second > b.second){
        return true;
    }else if(a.second == b.second){
        if(a.first < b.first){
            return true;
        }else{
            return false;
        }
    }else{
        return false; 
    }
    
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    // 결과를 저장할 벡터 result를 선언한다  
    vector<pair<int, double>> result;
    
    // 변수 len에 stages의 길이를 저장한다
    int len = stages.size();
    // 변수 total에 len을 저장한다 
    int total = len;
    
    // for문으로 N개의 스테이지를 순회한다  
    for(int i=1; i<=N; i++){
        int cnt = 0; 
        
        // 변수 cnt에 현재 스테이지의 인원을 저장한다 
        // for문을 통해서 stages 배열에 있는 값들을 반복 접근하면서
        // 해당 stage에 있는 사용자의 수를 계산한다 
        for(int j=0; j<len; j++){
            if(i == stages[j]){
                cnt += 1;
            }
        }
        
        // 변수 failureRate를 정의한다
        // 이 변수는 실패율을 저장하는 기능을 한다 
        double failureRate;
        
        // 만약 변수 total이 0이라면 failureRate는 0으로 정의한다
        // 왜냐하면 total이 0이면 실패율 자체를 정의할 수 없기 때문이다
        // total이 0인 경우와 아닌 경우를 분리하는 것이 매우 중요하다 
        // 이 부분을 잘 고려하지 않으면 런타임 에러를 경험할 수 있다 
        if(total == 0){
            failureRate = 0; 
        }else{
        // total이 0이 아닌 경우는 실패율을 계산한다
        // 실패율의 정의는 스테이지에 도달했으나 클리어하지 못한 플레이어의 수를
        // 스테이지에 도달한 플레이어의 수로 나눠주는 것이다. 
            failureRate = (double)cnt / (double)total;
        }
        
        // result 벡터에 스테이지 단계 i와 실패율 failureRate를 저장한다
        // 이 두 개를 저장하는 이유는 나중에 실패율이 높은 스테이지부터
        // 내림차순으로 배열을 리턴해야 하기 때문이다 
        result.push_back(make_pair(i, failureRate));
        
        // total에서 cnt를 제거해준다
        // 이것을 제거해주는 이유는 total에서 cnt만큼은 다음 스테이지에 도달할 수 없기 때문에
        // cnt만큼을 제거해주는 것이다. 
        total -= cnt;
    }
    
    // result 벡터를 cmp함수를 사용하여 정렬한다. 
    sort(result.begin(), result.end(), cmp);
    
    // resultlen 변수에 result의 크기를 저장한다 
    int resultlen = result.size();
    
    // for문을 resultlen 크기만큼 순회하면서
    // result[i].first의 값을 
    // 벡터 answer에 넣어준다
    for(int i=0; i<resultlen; i++){
        answer.push_back(result[i].first);
    }
    
    // 벡터 answer를 결과로서 리턴한다 
    return answer;
}
