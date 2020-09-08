#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 99999999;

int minCnt = INF;
bool check[60];

int isDiff(string a, string b){
    
    int diff = 0; 
    
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]){
            diff += 1;
        }
    }
    return diff; 
}

void recursive(int cnt, string current, string target, vector<string>& words){
    
    if(minCnt < cnt){
        return;
    }
    
    if(current == target){
        minCnt = min(minCnt, cnt);
        return; 
    }
    
    for(int i=0; i<words.size(); i++){
        if(check[i] == false && isDiff(current,words[i]) == 1){
            check[i] = true;
            recursive(cnt+1, words[i], target, words);
            check[i] = false; 
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    int len = words.size();
    bool isExist = false;
    
    for(int i=0; i<len; i++){
        if(target == words[i]){
            isExist = true;
            break;
        }
    }
    
    if(isExist == true){
        recursive(0, begin, target, words);
        answer = minCnt;
    }else{
        answer = 0;
    }
    
    return answer;
}
