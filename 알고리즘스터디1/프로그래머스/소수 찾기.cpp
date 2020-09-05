#include <string>
#include <vector>
#include <cstring> 
#include <set>

using namespace std;

set<int> s; 
bool arr[10000010];
bool check[10];

void isSosu(){
    
    memset(arr, true, sizeof(arr));
    arr[0] = false;
    arr[1] = false; 
    
    for(int i=2; i<=10000010; i++){
        if(arr[i] == false){
            continue;    
        }
        
        for(int j=i+i; j<=10000010; j+=i){
               if(arr[j] == true){
                   arr[j] = false; 
               }    
        }
    }
       
}

void recursive(string& str, string& numbers){
   
    if(str.size() >= 1){
        string temp = str;
        int num = stoi(temp);
        if(arr[num] == true){
            s.insert(num);
        }
    }
    
    if(str.size() == numbers.size()){
        return; 
    }
    
    for(int i=0; i<numbers.size(); i++){
        if(check[i] == false){
            check[i] = true;
            str += numbers[i];
            recursive(str, numbers);
            str.pop_back();
            check[i] = false;
        }
    }
    
}

int solution(string numbers) {
    
    memset(check, false, sizeof(check));
   
    
    int answer = 0;
    string str = "";
    int cnt = 0;
    int len = numbers.size(); 
 
    isSosu();
    recursive(str, numbers);
 
    answer = s.size(); 
    
    return answer;
}
