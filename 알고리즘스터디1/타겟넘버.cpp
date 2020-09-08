#include <string>
#include <vector>

using namespace std;

int answer = 0; 

void recursive(vector<char>&v, int cnt, int len, vector<int>numbers, int target){
    
    if(cnt == len){
        
        int sum = 0; 
        
        for(int i=0; i<v.size(); i++){
            if(v[i] == '+'){
                sum += numbers[i];
            }else{
                sum -= numbers[i];
            }
        }
        
        if(sum == target){
            answer += 1;
        }
        return; 
    }   
     
    for(int i=0; i<2; i++){
        if(i == 0){
            v.push_back('+');
        }else{
            v.push_back('-');
        }
        
        recursive(v, cnt+1, len, numbers, target);
        v.pop_back();
    }
    
    
    
}

int solution(vector<int> numbers, int target) {

    vector<char>v;
    int len = numbers.size();
    
    recursive(v, 0, len, numbers, target); 
    
    return answer;
}
