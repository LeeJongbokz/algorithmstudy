// 이 문제는 진법 변환을 어떻게 할지
// 그리고 앞 자리가 0인 2진수를 어떻게 나타낼지
// 2가지가 핵심 포인트인 문제이다 
// 앞 자리가 0인 2진수를 나타내는 방법도 다르게 접근할 수 있을 듯 하다 

#include <string>
#include <vector>

using namespace std;

vector<int> temp;

// recursive 함수는 10진수를 2진수로 변환한다
// 진법 변환을 잘 이해하고 있어야 한다 
// 그리고 벡터 temp에 이진수 값을 저장한다 
void recursive(int n){
    
    if(n == 0){
        return;
    }
    
    recursive(n/2);
    temp.push_back(n%2);

}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    // 2차원 배열 map1과 map2를 선언한다 
    // 각각은 벡터 arr1과 벡터 arr2를 저장하는데 사용한다 
    int map1[20][20]={0};
    int map2[20][20]={0};
    
    for(int i=0; i<n; i++){
        
        temp.clear();
        // recursive 함수에 arr[i]를 인자로 전달한다
        // recursive 함수는 10진수를 2진수로 변환하기 위한 함수이다 
        recursive(arr1[i]);
        
        // 변수 len에 벡터 temp의 길이를 저장한다  
        int len = temp.size();
        
        // 변수 cnt에 n-len값을 저장한다
        // 이 값은 이진수의 앞 부분의 0의 개수를 의미한다 
        int cnt = n - len;
        
        // 변수 t를 0으로 초기화한다 
        int t = 0;  
        
        for(int j=0; j<n; j++){
            
            // 만약 cnt가 1과 같거나 크다면
            // 이진수의 앞 부분에 0이 더 와야한다는 의미이다
            // 따라서 해당 좌표에는 0을 저장한다
            // 대신 0을 저장한만큼 cnt의 개수는 1만큼 줄여준다 
            if(cnt >= 1){
                map1[i][j] = 0;
                cnt -= 1;
            }
            // 만약 cnt가 0이라면, 이제는 벡터 temp에 저장된 값을 
            // 하나씩 map에 저장하면 된다.
            // 이 때, temp의 인덱스를 변화시키기 위해서 변수 t를 사용한다 
            else{
                map1[i][j] = temp[t];
                t += 1;
            }
        }
    }
    
    // 마찬가지로 벡터 arr2의 값도 
    // 2차원 배열 map2에 저장한다. 
    for(int i=0; i<n; i++){
        
        temp.clear();
        recursive(arr2[i]);
        int len = temp.size();
        int cnt = n - len;
        int t = 0;  
        
        for(int j=0; j<n; j++){
            if(cnt >= 1){
                map2[i][j] = 0;
                cnt -= 1;
            }else{
                map2[i][j] = temp[t];
                t += 1;
            }
        }
    }
    
    // 비밀지도를 해독한다 
    for(int i=0; i<n; i++){
        
        // 문자열 변수 str을 선언한다 
        string str;
        
        for(int j=0; j<n; j++){
            // 만약 map1[i][j], map2[i][j] 둘 중 하나라도 1이라면
            // str에 '#'를 추가한다 
            if(map1[i][j] ==1 || map2[i][j]==1){
                str += '#';
            }
            // 만약 둘 다 0이라면 str에 공백을 추가한다
            else{
                str += ' ';
            }
        }
        // i행에 대해서 완성된 str의 값을 벡터 answer에 저장한다. 
        answer.push_back(str);
    }
    
    // 결과로 벡터 answer를 리턴한다 
    return answer;
}
