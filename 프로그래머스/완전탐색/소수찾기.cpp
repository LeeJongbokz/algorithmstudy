#include <string>
#include <vector>
#include <algorithm>
#include <cstring> 

using namespace std;

vector<int> answer; 
int len;
vector<int> result;
bool check[20];
bool arr[10000000];




void recursive(string &numbers, int cnt){
    
    string str;
    
    for(int i=0;i<result.size(); i++){
        char temp = result[i];
        str += temp;
    }
    
    int zeroLen = 0; 
    
    for(int i=0; i<str.size(); i++){
        if(str[i] == '0'){
            zeroLen += 1;
        }else{
            break;
        }
    }
    
    if(zeroLen != 0){
        str.erase(0, zeroLen);
    }
   
    
    if(!str.empty()){
        int num = stoi(str);
        
        if(arr[num] == true){
            answer.push_back(num);
        }
    }
    
    if(cnt == len){
        return; 
    }
    
    for(int i=0; i<numbers.size(); i++){
        if(check[i] == false){
            check[i] = true;
            result.push_back(numbers[i]);
            recursive(numbers, cnt+1);
            result.pop_back();
            check[i] = false;
        }
    }
    
}

int solution(string numbers) {

    memset(check, false, sizeof(check));
    memset(arr, true, sizeof(arr));

    arr[1] = false; 
    
    for(int i=2; i<=9999999; i++){
        if(arr[i] == false){
            continue;
        }
        
        for(int j=i+i; j<=9999999; j+=i){
            if(arr[j] == true){
                arr[j] = false;
            }
        }
    }
    
    len = numbers.size(); 
    
    recursive(numbers, 0);
    
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    
    return answer.size();
}
